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
		textBuffer[Unicode::strlen(textBuffer) - 2] = 0; // Receive from ESP32 \r\n at the end of the message so I have to delete '\r' character
}

void MqttMessages::SetText(touchgfx::Unicode::UnicodeChar* t)
{
		Unicode::snprintf(textBuffer, TEXT_SIZE, "%s", t);
}

touchgfx::Unicode::UnicodeChar* MqttMessages::GetText()
{
		return textBuffer;
}
