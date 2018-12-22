#include "Message.hpp"
#include <functional>
#include <queue>
#include <vector>

#ifndef MESSAGE_BUS_H
#define MESSAGE_BUS_H

class MessageBus
{
public:
    MessageBus() {};
    ~MessageBus() {};

    void addReceiver(std::function<void (Message)> messageReceiver);

    void sendMessage(Message message);

    void notify();

private:
    std::vector<std::function<void (Message)>> receivers;
    std::queue<Message> messages;
};

#endif
