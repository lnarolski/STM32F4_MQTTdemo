#include <gui/tempscreen_screen/TempScreenView.hpp>
#include "ds18b20.h"

touchgfx::TextAreaWithOneWildcard* windowTempText;
touchgfx::BoxProgress* windowTempBar;

extern TIM_HandleTypeDef htim4;
uint8_t ROM_tmp[8];
extern Ds18b20Sensor_t ds18b20[1];

static bool isVisiblePage = false;
static bool isInited = false;

float temp;

void ClearText(touchgfx::Unicode::UnicodeChar* array, size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		array[i] = '\0';
	}
}

void TempScreenView::handleTickEvent()
{
	if (isVisiblePage && isInited)
	{
		DS18B20_ReadAll();
		for(uint8_t i = 0; i < DS18B20_Quantity(); i++)
		{
			if(DS18B20_GetTemperature(i, &ds18b20[i].Temperature))
			{
				DS18B20_GetROM(i, ROM_tmp);
				
				ClearText(TempTextBuffer, TEMPTEXT_SIZE);
				
				Unicode::snprintfFloat(TempTextBuffer, TEMPTEXT_SIZE, "%.2f", ds18b20[i].Temperature);
				
				windowTempText->resizeToCurrentText();
				windowTempText->invalidate();
				windowTempBar->setValue((int) ds18b20[i].Temperature);
			}
		}
		DS18B20_StartAll();
	}
}

TempScreenView::TempScreenView()
{
	windowTempText = &this->TempText;
	windowTempBar = &this->TempBar;
	
	if (!isInited)
	{
		DS18B20_Init(DS18B20_Resolution_12bits);
		DS18B20_StartAll();
		
		isInited = true;
	}
}

void TempScreenView::setupScreen()
{
    TempScreenViewBase::setupScreen();
	
	isVisiblePage = true;
}

void TempScreenView::tearDownScreen()
{
    TempScreenViewBase::tearDownScreen();
	
	isVisiblePage = false;
}
