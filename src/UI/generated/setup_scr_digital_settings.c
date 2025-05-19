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



void setup_scr_digital_settings(lv_ui *ui)
{
    //Write codes digital_settings
    ui->digital_settings = lv_obj_create(NULL);
    lv_obj_set_size(ui->digital_settings, 240, 240);
    lv_obj_set_scrollbar_mode(ui->digital_settings, LV_SCROLLBAR_MODE_OFF);

    //Write style for digital_settings, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->digital_settings, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->digital_settings, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->digital_settings, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes digital_settings_img_top_grey_bar
    ui->digital_settings_img_top_grey_bar = lv_img_create(ui->digital_settings);
    lv_obj_add_flag(ui->digital_settings_img_top_grey_bar, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->digital_settings_img_top_grey_bar, &_menu_bar_alpha_240x55);
    lv_img_set_pivot(ui->digital_settings_img_top_grey_bar, 50,50);
    lv_img_set_angle(ui->digital_settings_img_top_grey_bar, 0);
    lv_obj_set_pos(ui->digital_settings_img_top_grey_bar, 0, 0);
    lv_obj_set_size(ui->digital_settings_img_top_grey_bar, 240, 55);
    lv_obj_add_flag(ui->digital_settings_img_top_grey_bar, LV_OBJ_FLAG_FLOATING);

    //Write style for digital_settings_img_top_grey_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->digital_settings_img_top_grey_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->digital_settings_img_top_grey_bar, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->digital_settings_img_top_grey_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->digital_settings_img_top_grey_bar, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes digital_settings_label_messages_bar
    ui->digital_settings_label_messages_bar = lv_label_create(ui->digital_settings);
    lv_label_set_text(ui->digital_settings_label_messages_bar, "Settings");
    lv_label_set_long_mode(ui->digital_settings_label_messages_bar, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->digital_settings_label_messages_bar, 59, 16);
    lv_obj_set_size(ui->digital_settings_label_messages_bar, 121, 23);
    lv_obj_add_flag(ui->digital_settings_label_messages_bar, LV_OBJ_FLAG_FLOATING);

    //Write style for digital_settings_label_messages_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->digital_settings_label_messages_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->digital_settings_label_messages_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->digital_settings_label_messages_bar, lv_color_hex(0xffaf0b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->digital_settings_label_messages_bar, &lv_font_montserratMedium_21, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->digital_settings_label_messages_bar, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->digital_settings_label_messages_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->digital_settings_label_messages_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->digital_settings_label_messages_bar, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->digital_settings_label_messages_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->digital_settings_label_messages_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->digital_settings_label_messages_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->digital_settings_label_messages_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->digital_settings_label_messages_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->digital_settings_label_messages_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes digital_settings_img_close
    ui->digital_settings_img_close = lv_img_create(ui->digital_settings);
    lv_img_set_src(ui->digital_settings_img_close, &_x_thin_alpha_40x40);
    lv_img_set_pivot(ui->digital_settings_img_close, 50,50);
    lv_img_set_angle(ui->digital_settings_img_close, 0);
    lv_obj_set_pos(ui->digital_settings_img_close, 10, 8);
    lv_obj_set_size(ui->digital_settings_img_close, 40, 40);
    lv_obj_add_flag(ui->digital_settings_img_close, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_flag(ui->digital_settings_img_close, LV_OBJ_FLAG_FLOATING);

    //Write style for digital_settings_img_close, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->digital_settings_img_close, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->digital_settings_img_close, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->digital_settings_img_close, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->digital_settings_img_close, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->digital_settings_img_close, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes digital_settings_cont_1
    ui->digital_settings_cont_1 = lv_obj_create(ui->digital_settings);
    lv_obj_set_pos(ui->digital_settings_cont_1, 20, 55);
    lv_obj_set_size(ui->digital_settings_cont_1, 200, 185);
    lv_obj_set_scrollbar_mode(ui->digital_settings_cont_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for digital_settings_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->digital_settings_cont_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->digital_settings_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->digital_settings_cont_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->digital_settings_cont_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->digital_settings_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->digital_settings_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->digital_settings_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->digital_settings_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->digital_settings_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->digital_settings_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->digital_settings_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes digital_settings_btn_1
    ui->digital_settings_btn_1 = lv_btn_create(ui->digital_settings_cont_1);
    ui->digital_settings_btn_1_label = lv_label_create(ui->digital_settings_btn_1);
    lv_label_set_text(ui->digital_settings_btn_1_label, "");
    lv_label_set_long_mode(ui->digital_settings_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->digital_settings_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->digital_settings_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->digital_settings_btn_1_label, LV_PCT(100));
    lv_obj_set_pos(ui->digital_settings_btn_1, 13, 8);
    lv_obj_set_size(ui->digital_settings_btn_1, 80, 80);

    //Write style for digital_settings_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->digital_settings_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->digital_settings_btn_1, lv_color_hex(0x282626), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->digital_settings_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->digital_settings_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->digital_settings_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->digital_settings_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->digital_settings_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->digital_settings_btn_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->digital_settings_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->digital_settings_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes digital_settings_lizzard_emoji
    ui->digital_settings_lizzard_emoji = lv_img_create(ui->digital_settings_cont_1);
    lv_obj_add_flag(ui->digital_settings_lizzard_emoji, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->digital_settings_lizzard_emoji, &_lizard_emoji_alpha_75x75);
    lv_img_set_pivot(ui->digital_settings_lizzard_emoji, 50,50);
    lv_img_set_angle(ui->digital_settings_lizzard_emoji, 0);
    lv_obj_set_pos(ui->digital_settings_lizzard_emoji, 17, 11);
    lv_obj_set_size(ui->digital_settings_lizzard_emoji, 75, 75);

    //Write style for digital_settings_lizzard_emoji, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->digital_settings_lizzard_emoji, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->digital_settings_lizzard_emoji, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->digital_settings_lizzard_emoji, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->digital_settings_lizzard_emoji, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes digital_settings_btn_2
    ui->digital_settings_btn_2 = lv_btn_create(ui->digital_settings_cont_1);
    ui->digital_settings_btn_2_label = lv_label_create(ui->digital_settings_btn_2);
    lv_label_set_text(ui->digital_settings_btn_2_label, "");
    lv_label_set_long_mode(ui->digital_settings_btn_2_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->digital_settings_btn_2_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->digital_settings_btn_2, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->digital_settings_btn_2_label, LV_PCT(100));
    lv_obj_set_pos(ui->digital_settings_btn_2, 103, 8);
    lv_obj_set_size(ui->digital_settings_btn_2, 80, 80);

    //Write style for digital_settings_btn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->digital_settings_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->digital_settings_btn_2, lv_color_hex(0x282626), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->digital_settings_btn_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->digital_settings_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->digital_settings_btn_2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->digital_settings_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->digital_settings_btn_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->digital_settings_btn_2, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->digital_settings_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->digital_settings_btn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes digital_settings_btn_3
    ui->digital_settings_btn_3 = lv_btn_create(ui->digital_settings_cont_1);
    ui->digital_settings_btn_3_label = lv_label_create(ui->digital_settings_btn_3);
    lv_label_set_text(ui->digital_settings_btn_3_label, "");
    lv_label_set_long_mode(ui->digital_settings_btn_3_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->digital_settings_btn_3_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->digital_settings_btn_3, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->digital_settings_btn_3_label, LV_PCT(100));
    lv_obj_set_pos(ui->digital_settings_btn_3, 13, 92);
    lv_obj_set_size(ui->digital_settings_btn_3, 80, 80);

    //Write style for digital_settings_btn_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->digital_settings_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->digital_settings_btn_3, lv_color_hex(0x282626), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->digital_settings_btn_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->digital_settings_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->digital_settings_btn_3, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->digital_settings_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->digital_settings_btn_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->digital_settings_btn_3, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->digital_settings_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->digital_settings_btn_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes digital_settings_btn_4
    ui->digital_settings_btn_4 = lv_btn_create(ui->digital_settings_cont_1);
    ui->digital_settings_btn_4_label = lv_label_create(ui->digital_settings_btn_4);
    lv_label_set_text(ui->digital_settings_btn_4_label, "");
    lv_label_set_long_mode(ui->digital_settings_btn_4_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->digital_settings_btn_4_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->digital_settings_btn_4, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->digital_settings_btn_4_label, LV_PCT(100));
    lv_obj_set_pos(ui->digital_settings_btn_4, 103, 92);
    lv_obj_set_size(ui->digital_settings_btn_4, 80, 80);

    //Write style for digital_settings_btn_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->digital_settings_btn_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->digital_settings_btn_4, lv_color_hex(0x282626), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->digital_settings_btn_4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->digital_settings_btn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->digital_settings_btn_4, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->digital_settings_btn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->digital_settings_btn_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->digital_settings_btn_4, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->digital_settings_btn_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->digital_settings_btn_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes digital_settings_img_3
    ui->digital_settings_img_3 = lv_img_create(ui->digital_settings_cont_1);
    lv_obj_add_flag(ui->digital_settings_img_3, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->digital_settings_img_3, &_phoenix_bird_alpha_75x75);
    lv_img_set_pivot(ui->digital_settings_img_3, 50,50);
    lv_img_set_angle(ui->digital_settings_img_3, 0);
    lv_obj_set_pos(ui->digital_settings_img_3, 104, 12);
    lv_obj_set_size(ui->digital_settings_img_3, 75, 75);

    //Write style for digital_settings_img_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->digital_settings_img_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->digital_settings_img_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->digital_settings_img_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->digital_settings_img_3, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes digital_settings_img_1
    ui->digital_settings_img_1 = lv_img_create(ui->digital_settings);
    lv_obj_add_flag(ui->digital_settings_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->digital_settings_img_1, &_dog_emoji_alpha_75x75);
    lv_img_set_pivot(ui->digital_settings_img_1, 50,50);
    lv_img_set_angle(ui->digital_settings_img_1, 0);
    lv_obj_set_pos(ui->digital_settings_img_1, 37, 151);
    lv_obj_set_size(ui->digital_settings_img_1, 75, 75);

    //Write style for digital_settings_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->digital_settings_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->digital_settings_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->digital_settings_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->digital_settings_img_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes digital_settings_img_2
    ui->digital_settings_img_2 = lv_img_create(ui->digital_settings);
    lv_obj_add_flag(ui->digital_settings_img_2, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->digital_settings_img_2, &_cat_emoji_alpha_75x75);
    lv_img_set_pivot(ui->digital_settings_img_2, 50,50);
    lv_img_set_angle(ui->digital_settings_img_2, 0);
    lv_obj_set_pos(ui->digital_settings_img_2, 128, 151);
    lv_obj_set_size(ui->digital_settings_img_2, 75, 75);

    //Write style for digital_settings_img_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->digital_settings_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->digital_settings_img_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->digital_settings_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->digital_settings_img_2, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of digital_settings.


    //Update current screen layout.
    lv_obj_update_layout(ui->digital_settings);

    //Init events for screen.
    events_init_digital_settings(ui);
}
