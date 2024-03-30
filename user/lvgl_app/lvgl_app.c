#include "lvgl_app/lvgl_app.h"
#include <lvgl.h>
#include "porting/lv_port_disp_template.h"
#include "porting/lv_port_indev_template.h"
#include "main.h"
#include "lv_demos.h"
#include "i2c.h"
#define LVGL_TICK 	1

static void lvgl_init( void ) 
{
    lv_init();
    lv_port_disp_init();
    lv_port_indev_init();
    // lv_port_indev_init();
    // lv_port_fs_init();
    lv_demo_widgets();
}

int lvgl_app(void)
{
	lvgl_init();

	while(1) {
		// ??? lv_tick_inc ??? lv_timer_handler
		lv_timer_handler();
		HAL_Delay(LVGL_TICK);
	}
}











