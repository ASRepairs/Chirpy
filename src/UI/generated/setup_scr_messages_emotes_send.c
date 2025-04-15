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



void setup_scr_messages_emotes_send(lv_ui *ui)
{
    //Write codes messages_emotes_send
    ui->messages_emotes_send = lv_obj_create(NULL);
    lv_obj_set_size(ui->messages_emotes_send, 240, 240);
    lv_obj_set_scrollbar_mode(ui->messages_emotes_send, LV_SCROLLBAR_MODE_OFF);

    //Write style for messages_emotes_send, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->messages_emotes_send, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->messages_emotes_send, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->messages_emotes_send, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes messages_emotes_send_cont_1
    ui->messages_emotes_send_cont_1 = lv_obj_create(ui->messages_emotes_send);
    lv_obj_set_pos(ui->messages_emotes_send_cont_1, 39, 74);
    lv_obj_set_size(ui->messages_emotes_send_cont_1, 161, 453);
    lv_obj_set_scrollbar_mode(ui->messages_emotes_send_cont_1, LV_SCROLLBAR_MODE_ON);
    lv_obj_add_flag(ui->messages_emotes_send_cont_1, LV_OBJ_FLAG_SCROLLABLE);

    //Write style for messages_emotes_send_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->messages_emotes_send_cont_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->messages_emotes_send_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->messages_emotes_send_cont_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->messages_emotes_send_cont_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->messages_emotes_send_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->messages_emotes_send_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->messages_emotes_send_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->messages_emotes_send_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->messages_emotes_send_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->messages_emotes_send_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->messages_emotes_send_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes messages_emotes_send_emoji_party
    ui->messages_emotes_send_emoji_party = lv_img_create(ui->messages_emotes_send_cont_1);
    lv_obj_add_flag(ui->messages_emotes_send_emoji_party, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->messages_emotes_send_emoji_party, &_emoji_4_alpha_100x100);
    lv_img_set_pivot(ui->messages_emotes_send_emoji_party, 50,50);
    lv_img_set_angle(ui->messages_emotes_send_emoji_party, 0);
    lv_obj_set_pos(ui->messages_emotes_send_emoji_party, 30, 339);
    lv_obj_set_size(ui->messages_emotes_send_emoji_party, 100, 100);

    //Write style for messages_emotes_send_emoji_party, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->messages_emotes_send_emoji_party, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->messages_emotes_send_emoji_party, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->messages_emotes_send_emoji_party, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->messages_emotes_send_emoji_party, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes messages_emotes_send_emoji_heart
    ui->messages_emotes_send_emoji_heart = lv_img_create(ui->messages_emotes_send_cont_1);
    lv_obj_add_flag(ui->messages_emotes_send_emoji_heart, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->messages_emotes_send_emoji_heart, &_emoji_3_alpha_100x100);
    lv_img_set_pivot(ui->messages_emotes_send_emoji_heart, 50,50);
    lv_img_set_angle(ui->messages_emotes_send_emoji_heart, 0);
    lv_obj_set_pos(ui->messages_emotes_send_emoji_heart, 30, 230);
    lv_obj_set_size(ui->messages_emotes_send_emoji_heart, 100, 100);

    //Write style for messages_emotes_send_emoji_heart, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->messages_emotes_send_emoji_heart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->messages_emotes_send_emoji_heart, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->messages_emotes_send_emoji_heart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->messages_emotes_send_emoji_heart, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes messages_emotes_send_emoji_wave
    ui->messages_emotes_send_emoji_wave = lv_img_create(ui->messages_emotes_send_cont_1);
    lv_obj_add_flag(ui->messages_emotes_send_emoji_wave, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->messages_emotes_send_emoji_wave, &_emoji_2_alpha_100x100);
    lv_img_set_pivot(ui->messages_emotes_send_emoji_wave, 50,50);
    lv_img_set_angle(ui->messages_emotes_send_emoji_wave, 0);
    lv_obj_set_pos(ui->messages_emotes_send_emoji_wave, 30, 120);
    lv_obj_set_size(ui->messages_emotes_send_emoji_wave, 100, 100);

    //Write style for messages_emotes_send_emoji_wave, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->messages_emotes_send_emoji_wave, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->messages_emotes_send_emoji_wave, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->messages_emotes_send_emoji_wave, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->messages_emotes_send_emoji_wave, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes messages_emotes_send_emoji_like
    ui->messages_emotes_send_emoji_like = lv_img_create(ui->messages_emotes_send_cont_1);
    lv_obj_add_flag(ui->messages_emotes_send_emoji_like, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->messages_emotes_send_emoji_like, &_emoji_1_alpha_100x100);
    lv_img_set_pivot(ui->messages_emotes_send_emoji_like, 50,50);
    lv_img_set_angle(ui->messages_emotes_send_emoji_like, 0);
    lv_obj_set_pos(ui->messages_emotes_send_emoji_like, 30, 10);
    lv_obj_set_size(ui->messages_emotes_send_emoji_like, 100, 100);

    //Write style for messages_emotes_send_emoji_like, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->messages_emotes_send_emoji_like, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->messages_emotes_send_emoji_like, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->messages_emotes_send_emoji_like, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->messages_emotes_send_emoji_like, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes messages_emotes_send_img_top_grey_bar
    ui->messages_emotes_send_img_top_grey_bar = lv_img_create(ui->messages_emotes_send);
    lv_obj_add_flag(ui->messages_emotes_send_img_top_grey_bar, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->messages_emotes_send_img_top_grey_bar, &_menu_bar_alpha_240x55);
    lv_img_set_pivot(ui->messages_emotes_send_img_top_grey_bar, 50,50);
    lv_img_set_angle(ui->messages_emotes_send_img_top_grey_bar, 0);
    lv_obj_set_pos(ui->messages_emotes_send_img_top_grey_bar, 0, 0);
    lv_obj_set_size(ui->messages_emotes_send_img_top_grey_bar, 240, 55);
    lv_obj_add_flag(ui->messages_emotes_send_img_top_grey_bar, LV_OBJ_FLAG_FLOATING);

    //Write style for messages_emotes_send_img_top_grey_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->messages_emotes_send_img_top_grey_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->messages_emotes_send_img_top_grey_bar, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->messages_emotes_send_img_top_grey_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->messages_emotes_send_img_top_grey_bar, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes messages_emotes_send_label_messages_bar
    ui->messages_emotes_send_label_messages_bar = lv_label_create(ui->messages_emotes_send);
    lv_label_set_text(ui->messages_emotes_send_label_messages_bar, "Messages");
    lv_label_set_long_mode(ui->messages_emotes_send_label_messages_bar, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->messages_emotes_send_label_messages_bar, 59, 16);
    lv_obj_set_size(ui->messages_emotes_send_label_messages_bar, 121, 23);
    lv_obj_add_flag(ui->messages_emotes_send_label_messages_bar, LV_OBJ_FLAG_FLOATING);

    //Write style for messages_emotes_send_label_messages_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->messages_emotes_send_label_messages_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->messages_emotes_send_label_messages_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->messages_emotes_send_label_messages_bar, lv_color_hex(0x09AF2E), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->messages_emotes_send_label_messages_bar, &lv_font_montserratMedium_21, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->messages_emotes_send_label_messages_bar, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->messages_emotes_send_label_messages_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->messages_emotes_send_label_messages_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->messages_emotes_send_label_messages_bar, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->messages_emotes_send_label_messages_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->messages_emotes_send_label_messages_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->messages_emotes_send_label_messages_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->messages_emotes_send_label_messages_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->messages_emotes_send_label_messages_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->messages_emotes_send_label_messages_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes messages_emotes_send_img_close
    ui->messages_emotes_send_img_close = lv_img_create(ui->messages_emotes_send);
    lv_img_set_src(ui->messages_emotes_send_img_close, &_close_icon_alpha_20x20);
    lv_img_set_pivot(ui->messages_emotes_send_img_close, 50,50);
    lv_img_set_angle(ui->messages_emotes_send_img_close, 0);
    lv_obj_set_pos(ui->messages_emotes_send_img_close, 17, 17);
    lv_obj_set_size(ui->messages_emotes_send_img_close, 20, 20);
    lv_obj_add_flag(ui->messages_emotes_send_img_close, LV_OBJ_FLAG_FLOATING);
    lv_obj_add_flag(ui->messages_emotes_send_img_close, LV_OBJ_FLAG_CLICKABLE);

    //Write style for messages_emotes_send_img_close, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->messages_emotes_send_img_close, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->messages_emotes_send_img_close, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->messages_emotes_send_img_close, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->messages_emotes_send_img_close, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of messages_emotes_send.


    //Update current screen layout.
    lv_obj_update_layout(ui->messages_emotes_send);

    //Init events for screen.
    events_init_messages_emotes_send(ui);
}
