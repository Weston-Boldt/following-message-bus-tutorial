#include <string>

#ifndef MESSAGE_H
#define MESSAGE_H

class Message
{
public:
    Message(const std ::string event) {
        messageEvent = event;
    }

    std::string getEvent(); 

private:
    std::string messageEvent;
};

#endif
