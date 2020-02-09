#ifndef LIGHTSCREENVIEW_HPP
#define LIGHTSCREENVIEW_HPP

#define Light_ADC_Pin GPIO_PIN_5
#define Light_ADC_GPIO_Port GPIOC

#include <gui_generated/lightscreen_screen/LightScreenViewBase.hpp>
#include <gui/lightscreen_screen/LightScreenPresenter.hpp>
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_adc.h"

void HAL_ADC_MspInit(ADC_HandleTypeDef* hadc);

class LightScreenView : public LightScreenViewBase
{
public:
    LightScreenView();
    virtual ~LightScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent();
protected:
};

#endif // LIGHTSCREENVIEW_HPP
