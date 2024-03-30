/**
 * @file lv_port_indev_templ.c
 *
 */

/*Copy this file as "lv_port_indev.c" and set this value to "1" to enable content*/
#if 1

/*********************
 *      INCLUDES
 *********************/
#include "lv_port_indev_template.h"
#include "i2c.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void touchpad_init(void);
static void touchpad_read(lv_indev_t * indev, lv_indev_data_t * data);
static bool touchpad_is_pressed(void);
static void touchpad_get_xy(int32_t * x, int32_t * y);

/**********************
 *  STATIC VARIABLES
 **********************/
lv_indev_t * indev_touchpad;
lv_indev_t * indev_mouse;
lv_indev_t * indev_keypad;
lv_indev_t * indev_encoder;
lv_indev_t * indev_button;

static int32_t encoder_diff;
static lv_indev_state_t encoder_state;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lv_port_indev_init(void)
{
    /**
     * Here you will find example implementation of input devices supported by LittelvGL:
     *  - Touchpad
     *  - Mouse (with cursor support)
     *  - Keypad (supports GUI usage only with key)
     *  - Encoder (supports GUI usage only with: left, right, push)
     *  - Button (external buttons to press points on the screen)
     *
     *  The `..._read()` function are only examples.
     *  You should shape them according to your hardware
     */

    /*------------------
     * Touchpad
     * -----------------*/

    /*Initialize your touchpad if you have*/
    touchpad_init();

    /*Register a touchpad input device*/
    indev_touchpad = lv_indev_create();
    lv_indev_set_type(indev_touchpad, LV_INDEV_TYPE_POINTER);
    lv_indev_set_read_cb(indev_touchpad, touchpad_read);

}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/*------------------
 * Touchpad
 * -----------------*/

/*Initialize your touchpad*/
static void touchpad_init(void)
{
    /*Your code comes here*/
}

/*Will be called by the library to read the touchpad*/
static void touchpad_read(lv_indev_t * indev_drv, lv_indev_data_t * data)
{
    static int32_t last_x = 0;
    static int32_t last_y = 0;

    /*Save the pressed coordinates and the state*/
    if(touchpad_is_pressed()) {
        touchpad_get_xy(&last_x, &last_y);
        data->state = LV_INDEV_STATE_PR;
    }
    else {
        data->state = LV_INDEV_STATE_REL;
    }

    /*Set the last pressed coordinates*/
    data->point.x = last_x;
    data->point.y = last_y;
}

/*Return true is the touchpad is pressed*/
static bool touchpad_is_pressed(void)
{
    /*Your code comes here*/
		uint8_t _temp;	//中间变量
		HAL_I2C_Mem_Read(&hi2c2, GT911_DIV_R, GT_GSTID_REG, I2C_MEMADD_SIZE_16BIT, &_temp, 1, 0xff);
    if (_temp& 0x80)
    {
        return true;
    }
    return false;
}

/*Get the x and y coordinates if the touchpad is pressed*/
static void touchpad_get_xy(int32_t * x, int32_t * y)
{
    /*Your code comes here*/
			int32_t x_temp;
		int32_t y_temp;
		uint8_t _temp;
		HAL_I2C_Mem_Read(&hi2c2, GT911_DIV_R, (GT_TPD_Sta  + X_L), I2C_MEMADD_SIZE_16BIT, &_temp, 1, 0xff);
		x_temp  = _temp;
		HAL_I2C_Mem_Read(&hi2c2, GT911_DIV_R, (GT_TPD_Sta  + X_H), I2C_MEMADD_SIZE_16BIT, &_temp, 1, 0xff);
		x_temp |= (_temp<<8);

		HAL_I2C_Mem_Read(&hi2c2, GT911_DIV_R, (GT_TPD_Sta  + Y_L), I2C_MEMADD_SIZE_16BIT, &_temp, 1, 0xff);
		y_temp  = _temp;
		HAL_I2C_Mem_Read(&hi2c2, GT911_DIV_R, (GT_TPD_Sta  + Y_H), I2C_MEMADD_SIZE_16BIT, &_temp, 1, 0xff);
		y_temp |= (_temp<<8);
			_temp=0;
		HAL_I2C_Mem_Write(&hi2c2, GT911_DIV_W, GT_GSTID_REG, I2C_MEMADD_SIZE_16BIT, &_temp, 1, 0xff);
		(*x) = x_temp;
		(*y) = y_temp;
}

#else /*Enable this file at the top*/

/*This dummy typedef exists purely to silence -Wpedantic.*/
typedef int keep_pedantic_happy;
#endif
