//
// webSocket.tpp
// jackbengine
//
// Created by Damien Bendejacq on 30/06/2017.
// Copyright © 2017 Damien Bendejacq. All rights reserved.
//

#ifndef __WEBSOCKET_TPP__
#define __WEBSOCKET_TPP__

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
WebSocket<TListener>::WebSocket(const TListener& listener)
    : m_listener(listener)
{
    // Nothing
}

template<typename TListener>
WebSocket<TListener>::~WebSocket()
{
    close();

    DELETE_SAFE(m_socket);
}

template<typename TListener>
bool WebSocket<TListener>::open(const std::string& url)
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
    if (easywsclient::WebSocket::CLOSED == m_socket->getReadyState())
    {
        close();
        return;
    }

    m_socket->poll();

    m_socket->dispatchBinary(
        [this](const std::vector<byte>& message)
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
                LOG_ERROR("No deserializer found for network message [%u]", messageType);
                return;
            }

            auto messageData = message.data() + MESSAGE_HEADER_SIZE;
            auto messageSize = message.size() - MESSAGE_HEADER_SIZE;

            auto event = (itd->second)(messageData, messageSize);

            auto itc = m_callbacks.find(messageType);
            if (m_callbacks.end() == itc)
            {
                LOG_ERROR("No callback found for message [%u]", messageType);
                return;
            }

            (const_cast<TListener&>(m_listener).*itc->second)(event);

            auto ita = m_acknowledges.find(messageType);
            if (m_acknowledges.end() != ita && ita->second)
            {
                acknowledgeMessage(messageId);
            }
        }
    );
}

template<typename TListener>
void WebSocket<TListener>::send(short type, std::vector<byte>& payload) const
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
bool WebSocket<TListener>::parseMessage(const std::vector<byte> &message, short *type, int *id)
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
    std::vector<byte> data;

    union MessageIdUnion idUnion;
    idUnion.id = htonl(id);
    data.push_back(idUnion.bytes[0]);
    data.push_back(idUnion.bytes[1]);
    data.push_back(idUnion.bytes[2]);
    data.push_back(idUnion.bytes[3]);

    printf("%6i ACKNOWLEDGE\n", id);

    send(SystemSocketMessageType::ACKNOWLEDGE, data);
}

#endif // __WEBSOCKET_TPP__
