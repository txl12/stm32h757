/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef INFORMATIONVIEWBASE_HPP
#define INFORMATIONVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/information_screen/InformationPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/containers/buttons/Buttons.hpp>

class InformationViewBase : public touchgfx::View<InformationPresenter>
{
public:
    InformationViewBase();
    virtual ~InformationViewBase();
    virtual void setupScreen();
    virtual void handleKeyEvent(uint8_t key);

    /*
     * Custom Actions
     */
    virtual void goToScreenInfo2();

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
    touchgfx::Callback<InformationViewBase, const touchgfx::AbstractButtonContainer&> flexButtonCallback;

    /*
     * Callback Handler Declarations
     */
    void flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src);

};

#endif // INFORMATIONVIEWBASE_HPP
