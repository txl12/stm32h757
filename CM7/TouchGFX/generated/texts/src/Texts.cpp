/* DO NOT EDIT THIS FILE */
/* This file is autogenerated by the text-database code generator */

#include <stdarg.h>
#include <touchgfx/TextProvider.hpp>
#include <touchgfx/Texts.hpp>
#include <touchgfx/TypedText.hpp>
#include <touchgfx/Unicode.hpp>
#include <touchgfx/hal/HAL.hpp>
#include <touchgfx/lcd/LCD.hpp>
#include <texts/TypedTextDatabase.hpp>

uint16_t touchgfx::Font::getStringWidth(const touchgfx::Unicode::UnicodeChar* text, ...) const
{
    va_list pArg;
    va_start(pArg, text);
    uint16_t width = getStringWidthLTR(TEXT_DIRECTION_LTR, text, pArg);
    va_end(pArg);
    return width;
}

uint16_t touchgfx::Font::getStringWidth(touchgfx::TextDirection textDirection, const touchgfx::Unicode::UnicodeChar* text, ...) const
{
    va_list pArg;
    va_start(pArg, text);
    uint16_t width = getStringWidthLTR(textDirection, text, pArg);
    va_end(pArg);
    return width;
}

touchgfx::Unicode::UnicodeChar touchgfx::TextProvider::getNextLigature(TextDirection direction)
{
    if (fontGsubTable && nextCharacters.peekChar())
    {
        substituteGlyphs();
        if (nextCharacters.peekChar(1) == 0x093F) // Hindi I-matra
        {
            nextCharacters.replaceAt1(nextCharacters.peekChar());
            nextCharacters.replaceAt0(0x093F);
        }
    }
    return getNextChar();
}

void touchgfx::TextProvider::initializeInternal()
{
    fillInputBuffer();
}

void touchgfx::LCD::drawString(touchgfx::Rect widgetArea, const touchgfx::Rect& invalidatedArea, const touchgfx::LCD::StringVisuals& stringVisuals, const touchgfx::Unicode::UnicodeChar* format, ...)
{
    va_list pArg;
    va_start(pArg, format);
    drawStringLTR(widgetArea, invalidatedArea, stringVisuals, format, pArg);
    va_end(pArg);
}

// Default TypedTextDatabase
extern const touchgfx::TypedText::TypedTextData* const typedTextDatabaseArray[];

