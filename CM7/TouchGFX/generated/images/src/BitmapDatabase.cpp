// 4.23.0 0xc3c380db
// Generated by imageconverter. Please, do not edit!

#include <images/BitmapDatabase.hpp>
#include <touchgfx/Bitmap.hpp>

extern const unsigned char image_alternate_theme_images_backgrounds_1024x600_puzzle[]; // BITMAP_ALTERNATE_THEME_IMAGES_BACKGROUNDS_1024X600_PUZZLE_ID = 0, Size: 1024x600 pixels
extern const unsigned char image_keyboard[]; // BITMAP_KEYBOARD_ID = 1, Size: 1024x300 pixels

const touchgfx::Bitmap::BitmapData bitmap_database[] = {
    { image_alternate_theme_images_backgrounds_1024x600_puzzle, 0, 1024, 600, 0, 0, 1024, ((uint8_t)touchgfx::Bitmap::RGB565) >> 3, 600, ((uint8_t)touchgfx::Bitmap::RGB565) & 0x7 },
    { image_keyboard, 0, 1024, 300, 0, 0, 1024, ((uint8_t)touchgfx::Bitmap::RGB565) >> 3, 300, ((uint8_t)touchgfx::Bitmap::RGB565) & 0x7 }
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
} // namespace BitmapDatabase
