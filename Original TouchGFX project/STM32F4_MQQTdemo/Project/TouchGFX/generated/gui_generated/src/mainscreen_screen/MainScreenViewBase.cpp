/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/mainscreen_screen/MainScreenViewBase.hpp>
#include <touchgfx/Color.hpp>
#include "BitmapDatabase.hpp"
#include <texts/TextKeysAndLanguages.hpp>

MainScreenViewBase::MainScreenViewBase() :
    buttonCallback(this, &MainScreenViewBase::buttonCallbackHandler),
    updateItemCallback(this, &MainScreenViewBase::updateItemCallbackHandler)
{

    box1.setPosition(0, 0, 240, 320);
    box1.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));

    boxWithBorder1.setPosition(0, 260, 240, 60);
    boxWithBorder1.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    boxWithBorder1.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    boxWithBorder1.setBorderSize(5);

    PreviousPageButton.setXY(0, 260);
    PreviousPageButton.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_ICON_BUTTON_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_ICON_BUTTON_PRESSED_ID));
    PreviousPageButton.setLabelText(touchgfx::TypedText(T_SINGLEUSEID2));
    PreviousPageButton.setLabelColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    PreviousPageButton.setLabelColorPressed(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    PreviousPageButton.setAction(buttonCallback);

    NextPageButton.setXY(180, 260);
    NextPageButton.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_ICON_BUTTON_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_ICON_BUTTON_PRESSED_ID));
    NextPageButton.setLabelText(touchgfx::TypedText(T_SINGLEUSEID3));
    NextPageButton.setLabelColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    NextPageButton.setLabelColorPressed(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    NextPageButton.setAction(buttonCallback);

    scrollList1.setPosition(0, 43, 240, 217);
    scrollList1.setHorizontal(false);
    scrollList1.setCircular(false);
    scrollList1.setEasingEquation(touchgfx::EasingEquations::backEaseOut);
    scrollList1.setSwipeAcceleration(10);
    scrollList1.setDragAcceleration(10);
    scrollList1.setNumberOfItems(10);
    scrollList1.setPadding(0, 0);
    scrollList1.setSnapping(false);
    scrollList1.setDrawableSize(24, 0);
    scrollList1.setDrawables(scrollList1ListItems, updateItemCallback);

    textArea1.setXY(38, 8);
    textArea1.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    textArea1.setLinespacing(0);
    textArea1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID23));

    add(box1);
    add(boxWithBorder1);
    add(PreviousPageButton);
    add(NextPageButton);
    add(scrollList1);
    add(textArea1);
}

void MainScreenViewBase::setupScreen()
{
    scrollList1.initialize();
    for (int i = 0; i < scrollList1ListItems.getNumberOfDrawables(); i++)
    {
        scrollList1ListItems[i].initialize();
    }
}

void MainScreenViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &PreviousPageButton)
    {
        //PerviousPageInteraction
        //When PreviousPageButton clicked change screen to RGBScreen
        //Go to RGBScreen with no screen transition
        application().gotoRGBScreenScreenNoTransition();
    }
    else if (&src == &NextPageButton)
    {
        //NextPageInteraction
        //When NextPageButton clicked change screen to TempScreen
        //Go to TempScreen with no screen transition
        application().gotoTempScreenScreenNoTransition();
    }
}

void MainScreenViewBase::updateItemCallbackHandler(touchgfx::DrawableListItemsInterface* items, int16_t containerIndex, int16_t itemIndex)
{
    if (items == &scrollList1ListItems)
    {
        touchgfx::Drawable* d = items->getDrawable(containerIndex);
        MqttMessages* cc = (MqttMessages*)d;
        scrollList1UpdateItem(*cc, itemIndex);
    }
}
