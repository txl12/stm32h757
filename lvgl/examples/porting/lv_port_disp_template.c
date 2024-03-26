/**
 * @file lv_port_disp_templ.c
 *
 */

/*Copy this file as "lv_port_disp.c" and set this value to "1" to enable content*/
#if 1

/*********************
 *      INCLUDES
 *********************/
#include "lv_port_disp_template.h"
#include <stdbool.h>
#include "stm32h7xx_hal.h"
/*********************
 *      DEFINES
 *********************/
 #define LVGL_MemoryAdd 0xc0000000
#ifndef MY_DISP_HOR_RES
    #warning Please define or replace the macro MY_DISP_HOR_RES with the actual screen width, default value 320 is used for now.
    #define MY_DISP_HOR_RES    1024
#endif

#ifndef MY_DISP_VER_RES
    #warning Please define or replace the macro MY_DISP_VER_RES with the actual screen height, default value 240 is used for now.
    #define MY_DISP_VER_RES    600
#endif

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void disp_init(void);

static void disp_flush(lv_display_t * disp, const lv_area_t * area, uint8_t * px_map);

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lv_port_disp_init(void)
{
    /*-------------------------
     * Initialize your display
     * -----------------------*/
    disp_init();

    /*------------------------------------
     * Create a display and set a flush_cb
     * -----------------------------------*/
    lv_display_t * disp = lv_display_create(MY_DISP_HOR_RES, MY_DISP_VER_RES);
    lv_display_set_flush_cb(disp, disp_flush);

//	    static lv_color_t buf_1_1[MY_DISP_HOR_RES * 10];                          /*A buffer for 10 rows*/
//    lv_display_set_buffers(disp, (lv_color_t*)0xc0000000, NULL, 1024*600*2, LV_DISPLAY_RENDER_MODE_PARTIAL);
	
    static lv_color_t *buf_3_1 = (lv_color_t * )(LVGL_MemoryAdd);             /*A screen sized buffer*/
    static lv_color_t *buf_3_2 = (lv_color_t * )(LVGL_MemoryAdd + MY_DISP_HOR_RES*MY_DISP_VER_RES*sizeof(lv_color_t));    
	 lv_display_set_buffers(disp, buf_3_1, buf_3_2,2* MY_DISP_HOR_RES * MY_DISP_VER_RES, LV_DISPLAY_RENDER_MODE_DIRECT);
	
    /* Example 1
     * One buffer for partial rendering*/
//    static lv_color_t buf_1_1[MY_DISP_HOR_RES * 10];                          /*A buffer for 10 rows*/
//    lv_display_set_buffers(disp, buf_1_1, NULL, sizeof(buf_1_1), LV_DISPLAY_RENDER_MODE_PARTIAL);

    /* Example 2
     * Two buffers for partial rendering
     * In flush_cb DMA or similar hardware should be used to update the display in the background.*/
//    static lv_color_t buf_2_1[MY_DISP_HOR_RES * 10];
//    static lv_color_t buf_2_2[MY_DISP_HOR_RES * 10];
//    lv_display_set_buffers(disp, buf_2_1, buf_2_2, sizeof(buf_2_1), LV_DISPLAY_RENDER_MODE_PARTIAL);

//    /* Example 3
//     * Two buffers screen sized buffer for double buffering.
//     * Both LV_DISPLAY_RENDER_MODE_DIRECT and LV_DISPLAY_RENDER_MODE_FULL works, see their comments*/
//    static lv_color_t buf_3_1[MY_DISP_HOR_RES * MY_DISP_VER_RES];
//    static lv_color_t buf_3_2[MY_DISP_HOR_RES * MY_DISP_VER_RES];
//    lv_display_set_buffers(disp, buf_3_1, buf_3_2, sizeof(buf_3_1), LV_DISPLAY_RENDER_MODE_DIRECT);

}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/*Initialize your display and the required peripherals.*/
static void disp_init(void)
{
    /*You code here*/
}

volatile bool disp_flush_enabled = true;

/* Enable updating the screen (the flushing process) when disp_flush() is called by LVGL
 */
void disp_enable_update(void)
{
    disp_flush_enabled = true;
}

/* Disable updating the screen (the flushing process) when disp_flush() is called by LVGL
 */
void disp_disable_update(void)
{
    disp_flush_enabled = false;
}

/*Flush the content of the internal buffer the specific area on the display.
 *`px_map` contains the rendered image as raw pixel map and it should be copied to `area` on the display.
 *You can use DMA or any hardware acceleration to do this operation in the background but
 *'lv_display_flush_ready()' has to be called when it's finished.*/
static void disp_flush(lv_display_t * disp_drv, const lv_area_t * area, uint8_t * px_map)
{
//    if(disp_flush_enabled) {
//        /*The most simple case (but also the slowest) to put all pixels to the screen one-by-one*/

//        int32_t x;
//        int32_t y;
//        for(y = area->y1; y <= area->y2; y++) {
//            for(x = area->x1; x <= area->x2; x++) {
//                /*Put a pixel to the display. For example:*/
//                /*put_px(x, y, *px_map)*/
//								*(volatile uint16_t*)( 0xc0000000 + 2*(x + y*MY_DISP_VER_RES) ) = *px_map ; 	
//                px_map++;
//            }
//        }
//    }
	if(disp_flush_enabled) {
	LTDC_Layer1->CFBAR = (uint32_t)px_map;			// 切换显存地址
	}
    /*IMPORTANT!!!
     *Inform the graphics library that you are ready with the flushing*/
    lv_display_flush_ready(disp_drv);
}
void HAL_LTDC_LineEvenCallback(LTDC_HandleTypeDef *hltdc)
{   
	// 重新载入参数，新显存地址生效，此时显示才会更新
	// 每次进入中断才会更新显示，这样能有效避免撕裂现象	
	__HAL_LTDC_RELOAD_CONFIG(hltdc);						
	HAL_LTDC_ProgramLineEvent(hltdc, 0);
}
#else /*Enable this file at the top*/

/*This dummy typedef exists purely to silence -Wpedantic.*/
typedef int keep_pedantic_happy;
#endif
