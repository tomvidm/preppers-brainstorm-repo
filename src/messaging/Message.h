#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

namespace messaging {
    typedef std::string String;

    class Message
    {
    public:
        String decodeMessage() const;
        String encodeMessage(const String& plaintext) const;
    private:
        String messageString_;
    };
}

#endif