//
// webSocket.h
// jackbengine
//
// Created by Damien Bendejacq on 18/02/2016.
// Copyright © 2016 Damien Bendejacq. All rights reserved.
//

#ifndef __WEB_SOCKET_H__
#define __WEB_SOCKET_H__

#include <map>
#include <string>
#include <vector>

#include "easywsclient/easywsclient.hpp"

#include "common.h"
#include "webSocketEvent.h"
#include "systemSocketMessageType.h"

NS_BEGIN_JKB
NS_STD

union MessageTypeUnion
{
    short type;
    byte bytes[2];
};

union MessageIdUnion
{
    int id;
    byte bytes[4];
};

template<typename TListener>
class WebSocket
{
public:
    explicit WebSocket(const TListener& listener);
    virtual ~WebSocket();

    using Deserializer = const WebSocketEvent*(*)(const byte *data, int size);
    using Callback = void(TListener::*)(const WebSocketEvent *message);

    bool open(const string& url);
    void close();

    void poll();

    void setCallback(short type, Callback callback);

protected:
    void send(short type, vector<byte>& data) const;

    void setDeserializer(short type, Deserializer deserializer, bool acknowledge);

    const TListener& m_listener;

    map<short, Deserializer> m_deserializers;
    map<short, bool> m_acknowledges;
    map<short, Callback> m_callbacks;

private:
    easywsclient::WebSocket::pointer m_socket = nullptr;

    const int MESSAGE_HEADER_SIZE = 6;

    bool parseMessage(const vector<byte>& message, short *type, int *id);
    void acknowledgeMessage(int id);
};

template<typename TListener>
WebSocket<TListener>::WebSocket(const TListener& listener)
    : m_listener(listener)
{
}

template<typename TListener>
WebSocket<TListener>::~WebSocket()
{
    close();

    DELETE_SAFE(m_socket);
}

template<typename TListener>
bool WebSocket<TListener>::open(const string& url)
{
    if (nullptr == m_socket)
    {
        m_socket = easywsclient::WebSocket::from_url(url);

        return nullptr != m_socket;
    }

    return false;
}

template<typename TListener>
void WebSocket<TListener>::close()
{
    if (nullptr != m_socket)
    {
        m_socket->close();
    }
}

template<typename TListener>
void WebSocket<TListener>::poll()
{
    if (easywsclient::WebSocket::CLOSED != m_socket->getReadyState())
    {
        m_socket->poll();

        m_socket->dispatchBinary([this](const vector<byte>& message)
        {
            short messageType;
            int messageId;

            if (!parseMessage(message, &messageType, &messageId))
            {
                LOG_ERROR("Invalid network message, does not contain type or id");
                return;
            }

            auto itd = m_deserializers.find(messageType);
            if (m_deserializers.end() == itd)
            {
                LOG_ERROR("No deserializer found for network message [%u]", messageType)
                return;
            }

            auto messageData = message.data() + MESSAGE_HEADER_SIZE;
            auto messageSize = message.size() - MESSAGE_HEADER_SIZE;

            auto event = (itd->second)(messageData, messageSize);

            auto itc = m_callbacks.find(messageType);
            if (m_callbacks.end() == itc)
            {
                LOG_ERROR("No callback found for message [%u]", messageType)
                return;
            }

            (const_cast<TListener&>(m_listener).*itc->second)(event);

            auto ita = m_acknowledges.find(messageType);
            if (m_acknowledges.end() != ita && ita->second)
            {
                acknowledgeMessage(messageId);
            }
        });
    }
    else
    {
        close();
    }
}

template<typename TListener>
void WebSocket<TListener>::send(short type, vector<byte>& payload) const
{
    if (nullptr != m_socket)
    {
        union MessageTypeUnion typeUnion;
        typeUnion.type = htons(type);
        payload.insert(payload.begin(), typeUnion.bytes[1]);
        payload.insert(payload.begin(), typeUnion.bytes[0]);

        m_socket->sendBinary(payload);
    }
}

template<typename TListener>
void WebSocket<TListener>::setCallback(short type, Callback callback)
{
    m_callbacks[type] = callback;
}

template<typename TListener>
void WebSocket<TListener>::setDeserializer(short type, Deserializer deserializer, bool acknowledge)
{
    m_deserializers[type] = deserializer;
    m_acknowledges[type] = acknowledge;
}

template<typename TListener>
bool WebSocket<TListener>::parseMessage(const vector<byte> &message, short *type, int *id)
{
    if (MESSAGE_HEADER_SIZE > message.size())
    {
        return false;
    }

    union MessageTypeUnion typeUnion;
    typeUnion.bytes[0] = message[0];
    typeUnion.bytes[1] = message[1];
    *type = ntohs(typeUnion.type);

    union MessageIdUnion idUnion;
    idUnion.bytes[0] = message[2];
    idUnion.bytes[1] = message[3];
    idUnion.bytes[2] = message[4];
    idUnion.bytes[3] = message[5];
    *id = ntohl(idUnion.id);

    printf("%6i ", *id);

    return true;
}

template<typename TListener>
void WebSocket<TListener>::acknowledgeMessage(int id)
{
    vector<byte> data;

    union MessageIdUnion idUnion;
    idUnion.id = htonl(id);
    data.push_back(idUnion.bytes[0]);
    data.push_back(idUnion.bytes[1]);
    data.push_back(idUnion.bytes[2]);
    data.push_back(idUnion.bytes[3]);

    printf("%6i ACKNOWLEDGE\n", id);

    send(SystemSocketMessageType::ACKNOWLEDGE, data);
}

NS_END_JKB

#endif // __WEB_SOCKET_H__
