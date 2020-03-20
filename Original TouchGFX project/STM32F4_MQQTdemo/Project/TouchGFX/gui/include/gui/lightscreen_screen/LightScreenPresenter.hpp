#ifndef LIGHTSCREENPRESENTER_HPP
#define LIGHTSCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class LightScreenView;

class LightScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    LightScreenPresenter(LightScreenView& v);

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

    virtual ~LightScreenPresenter() {};

private:
    LightScreenPresenter();

    LightScreenView& view;
};

#endif // LIGHTSCREENPRESENTER_HPP
