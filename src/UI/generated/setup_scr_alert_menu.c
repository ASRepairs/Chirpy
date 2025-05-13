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



void setup_scr_alert_menu(lv_ui *ui)
{
    //Write codes alert_menu
    ui->alert_menu = lv_obj_create(NULL);
    lv_obj_set_size(ui->alert_menu, 240, 240);
    lv_obj_set_scrollbar_mode(ui->alert_menu, LV_SCROLLBAR_MODE_OFF);

    //Write style for alert_menu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->alert_menu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->alert_menu, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->alert_menu, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes alert_menu_img_top_grey_bar
    ui->alert_menu_img_top_grey_bar = lv_img_create(ui->alert_menu);
    lv_obj_add_flag(ui->alert_menu_img_top_grey_bar, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->alert_menu_img_top_grey_bar, &_menu_bar_alpha_240x55);
    lv_img_set_pivot(ui->alert_menu_img_top_grey_bar, 50,50);
    lv_img_set_angle(ui->alert_menu_img_top_grey_bar, 0);
    lv_obj_set_pos(ui->alert_menu_img_top_grey_bar, 0, 0);
    lv_obj_set_size(ui->alert_menu_img_top_grey_bar, 240, 55);
    lv_obj_add_flag(ui->alert_menu_img_top_grey_bar, LV_OBJ_FLAG_FLOATING);

    //Write style for alert_menu_img_top_grey_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->alert_menu_img_top_grey_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->alert_menu_img_top_grey_bar, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->alert_menu_img_top_grey_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->alert_menu_img_top_grey_bar, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes alert_menu_label_alert_bar
    ui->alert_menu_label_alert_bar = lv_label_create(ui->alert_menu);
    lv_label_set_text(ui->alert_menu_label_alert_bar, "Alert");
    lv_label_set_long_mode(ui->alert_menu_label_alert_bar, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->alert_menu_label_alert_bar, 93, 16);
    lv_obj_set_size(ui->alert_menu_label_alert_bar, 53, 23);
    lv_obj_add_flag(ui->alert_menu_label_alert_bar, LV_OBJ_FLAG_FLOATING);

    //Write style for alert_menu_label_alert_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->alert_menu_label_alert_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->alert_menu_label_alert_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->alert_menu_label_alert_bar, lv_color_hex(0xF61414), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->alert_menu_label_alert_bar, &lv_font_montserratMedium_21, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->alert_menu_label_alert_bar, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->alert_menu_label_alert_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->alert_menu_label_alert_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->alert_menu_label_alert_bar, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->alert_menu_label_alert_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->alert_menu_label_alert_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->alert_menu_label_alert_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->alert_menu_label_alert_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->alert_menu_label_alert_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->alert_menu_label_alert_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes alert_menu_alert_button_descrition
    ui->alert_menu_alert_button_descrition = lv_label_create(ui->alert_menu);
    lv_label_set_text(ui->alert_menu_alert_button_descrition, "Touch to send an alert in case of danger");
    lv_label_set_long_mode(ui->alert_menu_alert_button_descrition, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->alert_menu_alert_button_descrition, 11, 180);
    lv_obj_set_size(ui->alert_menu_alert_button_descrition, 218, 36);

    //Write style for alert_menu_alert_button_descrition, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->alert_menu_alert_button_descrition, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->alert_menu_alert_button_descrition, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->alert_menu_alert_button_descrition, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->alert_menu_alert_button_descrition, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->alert_menu_alert_button_descrition, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->alert_menu_alert_button_descrition, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->alert_menu_alert_button_descrition, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->alert_menu_alert_button_descrition, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->alert_menu_alert_button_descrition, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->alert_menu_alert_button_descrition, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->alert_menu_alert_button_descrition, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->alert_menu_alert_button_descrition, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->alert_menu_alert_button_descrition, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->alert_menu_alert_button_descrition, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes alert_menu_alert_button
    ui->alert_menu_alert_button = lv_imgbtn_create(ui->alert_menu);
    lv_obj_add_flag(ui->alert_menu_alert_button, LV_OBJ_FLAG_CHECKABLE);
    lv_imgbtn_set_src(ui->alert_menu_alert_button, LV_IMGBTN_STATE_RELEASED, NULL, &_alert_icon_alpha_90x90, NULL);
    lv_imgbtn_set_src(ui->alert_menu_alert_button, LV_IMGBTN_STATE_PRESSED, NULL, &_alert_icon_alpha_90x90, NULL);
    lv_imgbtn_set_src(ui->alert_menu_alert_button, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_alert_icon_alpha_90x90, NULL);
    lv_imgbtn_set_src(ui->alert_menu_alert_button, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &_alert_icon_alpha_90x90, NULL);
    ui->alert_menu_alert_button_label = lv_label_create(ui->alert_menu_alert_button);
    lv_label_set_text(ui->alert_menu_alert_button_label, "");
    lv_label_set_long_mode(ui->alert_menu_alert_button_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->alert_menu_alert_button_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->alert_menu_alert_button, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->alert_menu_alert_button, 75, 72);
    lv_obj_set_size(ui->alert_menu_alert_button, 90, 90);
    lv_obj_add_flag(ui->alert_menu_alert_button, LV_OBJ_FLAG_CLICKABLE);

    //Write style for alert_menu_alert_button, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->alert_menu_alert_button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->alert_menu_alert_button, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->alert_menu_alert_button, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->alert_menu_alert_button, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->alert_menu_alert_button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->alert_menu_alert_button, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->alert_menu_alert_button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for alert_menu_alert_button, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->alert_menu_alert_button, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->alert_menu_alert_button, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->alert_menu_alert_button, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->alert_menu_alert_button, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->alert_menu_alert_button, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->alert_menu_alert_button, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for alert_menu_alert_button, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->alert_menu_alert_button, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->alert_menu_alert_button, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->alert_menu_alert_button, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->alert_menu_alert_button, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->alert_menu_alert_button, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->alert_menu_alert_button, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for alert_menu_alert_button, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->alert_menu_alert_button, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->alert_menu_alert_button, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes alert_menu_img_close
    ui->alert_menu_img_close = lv_img_create(ui->alert_menu);
    lv_img_set_src(ui->alert_menu_img_close, &_x_thin_alpha_40x40);
    lv_img_set_pivot(ui->alert_menu_img_close, 50,50);
    lv_img_set_angle(ui->alert_menu_img_close, 0);
    lv_obj_set_pos(ui->alert_menu_img_close, 10, 8);
    lv_obj_set_size(ui->alert_menu_img_close, 40, 40);
    lv_obj_add_flag(ui->alert_menu_img_close, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_flag(ui->alert_menu_img_close, LV_OBJ_FLAG_FLOATING);

    //Write style for alert_menu_img_close, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->alert_menu_img_close, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->alert_menu_img_close, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->alert_menu_img_close, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->alert_menu_img_close, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->alert_menu_img_close, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of alert_menu.


    //Update current screen layout.
    lv_obj_update_layout(ui->alert_menu);

    //Init events for screen.
    events_init_alert_menu(ui);
}
