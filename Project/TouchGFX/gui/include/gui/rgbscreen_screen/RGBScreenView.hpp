#ifndef RGBSCREENVIEW_HPP
#define RGBSCREENVIEW_HPP

#define Green_PWM_Pin GPIO_PIN_5
#define Green_PWM_GPIO_Port GPIOA
#define Blue_PWM_Pin GPIO_PIN_6
#define Blue_PWM_GPIO_Port GPIOA
#define Red_PWM_Pin GPIO_PIN_9
#define Red_PWM_GPIO_Port GPIOE
#define Temp_Output_Pin GPIO_PIN_7
#define Temp_Output_GPIO_Port GPIOA

#include <gui_generated/rgbscreen_screen/RGBScreenViewBase.hpp>
#include <gui/rgbscreen_screen/RGBScreenPresenter.hpp>
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_tim.h"

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

class RGBScreenView : public RGBScreenViewBase
{
public:
    RGBScreenView();
    virtual ~RGBScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void SetRGB(int value);
    virtual void SetR(int value);
    virtual void SetG(int value);
    virtual void SetB(int value);
protected:
};

#endif // RGBSCREENVIEW_HPP
