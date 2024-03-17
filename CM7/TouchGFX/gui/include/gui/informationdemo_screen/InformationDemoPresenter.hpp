#ifndef INFORMATIONDEMOPRESENTER_HPP
#define INFORMATIONDEMOPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class InformationDemoView;

class InformationDemoPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    InformationDemoPresenter(InformationDemoView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~InformationDemoPresenter() {};

    /*******************************************************
                Passing data through screens
    *******************************************************/

    int16_t getPreviousScreen()
    {
        return model->getPreviousScreen();
    }

    // Passing the clock settings

    void saveHourClock(int16_t hour)
    {
        model->saveHourClock(hour);
    }

    void saveMinuteClock(int16_t minute)
    {
        model->saveMinuteClock(minute);
    }

    int16_t getHourClock()
    {
        return model->getHourClock();
    }

    int16_t getMinuteClock()
    {
        return model->getMinuteClock();
    }

    // Saving the cooking time remaining

    void saveMinuteCookingTimer(int16_t savedMinuteCookingTimer)
    {
        model->saveMinuteCookingTimer(savedMinuteCookingTimer);
    }

    void saveSecondCookingTimer(int16_t savedSecondCookingTimer)
    {
        model->saveSecondCookingTimer(savedSecondCookingTimer);
    }

    int16_t getMinuteCookingTimer()
    {
        return model->getMinuteCookingTimer();
    }

    int16_t getSecondCookingTimer()
    {
        return model->getSecondCookingTimer();
    }

private:
    InformationDemoPresenter();

    InformationDemoView& view;
};

#endif // INFORMATIONDEMOPRESENTER_HPP
