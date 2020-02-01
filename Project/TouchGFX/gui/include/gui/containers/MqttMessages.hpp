#ifndef MQTTMESSAGES_HPP
#define MQTTMESSAGES_HPP

#include <gui_generated/containers/MqttMessagesBase.hpp>

class MqttMessages : public MqttMessagesBase
{
public:
    MqttMessages();
    virtual ~MqttMessages() {}

    virtual void initialize();
protected:
};

#endif // MQTTMESSAGES_HPP
