#ifndef TEMPSCREENPRESENTER_HPP
#define TEMPSCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class TempScreenView;

class TempScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    TempScreenPresenter(TempScreenView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~TempScreenPresenter() {};

private:
    TempScreenPresenter();

    TempScreenView& view;
};

#endif // TEMPSCREENPRESENTER_HPP
