// 4.13.0 dither_algorithm=2 alpha_dither=yes layout_rotation=0 opaque_image_format=RGB565 non_opaque_image_format=ARGB8888 section=ExtFlashSection extra_section=ExtFlashSection generate_png=no 0x44ef14c2
// Generated by imageconverter. Please, do not edit!

#include <BitmapDatabase.hpp>
#include <touchgfx/Bitmap.hpp>
#include <touchgfx/lcd/LCD.hpp>
#include <platform/driver/lcd/LCD16bpp.hpp>

extern const unsigned char _blue_buttons_round_edge_icon_button[]; // BITMAP_BLUE_BUTTONS_ROUND_EDGE_ICON_BUTTON_ID = 0, Size: 60x60 pixels
extern const unsigned char _blue_buttons_round_edge_icon_button_pressed[]; // BITMAP_BLUE_BUTTONS_ROUND_EDGE_ICON_BUTTON_PRESSED_ID = 1, Size: 60x60 pixels
extern const unsigned char _blue_progressindicators_bg_medium_progress_indicator_bg_square_0_degrees[]; // BITMAP_BLUE_PROGRESSINDICATORS_BG_MEDIUM_PROGRESS_INDICATOR_BG_SQUARE_0_DEGREES_ID = 2, Size: 184x20 pixels
extern const unsigned char _blue_slider_horizontal_small_indicators_slider_horizontal_small_round_knob[]; // BITMAP_BLUE_SLIDER_HORIZONTAL_SMALL_INDICATORS_SLIDER_HORIZONTAL_SMALL_ROUND_KNOB_ID = 3, Size: 54x34 pixels
extern const unsigned char _blue_slider_horizontal_small_slider_horizontal_small_round_back[]; // BITMAP_BLUE_SLIDER_HORIZONTAL_SMALL_SLIDER_HORIZONTAL_SMALL_ROUND_BACK_ID = 4, Size: 172x20 pixels

const touchgfx::Bitmap::BitmapData bitmap_database[] =
{
    { _blue_buttons_round_edge_icon_button, 0, 60, 60, 7, 6, 46, (uint8_t)(touchgfx::Bitmap::ARGB8888) >> 3, 46, (uint8_t)(touchgfx::Bitmap::ARGB8888) & 0x7 },
    { _blue_buttons_round_edge_icon_button_pressed, 0, 60, 60, 7, 6, 46, (uint8_t)(touchgfx::Bitmap::ARGB8888) >> 3, 46, (uint8_t)(touchgfx::Bitmap::ARGB8888) & 0x7 },
    { _blue_progressindicators_bg_medium_progress_indicator_bg_square_0_degrees, 0, 184, 20, 0, 0, 184, (uint8_t)(touchgfx::Bitmap::RGB565) >> 3, 20, (uint8_t)(touchgfx::Bitmap::RGB565) & 0x7 },
    { _blue_slider_horizontal_small_indicators_slider_horizontal_small_round_knob, 0, 54, 34, 8, 4, 38, (uint8_t)(touchgfx::Bitmap::ARGB8888) >> 3, 24, (uint8_t)(touchgfx::Bitmap::ARGB8888) & 0x7 },
    { _blue_slider_horizontal_small_slider_horizontal_small_round_back, 0, 172, 20, 10, 0, 152, (uint8_t)(touchgfx::Bitmap::ARGB8888) >> 3, 20, (uint8_t)(touchgfx::Bitmap::ARGB8888) & 0x7 }
};

namespace BitmapDatabase
{
const touchgfx::Bitmap::BitmapData* getInstance()
{
    return bitmap_database;
}

uint16_t getInstanceSize()
{
    return (uint16_t)(sizeof(bitmap_database) / sizeof(touchgfx::Bitmap::BitmapData));
}
}
