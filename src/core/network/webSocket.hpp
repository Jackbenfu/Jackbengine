//
// webSocket.hpp
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

#include "common.hpp"
#include "webSocketEvent.hpp"
#include "systemSocketMessageType.hpp"

namespace Jackbengine {

template<typename TListener>
class WebSocket
{
public:
    explicit WebSocket(const TListener& listener);
    virtual ~WebSocket();

    using Deserializer = const WebSocketEvent*(*)(const byte *data, int size);
    using Callback = void(TListener::*)(const WebSocketEvent *message);

    bool open(const std::string& url);
    void close();

    void poll();

    void setCallback(short type, Callback callback);

protected:
    void send(short type, std::vector<byte>& data) const;

    void setDeserializer(short type, Deserializer deserializer, bool acknowledge);

    const TListener& m_listener;

    std::map<short, Deserializer> m_deserializers;
    std::map<short, bool> m_acknowledges;
    std::map<short, Callback> m_callbacks;

private:
    easywsclient::WebSocket::pointer m_socket = nullptr;

    const int MESSAGE_HEADER_SIZE = 6;

    bool parseMessage(const std::vector<byte>& message, short *type, int *id);
    void acknowledgeMessage(int id);
};

#include "webSocket.tpp"

} // namespace Jackbengine

#endif // __WEB_SOCKET_H__
