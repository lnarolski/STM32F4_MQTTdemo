#ifndef MAINSCREENVIEW_HPP
#define MAINSCREENVIEW_HPP

#define Green_PWM_Pin GPIO_PIN_5
#define Green_PWM_GPIO_Port GPIOA
#define Blue_PWM_Pin GPIO_PIN_6
#define Blue_PWM_GPIO_Port GPIOA
#define Red_PWM_Pin GPIO_PIN_9
#define Red_PWM_GPIO_Port GPIOE
#define Temp_Output_Pin GPIO_PIN_7
#define Temp_Output_GPIO_Port GPIOA

#include <gui_generated/mainscreen_screen/MainScreenViewBase.hpp>
#include <gui/mainscreen_screen/MainScreenPresenter.hpp>
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_tim.h"

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

class MainScreenView : public MainScreenViewBase
{
public:
    MainScreenView();
    virtual ~MainScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
		void handleTickEvent();
protected:
};

#endif // MAINSCREENVIEW_HPP
