/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef TEMPSCREENVIEWBASE_HPP
#define TEMPSCREENVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/tempscreen_screen/TempScreenPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/BoxWithBorder.hpp>
#include <touchgfx/widgets/ButtonWithLabel.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/containers/progress_indicators/BoxProgress.hpp>

class TempScreenViewBase : public touchgfx::View<TempScreenPresenter>
{
public:
    TempScreenViewBase();
    virtual ~TempScreenViewBase() {}
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
    touchgfx::TextAreaWithOneWildcard TempText;
    touchgfx::BoxProgress TempBar;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TEMPTEXT_SIZE = 10;
    touchgfx::Unicode::UnicodeChar TempTextBuffer[TEMPTEXT_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<TempScreenViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // TEMPSCREENVIEWBASE_HPP
