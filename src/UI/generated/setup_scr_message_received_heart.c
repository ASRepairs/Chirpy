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



void setup_scr_message_received_heart(lv_ui *ui)
{
    //Write codes message_received_heart
    ui->message_received_heart = lv_obj_create(NULL);
    lv_obj_set_size(ui->message_received_heart, 240, 240);
    lv_obj_set_scrollbar_mode(ui->message_received_heart, LV_SCROLLBAR_MODE_OFF);

    //Write style for message_received_heart, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->message_received_heart, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->message_received_heart, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->message_received_heart, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes message_received_heart_img_top_grey_bar
    ui->message_received_heart_img_top_grey_bar = lv_img_create(ui->message_received_heart);
    lv_obj_add_flag(ui->message_received_heart_img_top_grey_bar, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->message_received_heart_img_top_grey_bar, &_menu_bar_alpha_240x55);
    lv_img_set_pivot(ui->message_received_heart_img_top_grey_bar, 50,50);
    lv_img_set_angle(ui->message_received_heart_img_top_grey_bar, 0);
    lv_obj_set_pos(ui->message_received_heart_img_top_grey_bar, 0, 0);
    lv_obj_set_size(ui->message_received_heart_img_top_grey_bar, 240, 55);
    lv_obj_add_flag(ui->message_received_heart_img_top_grey_bar, LV_OBJ_FLAG_FLOATING);

    //Write style for message_received_heart_img_top_grey_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->message_received_heart_img_top_grey_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->message_received_heart_img_top_grey_bar, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->message_received_heart_img_top_grey_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->message_received_heart_img_top_grey_bar, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes message_received_heart_img_close
    ui->message_received_heart_img_close = lv_img_create(ui->message_received_heart);
    lv_img_set_src(ui->message_received_heart_img_close, &_x_thin_alpha_40x40);
    lv_img_set_pivot(ui->message_received_heart_img_close, 50,50);
    lv_img_set_angle(ui->message_received_heart_img_close, 0);
    lv_obj_set_pos(ui->message_received_heart_img_close, 10, 8);
    lv_obj_set_size(ui->message_received_heart_img_close, 40, 40);
    lv_obj_add_flag(ui->message_received_heart_img_close, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_flag(ui->message_received_heart_img_close, LV_OBJ_FLAG_FLOATING);

    //Write style for message_received_heart_img_close, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->message_received_heart_img_close, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->message_received_heart_img_close, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->message_received_heart_img_close, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->message_received_heart_img_close, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->message_received_heart_img_close, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes message_received_heart_label_messages_bar
    ui->message_received_heart_label_messages_bar = lv_label_create(ui->message_received_heart);
    lv_label_set_text(ui->message_received_heart_label_messages_bar, "Messages");
    lv_label_set_long_mode(ui->message_received_heart_label_messages_bar, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->message_received_heart_label_messages_bar, 59, 16);
    lv_obj_set_size(ui->message_received_heart_label_messages_bar, 121, 23);
    lv_obj_add_flag(ui->message_received_heart_label_messages_bar, LV_OBJ_FLAG_FLOATING);

    //Write style for message_received_heart_label_messages_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->message_received_heart_label_messages_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->message_received_heart_label_messages_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->message_received_heart_label_messages_bar, lv_color_hex(0x09AF2E), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->message_received_heart_label_messages_bar, &lv_font_montserratMedium_21, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->message_received_heart_label_messages_bar, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->message_received_heart_label_messages_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->message_received_heart_label_messages_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->message_received_heart_label_messages_bar, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->message_received_heart_label_messages_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->message_received_heart_label_messages_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->message_received_heart_label_messages_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->message_received_heart_label_messages_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->message_received_heart_label_messages_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->message_received_heart_label_messages_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes message_received_heart_label_message_received
    ui->message_received_heart_label_message_received = lv_label_create(ui->message_received_heart);
    lv_label_set_text(ui->message_received_heart_label_message_received, "Message received!");
    lv_label_set_long_mode(ui->message_received_heart_label_message_received, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->message_received_heart_label_message_received, 25, 70);
    lv_obj_set_size(ui->message_received_heart_label_message_received, 189, 18);

    //Write style for message_received_heart_label_message_received, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->message_received_heart_label_message_received, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->message_received_heart_label_message_received, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->message_received_heart_label_message_received, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->message_received_heart_label_message_received, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->message_received_heart_label_message_received, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->message_received_heart_label_message_received, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->message_received_heart_label_message_received, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->message_received_heart_label_message_received, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->message_received_heart_label_message_received, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->message_received_heart_label_message_received, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->message_received_heart_label_message_received, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->message_received_heart_label_message_received, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->message_received_heart_label_message_received, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->message_received_heart_label_message_received, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes message_received_heart_emoji_heart
    ui->message_received_heart_emoji_heart = lv_img_create(ui->message_received_heart);
    lv_obj_add_flag(ui->message_received_heart_emoji_heart, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->message_received_heart_emoji_heart, &_emoji_3_alpha_80x80);
    lv_img_set_pivot(ui->message_received_heart_emoji_heart, 50,50);
    lv_img_set_angle(ui->message_received_heart_emoji_heart, 0);
    lv_obj_set_pos(ui->message_received_heart_emoji_heart, 80, 110);
    lv_obj_set_size(ui->message_received_heart_emoji_heart, 80, 80);

    //Write style for message_received_heart_emoji_heart, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->message_received_heart_emoji_heart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->message_received_heart_emoji_heart, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->message_received_heart_emoji_heart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->message_received_heart_emoji_heart, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes message_received_heart_img_1
    ui->message_received_heart_img_1 = lv_img_create(ui->message_received_heart);
    lv_obj_add_flag(ui->message_received_heart_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->message_received_heart_img_1, &_dog_emoji_alpha_30x30);
    lv_img_set_pivot(ui->message_received_heart_img_1, 50,50);
    lv_img_set_angle(ui->message_received_heart_img_1, 0);
    lv_obj_set_pos(ui->message_received_heart_img_1, 141, 96);
    lv_obj_set_size(ui->message_received_heart_img_1, 30, 30);

    //Write style for message_received_heart_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->message_received_heart_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->message_received_heart_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->message_received_heart_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->message_received_heart_img_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of message_received_heart.


    //Update current screen layout.
    lv_obj_update_layout(ui->message_received_heart);

    //Init events for screen.
    events_init_message_received_heart(ui);
}