TEXT_LOCATION_FLASH_PRAGMA
KEEP extern const touchgfx::Unicode::UnicodeChar texts_all_languages[] TEXT_LOCATION_FLASH_ATTRIBUTE = {
    0x50, 0x6c, 0x61, 0x79, 0x20, 0x61, 0x20, 0x73, 0x69, 0x6d, 0x70, 0x6c, 0x65, 0x20, 0x70, 0x75, 0x7a, 0x7a, 0x6c, 0x65, 0x20, 0x67, 0x61, 0x6d, 0x65, 0xa, 0x53, 0x68, 0x6f, 0x77, 0x73, 0x20, 0x68, 0x69, 0x67, 0x68, 0x20, 0x71, 0x75, 0x61, 0x6c, 0x69, 0x74, 0x79, 0x20, 0x67, 0x72, 0x61, 0x70, 0x68, 0x69, 0x63, 0x73, 0x20, 0x61, 0x6e, 0x64, 0x20, 0x73, 0x6d, 0x6f, 0x6f, 0x74, 0x68, 0x20, 0x61, 0x6e, 0x69, 0x6d, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x73, 0x0, // @0 "Play a simple puzzle game\nShows high quality graphics and smooth animations"
    0x50, 0x6c, 0x61, 0x79, 0x20, 0x74, 0x68, 0x65, 0x20, 0x42, 0x69, 0x72, 0x64, 0x20, 0x45, 0x61, 0x74, 0x20, 0x43, 0x6f, 0x69, 0x6e, 0x20, 0x67, 0x61, 0x6d, 0x65, 0xa, 0x53, 0x68, 0x6f, 0x77, 0x73, 0x20, 0x67, 0x72, 0x61, 0x70, 0x68, 0x69, 0x63, 0x73, 0x20, 0x70, 0x65, 0x72, 0x66, 0x6f, 0x72, 0x6d, 0x61, 0x6e, 0x63, 0x65, 0x20, 0x6f, 0x66, 0x20, 0x54, 0x6f, 0x75, 0x63, 0x68, 0x47, 0x46, 0x58, 0x0, // @76 "Play the Bird Eat Coin game\nShows graphics performance of TouchGFX"
    0x53, 0x69, 0x6d, 0x75, 0x6c, 0x61, 0x74, 0x65, 0x73, 0x20, 0x69, 0x6e, 0x70, 0x75, 0x74, 0x20, 0x61, 0x6e, 0x64, 0x20, 0x6f, 0x75, 0x74, 0x70, 0x75, 0x74, 0x20, 0x66, 0x72, 0x6f, 0x6d, 0x20, 0xa, 0x65, 0x78, 0x74, 0x65, 0x72, 0x6e, 0x61, 0x6c, 0x20, 0x68, 0x61, 0x72, 0x64, 0x77, 0x61, 0x72, 0x65, 0x20, 0x63, 0x6f, 0x6d, 0x70, 0x6f, 0x6e, 0x65, 0x6e, 0x74, 0x73, 0x0, // @143 "Simulates input and output from \nexternal hardware components"
    0x43, 0x6f, 0x6e, 0x74, 0x72, 0x6f, 0x6c, 0x20, 0x79, 0x6f, 0x75, 0x72, 0x20, 0x68, 0x6f, 0x6d, 0x65, 0xa, 0x53, 0x68, 0x6f, 0x77, 0x73, 0x20, 0x76, 0x69, 0x76, 0x69, 0x64, 0x20, 0x67, 0x72, 0x61, 0x70, 0x68, 0x73, 0x20, 0x61, 0x6e, 0x64, 0x20, 0x61, 0x63, 0x63, 0x65, 0x73, 0x73, 0x20, 0x63, 0x6f, 0x6e, 0x74, 0x72, 0x6f, 0x6c, 0x0, // @205 "Control your home\nShows vivid graphs and access control"
    0x53, 0x68, 0x6f, 0x77, 0x20, 0x77, 0x69, 0x64, 0x67, 0x65, 0x74, 0x73, 0x20, 0x66, 0x6f, 0x72, 0x20, 0x61, 0x64, 0x6a, 0x75, 0x73, 0x74, 0x69, 0x6e, 0x67, 0x20, 0x74, 0x69, 0x6d, 0x65, 0x20, 0x61, 0x6e, 0x64, 0x20, 0x64, 0x61, 0x74, 0x65, 0x20, 0xa, 0x0, // @261 "Show widgets for adjusting time and date \n"
    0x48, 0x61, 0x72, 0x64, 0x77, 0x61, 0x72, 0x65, 0x20, 0x67, 0x72, 0x61, 0x70, 0x68, 0x69, 0x63, 0x73, 0x20, 0x61, 0x63, 0x63, 0x65, 0x6c, 0x65, 0x72, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x20, 0x62, 0x79, 0x20, 0x52, 0x65, 0x6e, 0x65, 0x73, 0x61, 0x73, 0x0, // @304 "Hardware graphics acceleration by Renesas"
    0x48, 0x61, 0x72, 0x64, 0x77, 0x61, 0x72, 0x65, 0x20, 0x67, 0x72, 0x61, 0x70, 0x68, 0x69, 0x63, 0x73, 0x20, 0x61, 0x63, 0x63, 0x65, 0x6c, 0x65, 0x72, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x20, 0x62, 0x79, 0x20, 0x53, 0x54, 0x0, // @346 "Hardware graphics acceleration by ST"
    0x4c, 0x6f, 0x67, 0x69, 0x6e, 0x20, 0x66, 0x61, 0x69, 0x6c, 0x65, 0x64, 0x3a, 0x20, 0x50, 0x61, 0x74, 0x74, 0x65, 0x72, 0x6e, 0x20, 0x77, 0x61, 0x73, 0x20, 0x69, 0x6e, 0x63, 0x6f, 0x72, 0x72, 0x65, 0x63, 0x74, 0x21, 0x0, // @383 "Login failed: Pattern was incorrect!"
    0x4c, 0x6f, 0x67, 0x69, 0x6e, 0x20, 0x66, 0x61, 0x69, 0x6c, 0x65, 0x64, 0x3a, 0x20, 0x50, 0x61, 0x74, 0x74, 0x65, 0x72, 0x6e, 0x20, 0x77, 0x61, 0x73, 0x20, 0x74, 0x6f, 0x6f, 0x20, 0x73, 0x68, 0x6f, 0x72, 0x74, 0x21, 0x0, // @420 "Login failed: Pattern was too short!"
    0x45, 0x6e, 0x61, 0x62, 0x6c, 0x65, 0x2f, 0x64, 0x69, 0x73, 0x61, 0x62, 0x6c, 0x65, 0x20, 0x32, 0x44, 0x20, 0x44, 0x72, 0x61, 0x77, 0x69, 0x6e, 0x67, 0x20, 0x45, 0x6e, 0x67, 0x69, 0x6e, 0x65, 0x0, // @457 "Enable/disable 2D Drawing Engine"
    0x45, 0x6e, 0x61, 0x62, 0x6c, 0x65, 0x2f, 0x64, 0x69, 0x73, 0x61, 0x62, 0x6c, 0x65, 0x20, 0x43, 0x68, 0x72, 0x6f, 0x6d, 0x2d, 0x41, 0x52, 0x54, 0x0, // @490 "Enable/disable Chrom-ART"
    0x50, 0x4f, 0x54, 0x45, 0x4e, 0x54, 0x49, 0x4f, 0x4d, 0x45, 0x54, 0x45, 0x52, 0x20, 0x4c, 0x45, 0x56, 0x45, 0x4c, 0x0, // @515 "POTENTIOMETER LEVEL"
    0x45, 0x78, 0x74, 0x65, 0x72, 0x6e, 0x61, 0x6c, 0x20, 0x48, 0x61, 0x72, 0x64, 0x77, 0x61, 0x72, 0x65, 0x0, // @535 "External Hardware"
    0x53, 0x43, 0x52, 0x45, 0x45, 0x4e, 0x20, 0x42, 0x52, 0x49, 0x47, 0x48, 0x54, 0x4e, 0x45, 0x53, 0x53, 0x0, // @553 "SCREEN BRIGHTNESS"
    0x54, 0x69, 0x6d, 0x65, 0x20, 0x61, 0x6e, 0x64, 0x20, 0x43, 0x61, 0x6c, 0x65, 0x6e, 0x64, 0x61, 0x72, 0x0, // @571 "Time and Calendar"
    0x4c, 0x6f, 0x67, 0x69, 0x6e, 0x20, 0x73, 0x75, 0x63, 0x63, 0x65, 0x65, 0x64, 0x65, 0x64, 0x21, 0x0, // @589 "Login succeeded!"
    0x53, 0x45, 0x43, 0x55, 0x52, 0x49, 0x54, 0x59, 0x20, 0x43, 0x4f, 0x4e, 0x54, 0x52, 0x4f, 0x4c, 0x0, // @606 "SECURITY CONTROL"
    0x54, 0x49, 0x4d, 0x45, 0x20, 0x26, 0x20, 0x43, 0x41, 0x4c, 0x45, 0x4e, 0x44, 0x41, 0x52, 0x0, // @623 "TIME & CALENDAR"
    0x42, 0x4c, 0x49, 0x4e, 0x44, 0x53, 0x20, 0x43, 0x4f, 0x4e, 0x54, 0x52, 0x4f, 0x4c, 0x0, // @639 "BLINDS CONTROL"
    0x48, 0x45, 0x52, 0x45, 0x27, 0x53, 0x20, 0x41, 0x20, 0x48, 0x49, 0x4e, 0x54, 0x21, 0x0, // @654 "HERE'S A HINT!"
    0x2b, 0x2, 0x0, // @669 "+<>"
    0x42, 0x69, 0x72, 0x64, 0x20, 0x45, 0x61, 0x74, 0x20, 0x43, 0x6f, 0x69, 0x6e, 0x0, // @672 "Bird Eat Coin"
    0x4c, 0x49, 0x47, 0x48, 0x54, 0x20, 0x43, 0x4f, 0x4e, 0x54, 0x52, 0x4f, 0x4c, 0x0, // @686 "LIGHT CONTROL"
    0x43, 0x48, 0x4f, 0x4f, 0x53, 0x45, 0x20, 0x43, 0x4c, 0x4f, 0x43, 0x4b, 0x0, // @700 "CHOOSE CLOCK"
    0x48, 0x4f, 0x4d, 0x45, 0x20, 0x43, 0x4f, 0x4e, 0x54, 0x52, 0x4f, 0x4c, 0x0, // @713 "HOME CONTROL"
    0x48, 0x6f, 0x6d, 0x65, 0x20, 0x43, 0x6f, 0x6e, 0x74, 0x72, 0x6f, 0x6c, 0x0, // @726 "Home Control"
    0x32, 0x30, 0x34, 0x38, 0x20, 0x50, 0x75, 0x7a, 0x7a, 0x6c, 0x65, 0x0, // @739 "2048 Puzzle"
    0x4d, 0x43, 0x55, 0x20, 0x6c, 0x6f, 0x61, 0x64, 0x3a, 0x20, 0x0, // @751 "MCU load: "
    0x53, 0x54, 0x41, 0x54, 0x49, 0x53, 0x54, 0x49, 0x43, 0x53, 0x0, // @762 "STATISTICS"
    0x2, 0x25, 0x0, // @773 "<>%"
    0x53, 0x45, 0x54, 0x20, 0x44, 0x41, 0x54, 0x45, 0x0, // @776 "SET DATE"
    0x53, 0x45, 0x54, 0x20, 0x54, 0x49, 0x4d, 0x45, 0x0, // @785 "SET TIME"
    0x4c, 0x4f, 0x47, 0x49, 0x4e, 0x0, // @794 "LOGIN"
    0x53, 0x43, 0x4f, 0x52, 0x45, 0x0 // @800 "SCORE"
};

