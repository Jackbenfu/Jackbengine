//
//  webSocket.h
//  Jackbengine
//
//  Created by Damien Bendejacq on 18/02/2016.
//  Copyright (c) 2016 Damien Bendejacq. All rights reserved.
//

#ifndef __WEB_SOCKET_H__
#define __WEB_SOCKET_H__

#include <map>
#include <string>
#include <vector>

#include "easywsclient/easywsclient.hpp"

#include "common.h"
#include "webSocketEvent.h"

NS_BEGIN_JKB
NS_STD

template<typename TListener>
class WebSocket
{
public:
    explicit WebSocket(const TListener& listener);
    ~WebSocket();

    using Deserializer = const WebSocketEvent*(*)(const vector<byte>& message);
    using Callback = void(TListener::*)(const WebSocketEvent *message);

    bool open(const string& url);
    void close();

    void poll();

    void setCallback(byte type, Callback callback);

protected:
    void send(const vector<byte>& message) const;

    void setDeserializer(byte type, Deserializer deserializer);

    const TListener& m_listener;
    map<byte, Deserializer> m_deserializers;
    map<byte, Callback> m_callbacks;

private:
    easywsclient::WebSocket::pointer m_socket = nullptr;
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
            auto messageType = message[0];

            auto itd = m_deserializers.find(messageType);
            if (m_deserializers.end() == itd)
            {
                printf("ERROR Invalid network message [%u]\n", messageType);
                return;
            }

            auto event = (itd->second)(message);

            auto itc = m_callbacks.find(messageType);
            if (m_callbacks.end() == itc)
            {
                printf("ERROR No callback found for message %u\n", messageType);
                return;
            }

            (const_cast<TListener&>(m_listener).*itc->second)(event);
        });
    }
    else
    {
        close();
    }
}

template<typename TListener>
void WebSocket<TListener>::send(const vector<byte>& message) const
{
    if (nullptr != m_socket)
    {
        m_socket->sendBinary(message);
    }
}

template<typename TListener>
void WebSocket<TListener>::setCallback(byte type, Callback callback)
{
    m_callbacks[type] = callback;
}

template<typename TListener>
void WebSocket<TListener>::setDeserializer(byte type, Deserializer deserializer)
{
    m_deserializers[type] = deserializer;
}

NS_END_JKB

#endif // __WEB_SOCKET_H__
