#ifndef LIGHTSCREENVIEW_HPP
#define LIGHTSCREENVIEW_HPP

#include <gui_generated/lightscreen_screen/LightScreenViewBase.hpp>
#include <gui/lightscreen_screen/LightScreenPresenter.hpp>

class LightScreenView : public LightScreenViewBase
{
public:
    LightScreenView();
    virtual ~LightScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // LIGHTSCREENVIEW_HPP
