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



void setup_scr_alert_received(lv_ui *ui)
{
    //Write codes alert_received
    ui->alert_received = lv_obj_create(NULL);
    lv_obj_set_size(ui->alert_received, 240, 240);
    lv_obj_set_scrollbar_mode(ui->alert_received, LV_SCROLLBAR_MODE_OFF);

    //Write style for alert_received, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->alert_received, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->alert_received, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->alert_received, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes alert_received_img_top_grey_bar
    ui->alert_received_img_top_grey_bar = lv_img_create(ui->alert_received);
    lv_obj_add_flag(ui->alert_received_img_top_grey_bar, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->alert_received_img_top_grey_bar, &_menu_bar_alpha_240x55);
    lv_img_set_pivot(ui->alert_received_img_top_grey_bar, 50,50);
    lv_img_set_angle(ui->alert_received_img_top_grey_bar, 0);
    lv_obj_set_pos(ui->alert_received_img_top_grey_bar, 0, 0);
    lv_obj_set_size(ui->alert_received_img_top_grey_bar, 240, 55);
    lv_obj_add_flag(ui->alert_received_img_top_grey_bar, LV_OBJ_FLAG_FLOATING);

    //Write style for alert_received_img_top_grey_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->alert_received_img_top_grey_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->alert_received_img_top_grey_bar, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->alert_received_img_top_grey_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->alert_received_img_top_grey_bar, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes alert_received_label_alert_bar
    ui->alert_received_label_alert_bar = lv_label_create(ui->alert_received);
    lv_label_set_text(ui->alert_received_label_alert_bar, "Alert");
    lv_label_set_long_mode(ui->alert_received_label_alert_bar, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->alert_received_label_alert_bar, 93, 16);
    lv_obj_set_size(ui->alert_received_label_alert_bar, 53, 23);
    lv_obj_add_flag(ui->alert_received_label_alert_bar, LV_OBJ_FLAG_FLOATING);

    //Write style for alert_received_label_alert_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->alert_received_label_alert_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->alert_received_label_alert_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->alert_received_label_alert_bar, lv_color_hex(0xF61414), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->alert_received_label_alert_bar, &lv_font_montserratMedium_21, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->alert_received_label_alert_bar, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->alert_received_label_alert_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->alert_received_label_alert_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->alert_received_label_alert_bar, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->alert_received_label_alert_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->alert_received_label_alert_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->alert_received_label_alert_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->alert_received_label_alert_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->alert_received_label_alert_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->alert_received_label_alert_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes alert_received_alert_button
    ui->alert_received_alert_button = lv_imgbtn_create(ui->alert_received);
    lv_obj_add_flag(ui->alert_received_alert_button, LV_OBJ_FLAG_CHECKABLE);
    lv_imgbtn_set_src(ui->alert_received_alert_button, LV_IMGBTN_STATE_RELEASED, NULL, &_alert_icon_alpha_90x90, NULL);
    lv_imgbtn_set_src(ui->alert_received_alert_button, LV_IMGBTN_STATE_PRESSED, NULL, &_alert_icon_alpha_90x90, NULL);
    lv_imgbtn_set_src(ui->alert_received_alert_button, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_alert_icon_alpha_90x90, NULL);
    lv_imgbtn_set_src(ui->alert_received_alert_button, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &_alert_icon_alpha_90x90, NULL);
    ui->alert_received_alert_button_label = lv_label_create(ui->alert_received_alert_button);
    lv_label_set_text(ui->alert_received_alert_button_label, "");
    lv_label_set_long_mode(ui->alert_received_alert_button_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->alert_received_alert_button_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->alert_received_alert_button, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->alert_received_alert_button, 75, 110);
    lv_obj_set_size(ui->alert_received_alert_button, 90, 90);
    lv_obj_add_flag(ui->alert_received_alert_button, LV_OBJ_FLAG_CLICKABLE);

    //Write style for alert_received_alert_button, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->alert_received_alert_button, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->alert_received_alert_button, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->alert_received_alert_button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->alert_received_alert_button, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->alert_received_alert_button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->alert_received_alert_button, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->alert_received_alert_button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for alert_received_alert_button, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->alert_received_alert_button, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->alert_received_alert_button, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->alert_received_alert_button, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->alert_received_alert_button, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->alert_received_alert_button, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->alert_received_alert_button, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for alert_received_alert_button, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->alert_received_alert_button, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->alert_received_alert_button, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->alert_received_alert_button, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->alert_received_alert_button, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->alert_received_alert_button, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->alert_received_alert_button, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for alert_received_alert_button, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->alert_received_alert_button, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->alert_received_alert_button, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes alert_received_img_close
    ui->alert_received_img_close = lv_img_create(ui->alert_received);
    lv_img_set_src(ui->alert_received_img_close, &_x_thin_alpha_40x40);
    lv_img_set_pivot(ui->alert_received_img_close, 50,50);
    lv_img_set_angle(ui->alert_received_img_close, 0);
    lv_obj_set_pos(ui->alert_received_img_close, 10, 8);
    lv_obj_set_size(ui->alert_received_img_close, 40, 40);
    lv_obj_add_flag(ui->alert_received_img_close, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_flag(ui->alert_received_img_close, LV_OBJ_FLAG_FLOATING);

    //Write style for alert_received_img_close, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->alert_received_img_close, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->alert_received_img_close, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->alert_received_img_close, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->alert_received_img_close, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->alert_received_img_close, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes alert_received_label_1
    ui->alert_received_label_1 = lv_label_create(ui->alert_received);
    lv_label_set_text(ui->alert_received_label_1, "Alert received!");
    lv_label_set_long_mode(ui->alert_received_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->alert_received_label_1, 25, 70);
    lv_obj_set_size(ui->alert_received_label_1, 189, 17);

    //Write style for alert_received_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->alert_received_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->alert_received_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->alert_received_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->alert_received_label_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->alert_received_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->alert_received_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->alert_received_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->alert_received_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->alert_received_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->alert_received_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->alert_received_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->alert_received_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->alert_received_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->alert_received_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes alert_received_img_1
    ui->alert_received_img_1 = lv_img_create(ui->alert_received);
    lv_obj_add_flag(ui->alert_received_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->alert_received_img_1, &_dog_emoji_alpha_30x30);
    lv_img_set_pivot(ui->alert_received_img_1, 50,50);
    lv_img_set_angle(ui->alert_received_img_1, 0);
    lv_obj_set_pos(ui->alert_received_img_1, 141, 96);
    lv_obj_set_size(ui->alert_received_img_1, 30, 30);

    //Write style for alert_received_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->alert_received_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->alert_received_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->alert_received_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->alert_received_img_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of alert_received.


    //Update current screen layout.
    lv_obj_update_layout(ui->alert_received);

}
