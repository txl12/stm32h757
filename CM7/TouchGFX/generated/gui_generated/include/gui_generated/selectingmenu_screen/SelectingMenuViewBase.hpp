/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SELECTINGMENUVIEWBASE_HPP
#define SELECTINGMENUVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/selectingmenu_screen/SelectingMenuPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/EasingEquations.hpp>
#include <touchgfx/mixins/FadeAnimator.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/mixins/MoveAnimator.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/containers/buttons/Buttons.hpp>

class SelectingMenuViewBase : public touchgfx::View<SelectingMenuPresenter>
{
public:
    SelectingMenuViewBase();
    virtual ~SelectingMenuViewBase();
    virtual void setupScreen();
    virtual void handleKeyEvent(uint8_t key);

    /*
     * Custom Actions
     */
    virtual void goToCookingScreen();
    virtual void goToInformationScreen();
    virtual void goToSettingScreen();

    /*
     * Virtual Action Handlers
     */
    virtual void hardwareDownKeyAction()
    {
        // Override and implement this function in SelectingMenu
    }
    virtual void hardwareUpKeyAction()
    {
        // Override and implement this function in SelectingMenu
    }
    virtual void hardwareRightKeyAction()
    {
        // Override and implement this function in SelectingMenu
    }
    virtual void hardwareLeftKeyAction()
    {
        // Override and implement this function in SelectingMenu
    }
    virtual void pressRightButtonAction()
    {
        // Override and implement this function in SelectingMenu
    }
    virtual void pressLeftButtonAction()
    {
        // Override and implement this function in SelectingMenu
    }
    virtual void pressSettingButtonAction()
    {
        // Override and implement this function in SelectingMenu
    }
    virtual void pressInfoButtonAction()
    {
        // Override and implement this function in SelectingMenu
    }
    virtual void hardwareCenterKeyAction()
    {
        // Override and implement this function in SelectingMenu
    }
    virtual void hideRemainingElements()
    {
        // Override and implement this function in SelectingMenu
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Image background;
    touchgfx::FadeAnimator< touchgfx::TextAreaWithTwoWildcards > clockTextArea;
    touchgfx::FadeAnimator< touchgfx::Image > selectedImage;
    touchgfx::MoveAnimator< touchgfx::Container > start_option_background;
    touchgfx::Box startBackground;
    touchgfx::Image startBackgroundLeft;
    touchgfx::Image startBackgroundRight;
    touchgfx::FadeAnimator< touchgfx::TextArea > startTextArea;
    touchgfx::FadeAnimator< touchgfx::TextArea > optionTextArea;
    touchgfx::FadeAnimator< touchgfx::Button > settingsButton;
    touchgfx::FadeAnimator< touchgfx::Button > infoButton;
    touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  startButtonClickListener;
    touchgfx::FadeAnimator< touchgfx::Image > leftButton;
    touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  leftButtonClickListener;
    touchgfx::FadeAnimator< touchgfx::Image > rightButton;
    touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  rightButtonClickListener;

    /*
     * Wildcard Buffers
     */
    static const uint16_t CLOCKTEXTAREABUFFER1_SIZE = 10;
    touchgfx::Unicode::UnicodeChar clockTextAreaBuffer1[CLOCKTEXTAREABUFFER1_SIZE];
    static const uint16_t CLOCKTEXTAREABUFFER2_SIZE = 10;
    touchgfx::Unicode::UnicodeChar clockTextAreaBuffer2[CLOCKTEXTAREABUFFER2_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<SelectingMenuViewBase, const touchgfx::AbstractButtonContainer&> flexButtonCallback;
    touchgfx::Callback<SelectingMenuViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src);
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // SELECTINGMENUVIEWBASE_HPP
