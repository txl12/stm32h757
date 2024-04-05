#include <gui/screen1_screen/Screen1View.hpp>

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
	textArea1Buffer[0] ='a';
	textArea1Buffer[1] = 0;
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}
