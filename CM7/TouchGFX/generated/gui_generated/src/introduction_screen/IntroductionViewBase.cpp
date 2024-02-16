/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/introduction_screen/IntroductionViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <images/BitmapDatabase.hpp>

IntroductionViewBase::IntroductionViewBase()
{
    __background.setPosition(0, 0, 800, 480);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    background.setPosition(0, 0, 800, 480);
    background.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    add(background);

    headline.setPosition(0, 73, 800, 298);
    headline.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    headline.setLinespacing(0);
    headline.setTypedText(touchgfx::TypedText(T_INTRODUCTION));
    add(headline);

    arrow_left.setXY(6, 224);
    arrow_left.setBitmap(touchgfx::Bitmap(BITMAP_ARROW_LEFT_ID));
    add(arrow_left);

    arrow_right.setXY(776, 224);
    arrow_right.setBitmap(touchgfx::Bitmap(BITMAP_ARROW_RIGHT_ID));
    add(arrow_right);
}

IntroductionViewBase::~IntroductionViewBase()
{

}

void IntroductionViewBase::setupScreen()
{

}

void IntroductionViewBase::handleKeyEvent(uint8_t key)
{
    if(0 == key)
    {
        //Interaction1
        //When hardware button 0 clicked change screen to Demo
        //Go to Demo with screen transition towards West
        application().gotoDemoScreenSlideTransitionWest();
    
    }
}
