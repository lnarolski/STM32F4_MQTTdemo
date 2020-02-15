#ifndef TEMPSCREENVIEW_HPP
#define TEMPSCREENVIEW_HPP

#include <gui_generated/tempscreen_screen/TempScreenViewBase.hpp>
#include <gui/tempscreen_screen/TempScreenPresenter.hpp>
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_tim.h"

class TempScreenView : public TempScreenViewBase
{
public:
    TempScreenView();
    virtual ~TempScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent();
protected:
};

#endif // TEMPSCREENVIEW_HPP
