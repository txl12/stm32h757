#include "lvgl_app/lvgl_app.h"
#include <lvgl.h>
#include "porting/lv_port_disp_template.h"
#include "main.h"
#include "lv_demos.h"
#define LVGL_TICK 	5

static void lvgl_init( void ) 
{
    lv_init();
    lv_port_disp_init();        // ??????
    // lv_port_indev_init();       // ???????
    // lv_port_fs_init();          // ?????????
	lv_demo_benchmark();
}

int lvgl_app(void)
{
	lvgl_init();

	while(1) {
		// ??? lv_tick_inc ??? lv_timer_handler
		lv_tick_inc(1);
		lv_timer_handler();
//		HAL_Delay(LVGL_TICK);
	}
}










