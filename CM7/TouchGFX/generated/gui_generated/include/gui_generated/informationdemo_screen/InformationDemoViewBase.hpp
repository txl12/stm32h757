/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef INFORMATIONDEMOVIEWBASE_HPP
#define INFORMATIONDEMOVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/informationdemo_screen/InformationDemoPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/containers/buttons/Buttons.hpp>

class InformationDemoViewBase : public touchgfx::View<InformationDemoPresenter>
{
public:
    InformationDemoViewBase();
    virtual ~InformationDemoViewBase();
    virtual void setupScreen();
    virtual void handleKeyEvent(uint8_t key);

    /*
     * Custom Actions
     */
    virtual void goToSelectingMenu();
    virtual void goToCookingMenu();

    /*
     * Virtual Action Handlers
     */
    virtual void pressCenterKeyFunction()
    {
        // Override and implement this function in InformationDemo
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Image informationImage;
    touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  screenClickListener;

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<InformationDemoViewBase, const touchgfx::AbstractButtonContainer&> flexButtonCallback;

    /*
     * Callback Handler Declarations
     */
    void flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src);

};

#endif // INFORMATIONDEMOVIEWBASE_HPP
