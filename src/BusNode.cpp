#include "BusNode.hpp"

BusNode::BusNode(MessageBus *messageBus)
{
    this->messageBus = messageBus;
    this->messageBus->addReceiver(this->getNotifyFunc());
}

void BusNode::update(void) {
}

std::function<void (Message)> BusNode::getNotifyFunc()
{
    auto messageListener = [=](Message message) -> void {
        this->onNotify(message);
    };
    return messageListener;
}

void BusNode::send(Message message)
{
    messageBus->sendMessage(message);
}

void BusNode::onNotify(Message message)
{
    std::cout << "you gotta implement onNotify()." << std::endl;
}
