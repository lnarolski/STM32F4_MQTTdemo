#ifndef RGBSCREENVIEW_HPP
#define RGBSCREENVIEW_HPP

#include <gui_generated/rgbscreen_screen/RGBScreenViewBase.hpp>
#include <gui/rgbscreen_screen/RGBScreenPresenter.hpp>

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