TEXT_LOCATION_FLASH_PRAGMA
KEEP extern const uint32_t indicesGbr[] TEXT_LOCATION_FLASH_ATTRIBUTE;

// Array holding dynamically installed languages
struct TranslationHeader
{
    uint32_t offset_to_texts;
    uint32_t offset_to_indices;
    uint32_t offset_to_typedtext;
};
static const TranslationHeader* languagesArray[1] = { 0 };

// Compiled and linked in languages
static const uint32_t* const staticLanguageIndices[] = {
    indicesGbr
};

touchgfx::LanguageId touchgfx::Texts::currentLanguage = static_cast<touchgfx::LanguageId>(0);
static const touchgfx::Unicode::UnicodeChar* currentLanguagePtr = 0;
static const uint32_t* currentLanguageIndices = 0;

void touchgfx::Texts::setLanguage(touchgfx::LanguageId id)
{
    const touchgfx::TypedText::TypedTextData* currentLanguageTypedText = 0;
    if (id < 1)
    {
        if (languagesArray[id] != 0)
        {
            // Dynamic translation is added
            const TranslationHeader* translation = languagesArray[id];
            currentLanguagePtr = (const touchgfx::Unicode::UnicodeChar*)(((const uint8_t*)translation) + translation->offset_to_texts);
            currentLanguageIndices = (const uint32_t*)(((const uint8_t*)translation) + translation->offset_to_indices);
            currentLanguageTypedText = (const touchgfx::TypedText::TypedTextData*)(((const uint8_t*)translation) + translation->offset_to_typedtext);
        }
        else
        {
            // Compiled and linked in languages
            currentLanguagePtr = texts_all_languages;
            currentLanguageIndices = staticLanguageIndices[id];
            currentLanguageTypedText = typedTextDatabaseArray[id];
        }
    }

    if (currentLanguageTypedText)
    {
        currentLanguage = id;
        touchgfx::TypedText::registerTypedTextDatabase(currentLanguageTypedText,
                                                       TypedTextDatabase::getFonts(), TypedTextDatabase::getInstanceSize());
    }
}

void touchgfx::Texts::setTranslation(touchgfx::LanguageId id, const void* translation)
{
    languagesArray[id] = (const TranslationHeader*)translation;
}

const touchgfx::Unicode::UnicodeChar* touchgfx::Texts::getText(TypedTextId id) const
{
    return &currentLanguagePtr[currentLanguageIndices[id]];
}
