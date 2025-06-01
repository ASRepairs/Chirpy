/*
* Copyright 2023 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/


/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include "lvgl.h"
#include "custom.h"
#include "gui_guider.h"
#include <stdio.h>  // make sure this is included for printf

/*********************
 *      DEFINES
 *********************/
void show_home_lizzard_emoji()
{
    if (guider_ui.home_digital != NULL) {
        lv_obj_clear_flag(guider_ui.home_digital_lizzard, LV_OBJ_FLAG_HIDDEN);
        // Temporarily comment this out
        // lv_event_send(guider_ui.home_digital_lizzard, LV_EVENT_VALUE_CHANGED, NULL);
    }
}

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**
 * Create a demo application
 */

void custom_init(lv_ui *ui)
{
    /* Add your codes here */
}

