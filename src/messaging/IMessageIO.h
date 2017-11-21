#ifndef IMESSAGEIO_H
#define IMESSAGEIO_H

#include "messaging/Message.h"

namespace messaging {
    typedef std::string StringId;

    class IMessageIO
    {
    public:
        virtual void sendMessage(const StringId& recipient, const Message& msg);
        virtual void receiveMessage(const Message& msg);
    };
}

#endif