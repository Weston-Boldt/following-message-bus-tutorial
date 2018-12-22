#include "MessageBus.hpp"
#include "Message.hpp"

#include <iostream>
#include <functional>

#ifndef BUS_NODE_H
#define BUS_NODE_H

class BusNode
{
public:
    BusNode (MessageBus *messageBus);

    virtual void update();

protected:
    MessageBus *messageBus;

    std::function<void (Message)> getNotifyFunc();

    void send(Message message);

    virtual void onNotify(Message message);
};

#endif
