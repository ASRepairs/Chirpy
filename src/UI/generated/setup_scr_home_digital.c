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



void setup_scr_home_digital(lv_ui *ui)
{
    //Write codes home_digital
    ui->home_digital = lv_obj_create(NULL);
    lv_obj_set_size(ui->home_digital, 240, 240);
    lv_obj_set_scrollbar_mode(ui->home_digital, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->home_digital, LV_OBJ_FLAG_SCROLLABLE);

    //Write style for home_digital, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->home_digital, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->home_digital, &_homescreen_UI_240x240, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->home_digital, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->home_digital, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_digital_label_week
    ui->home_digital_label_week = lv_label_create(ui->home_digital);
    lv_label_set_text(ui->home_digital_label_week, "WED");
    lv_label_set_long_mode(ui->home_digital_label_week, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->home_digital_label_week, 99, 142);
    lv_obj_set_size(ui->home_digital_label_week, 41, 15);

    //Write style for home_digital_label_week, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_digital_label_week, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_digital_label_week, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_digital_label_week, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_digital_label_week, &lv_font_montserratMedium_13, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_digital_label_week, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_digital_label_week, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_digital_label_week, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_digital_label_week, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_digital_label_week, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_digital_label_week, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_digital_label_week, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_digital_label_week, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_digital_label_week, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_digital_label_week, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_digital_label_date
    ui->home_digital_label_date = lv_label_create(ui->home_digital);
    lv_label_set_text(ui->home_digital_label_date, "05/15");
    lv_label_set_long_mode(ui->home_digital_label_date, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->home_digital_label_date, 97, 126);
    lv_obj_set_size(ui->home_digital_label_date, 45, 12);

    //Write style for home_digital_label_date, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_digital_label_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_digital_label_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_digital_label_date, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_digital_label_date, &lv_font_montserratMedium_13, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_digital_label_date, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_digital_label_date, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_digital_label_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_digital_label_date, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_digital_label_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_digital_label_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_digital_label_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_digital_label_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_digital_label_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_digital_label_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_digital_label_time
    ui->home_digital_label_time = lv_label_create(ui->home_digital);
    lv_label_set_text(ui->home_digital_label_time, "05:25");
    lv_label_set_long_mode(ui->home_digital_label_time, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->home_digital_label_time, 55, 65);
    lv_obj_set_size(ui->home_digital_label_time, 130, 45);

    //Write style for home_digital_label_time, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_digital_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_digital_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_digital_label_time, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_digital_label_time, &lv_font_montserratMedium_45, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_digital_label_time, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_digital_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_digital_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_digital_label_time, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_digital_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_digital_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_digital_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_digital_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_digital_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_digital_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_digital_img_1
    ui->home_digital_img_1 = lv_img_create(ui->home_digital);
    lv_obj_add_flag(ui->home_digital_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->home_digital_img_1, &_three_dot_icon1321_alpha_50x50);
    lv_img_set_pivot(ui->home_digital_img_1, 50,50);
    lv_img_set_angle(ui->home_digital_img_1, 0);
    lv_obj_set_pos(ui->home_digital_img_1, 190, 95);
    lv_obj_set_size(ui->home_digital_img_1, 50, 50);

    //Write style for home_digital_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->home_digital_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->home_digital_img_1, 100, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_digital_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->home_digital_img_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_digital_img_2
    ui->home_digital_img_2 = lv_img_create(ui->home_digital);
    lv_obj_add_flag(ui->home_digital_img_2, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->home_digital_img_2, &_three_dot_icon13214214214_alpha_49x17);
    lv_img_set_pivot(ui->home_digital_img_2, 50,50);
    lv_img_set_angle(ui->home_digital_img_2, 0);
    lv_obj_set_pos(ui->home_digital_img_2, 190, 80);
    lv_obj_set_size(ui->home_digital_img_2, 49, 17);

    //Write style for home_digital_img_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->home_digital_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->home_digital_img_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_digital_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->home_digital_img_2, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_digital_img_4
    ui->home_digital_img_4 = lv_img_create(ui->home_digital);
    lv_obj_add_flag(ui->home_digital_img_4, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->home_digital_img_4, &_gear_twitter_alpha_50x50);
    lv_img_set_pivot(ui->home_digital_img_4, 50,50);
    lv_img_set_angle(ui->home_digital_img_4, 0);
    lv_obj_set_pos(ui->home_digital_img_4, 6, 6);
    lv_obj_set_size(ui->home_digital_img_4, 50, 50);

    //Write style for home_digital_img_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->home_digital_img_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->home_digital_img_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_digital_img_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->home_digital_img_4, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of home_digital.


    //Update current screen layout.
    lv_obj_update_layout(ui->home_digital);

    //Init events for screen.
    events_init_home_digital(ui);
}
