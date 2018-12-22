#include "BusNode.hpp"

class ComponentA : public BusNode
{

public:
    ComponentA(MessageBus* messageBus) : BusNode(messageBus) {}

private:
    void onNotify(Message message)
    {
        std::cout << "I received: " << message.getEvent() << std::endl;
    }
};

class ComponentB : public BusNode
{

public:
    ComponentB(MessageBus* messageBus) : BusNode(messageBus) {}

    void update()
    {
        Message greeting("hi");
        send(greeting);
    }

private:
    void onNotify(Message message)
    {
        std::cout << "I received: " << message.getEvent() << std::endl;
    }
};

int main()
{
    MessageBus messageBus;

    ComponentA compA(&messageBus);
    ComponentB compB(&messageBus);

    for (int ctr = 0; ctr < 50; ctr++) {
        compA.update();
        compB.update();
        messageBus.notify();
    }

    return 0;
}
