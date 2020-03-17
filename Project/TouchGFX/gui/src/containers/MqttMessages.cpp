#include <gui/containers/MqttMessages.hpp>

MqttMessages::MqttMessages()
{

}

void MqttMessages::initialize()
{
    MqttMessagesBase::initialize();
}

void MqttMessages::SetText(char* t)
{
		Unicode::snprintf(textBuffer, TEXT_SIZE, t);
}

void MqttMessages::SetText(touchgfx::Unicode::UnicodeChar* t)
{
		Unicode::snprintf(textBuffer, TEXT_SIZE, "%s", t);
}

touchgfx::Unicode::UnicodeChar* MqttMessages::GetText()
{
		return textBuffer;
}