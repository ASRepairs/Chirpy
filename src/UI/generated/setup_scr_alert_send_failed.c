/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



void setup_scr_alert_send_failed(lv_ui *ui)
{
    //Write codes alert_send_failed
    ui->alert_send_failed = lv_obj_create(NULL);
    lv_obj_set_size(ui->alert_send_failed, 240, 240);
    lv_obj_set_scrollbar_mode(ui->alert_send_failed, LV_SCROLLBAR_MODE_OFF);

    //Write style for alert_send_failed, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->alert_send_failed, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->alert_send_failed, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->alert_send_failed, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes alert_send_failed_img_top_grey_bar
    ui->alert_send_failed_img_top_grey_bar = lv_img_create(ui->alert_send_failed);
    lv_obj_add_flag(ui->alert_send_failed_img_top_grey_bar, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->alert_send_failed_img_top_grey_bar, &_menu_bar_alpha_240x55);
    lv_img_set_pivot(ui->alert_send_failed_img_top_grey_bar, 50,50);
    lv_img_set_angle(ui->alert_send_failed_img_top_grey_bar, 0);
    lv_obj_set_pos(ui->alert_send_failed_img_top_grey_bar, 0, 0);
    lv_obj_set_size(ui->alert_send_failed_img_top_grey_bar, 240, 55);
    lv_obj_add_flag(ui->alert_send_failed_img_top_grey_bar, LV_OBJ_FLAG_FLOATING);

    //Write style for alert_send_failed_img_top_grey_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->alert_send_failed_img_top_grey_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->alert_send_failed_img_top_grey_bar, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->alert_send_failed_img_top_grey_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->alert_send_failed_img_top_grey_bar, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes alert_send_failed_label_alert_bar
    ui->alert_send_failed_label_alert_bar = lv_label_create(ui->alert_send_failed);
    lv_label_set_text(ui->alert_send_failed_label_alert_bar, "Alert");
    lv_label_set_long_mode(ui->alert_send_failed_label_alert_bar, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->alert_send_failed_label_alert_bar, 93, 16);
    lv_obj_set_size(ui->alert_send_failed_label_alert_bar, 53, 23);
    lv_obj_add_flag(ui->alert_send_failed_label_alert_bar, LV_OBJ_FLAG_FLOATING);

    //Write style for alert_send_failed_label_alert_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->alert_send_failed_label_alert_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->alert_send_failed_label_alert_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->alert_send_failed_label_alert_bar, lv_color_hex(0xF61414), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->alert_send_failed_label_alert_bar, &lv_font_montserratMedium_21, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->alert_send_failed_label_alert_bar, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->alert_send_failed_label_alert_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->alert_send_failed_label_alert_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->alert_send_failed_label_alert_bar, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->alert_send_failed_label_alert_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->alert_send_failed_label_alert_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->alert_send_failed_label_alert_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->alert_send_failed_label_alert_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->alert_send_failed_label_alert_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->alert_send_failed_label_alert_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes alert_send_failed_img_close
    ui->alert_send_failed_img_close = lv_img_create(ui->alert_send_failed);
    lv_img_set_src(ui->alert_send_failed_img_close, &_x_thin_alpha_40x40);
    lv_img_set_pivot(ui->alert_send_failed_img_close, 50,50);
    lv_img_set_angle(ui->alert_send_failed_img_close, 0);
    lv_obj_set_pos(ui->alert_send_failed_img_close, 10, 8);
    lv_obj_set_size(ui->alert_send_failed_img_close, 40, 40);
    lv_obj_add_flag(ui->alert_send_failed_img_close, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_flag(ui->alert_send_failed_img_close, LV_OBJ_FLAG_FLOATING);

    //Write style for alert_send_failed_img_close, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->alert_send_failed_img_close, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->alert_send_failed_img_close, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->alert_send_failed_img_close, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->alert_send_failed_img_close, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->alert_send_failed_img_close, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes alert_send_failed_label_1
    ui->alert_send_failed_label_1 = lv_label_create(ui->alert_send_failed);
    lv_label_set_text(ui->alert_send_failed_label_1, "Failed!\nAlert not send");
    lv_label_set_long_mode(ui->alert_send_failed_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->alert_send_failed_label_1, 37, 120);
    lv_obj_set_size(ui->alert_send_failed_label_1, 166, 35);

    //Write style for alert_send_failed_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->alert_send_failed_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->alert_send_failed_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->alert_send_failed_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->alert_send_failed_label_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->alert_send_failed_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->alert_send_failed_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->alert_send_failed_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->alert_send_failed_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->alert_send_failed_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->alert_send_failed_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->alert_send_failed_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->alert_send_failed_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->alert_send_failed_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->alert_send_failed_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of alert_send_failed.


    //Update current screen layout.
    lv_obj_update_layout(ui->alert_send_failed);

    //Init events for screen.
    events_init_alert_send_failed(ui);
}
