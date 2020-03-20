#ifndef TEMPSCREENVIEW_HPP
#define TEMPSCREENVIEW_HPP

#include <gui_generated/tempscreen_screen/TempScreenViewBase.hpp>
#include <gui/tempscreen_screen/TempScreenPresenter.hpp>

class TempScreenView : public TempScreenViewBase
{
public:
    TempScreenView();
    virtual ~TempScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // TEMPSCREENVIEW_HPP
