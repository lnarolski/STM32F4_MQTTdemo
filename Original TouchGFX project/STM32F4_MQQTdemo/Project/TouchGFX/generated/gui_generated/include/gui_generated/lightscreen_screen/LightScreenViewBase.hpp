/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef LIGHTSCREENVIEWBASE_HPP
#define LIGHTSCREENVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/lightscreen_screen/LightScreenPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/BoxWithBorder.hpp>
#include <touchgfx/widgets/ButtonWithLabel.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/containers/progress_indicators/BoxProgress.hpp>

class LightScreenViewBase : public touchgfx::View<LightScreenPresenter>
{
public:
    LightScreenViewBase();
    virtual ~LightScreenViewBase() {}
    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box box1;
    touchgfx::BoxWithBorder boxWithBorder1;
    touchgfx::ButtonWithLabel PreviousPageButton;
    touchgfx::ButtonWithLabel NextPageButton;
    touchgfx::TextArea textArea1;
    touchgfx::TextAreaWithOneWildcard LightText;
    touchgfx::BoxProgress LightBar;

    /*
     * Wildcard Buffers
     */
    static const uint16_t LIGHTTEXT_SIZE = 10;
    touchgfx::Unicode::UnicodeChar LightTextBuffer[LIGHTTEXT_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<LightScreenViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // LIGHTSCREENVIEWBASE_HPP
