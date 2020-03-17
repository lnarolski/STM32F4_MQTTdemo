#include <gui/rgbscreen_screen/RGBScreenView.hpp>

extern uint32_t RedDuty;
extern uint32_t GreenDuty;
extern uint32_t BlueDuty;

RGBScreenView::RGBScreenView()
{
		static bool inited = false;
	
		if (!inited)
		{
			
			inited = true;
		}
}

void RGBScreenView::setupScreen()
{
		RedSlider.setValue(RedDuty);
		BlueSlider.setValue(BlueDuty);
		GreenSlider.setValue(GreenDuty);
	
    RGBScreenViewBase::setupScreen();
}

void RGBScreenView::tearDownScreen()
{
    RGBScreenViewBase::tearDownScreen();
}

void RGBScreenView::SetRGB(int value)
{

}

void RGBScreenView::SetR(int value)
{
		RedDuty = value;
}

void RGBScreenView::SetG(int value)
{
		GreenDuty = value;
}

void RGBScreenView::SetB(int value)
{
		BlueDuty = value;
}
