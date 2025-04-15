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



void setup_scr_messages_convo_screen(lv_ui *ui)
{
    //Write codes messages_convo_screen
    ui->messages_convo_screen = lv_obj_create(NULL);
    lv_obj_set_size(ui->messages_convo_screen, 240, 240);
    lv_obj_set_scrollbar_mode(ui->messages_convo_screen, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->messages_convo_screen, LV_OBJ_FLAG_SCROLLABLE);

    //Write style for messages_convo_screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->messages_convo_screen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->messages_convo_screen, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->messages_convo_screen, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes messages_convo_screen_img_top_grey_bar
    ui->messages_convo_screen_img_top_grey_bar = lv_img_create(ui->messages_convo_screen);
    lv_obj_add_flag(ui->messages_convo_screen_img_top_grey_bar, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->messages_convo_screen_img_top_grey_bar, &_menu_bar_alpha_240x55);
    lv_img_set_pivot(ui->messages_convo_screen_img_top_grey_bar, 50,50);
    lv_img_set_angle(ui->messages_convo_screen_img_top_grey_bar, 0);
    lv_obj_set_pos(ui->messages_convo_screen_img_top_grey_bar, 0, 0);
    lv_obj_set_size(ui->messages_convo_screen_img_top_grey_bar, 240, 55);
    lv_obj_add_flag(ui->messages_convo_screen_img_top_grey_bar, LV_OBJ_FLAG_FLOATING);

    //Write style for messages_convo_screen_img_top_grey_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->messages_convo_screen_img_top_grey_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->messages_convo_screen_img_top_grey_bar, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->messages_convo_screen_img_top_grey_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->messages_convo_screen_img_top_grey_bar, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes messages_convo_screen_label_messages_bar
    ui->messages_convo_screen_label_messages_bar = lv_label_create(ui->messages_convo_screen);
    lv_label_set_text(ui->messages_convo_screen_label_messages_bar, "Messages");
    lv_label_set_long_mode(ui->messages_convo_screen_label_messages_bar, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->messages_convo_screen_label_messages_bar, 59, 16);
    lv_obj_set_size(ui->messages_convo_screen_label_messages_bar, 121, 23);
    lv_obj_add_flag(ui->messages_convo_screen_label_messages_bar, LV_OBJ_FLAG_FLOATING);

    //Write style for messages_convo_screen_label_messages_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->messages_convo_screen_label_messages_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->messages_convo_screen_label_messages_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->messages_convo_screen_label_messages_bar, lv_color_hex(0x09AF2E), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->messages_convo_screen_label_messages_bar, &lv_font_montserratMedium_21, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->messages_convo_screen_label_messages_bar, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->messages_convo_screen_label_messages_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->messages_convo_screen_label_messages_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->messages_convo_screen_label_messages_bar, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->messages_convo_screen_label_messages_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->messages_convo_screen_label_messages_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->messages_convo_screen_label_messages_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->messages_convo_screen_label_messages_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->messages_convo_screen_label_messages_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->messages_convo_screen_label_messages_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes messages_convo_screen_img_close
    ui->messages_convo_screen_img_close = lv_img_create(ui->messages_convo_screen);
    lv_img_set_src(ui->messages_convo_screen_img_close, &_close_icon_alpha_20x20);
    lv_img_set_pivot(ui->messages_convo_screen_img_close, 50,50);
    lv_img_set_angle(ui->messages_convo_screen_img_close, 0);
    lv_obj_set_pos(ui->messages_convo_screen_img_close, 17, 17);
    lv_obj_set_size(ui->messages_convo_screen_img_close, 20, 20);
    lv_obj_add_flag(ui->messages_convo_screen_img_close, LV_OBJ_FLAG_FLOATING);
    lv_obj_add_flag(ui->messages_convo_screen_img_close, LV_OBJ_FLAG_CLICKABLE);

    //Write style for messages_convo_screen_img_close, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->messages_convo_screen_img_close, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->messages_convo_screen_img_close, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->messages_convo_screen_img_close, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->messages_convo_screen_img_close, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes messages_convo_screen_img_message_bar_bottom
    ui->messages_convo_screen_img_message_bar_bottom = lv_img_create(ui->messages_convo_screen);
    lv_img_set_src(ui->messages_convo_screen_img_message_bar_bottom, &_img_bg_2_alpha_209x30);
    lv_img_set_pivot(ui->messages_convo_screen_img_message_bar_bottom, 50,50);
    lv_img_set_angle(ui->messages_convo_screen_img_message_bar_bottom, 0);
    lv_obj_set_pos(ui->messages_convo_screen_img_message_bar_bottom, 16, 200);
    lv_obj_set_size(ui->messages_convo_screen_img_message_bar_bottom, 209, 30);
    lv_obj_add_flag(ui->messages_convo_screen_img_message_bar_bottom, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_flag(ui->messages_convo_screen_img_message_bar_bottom, LV_OBJ_FLAG_FLOATING);

    //Write style for messages_convo_screen_img_message_bar_bottom, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->messages_convo_screen_img_message_bar_bottom, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->messages_convo_screen_img_message_bar_bottom, lv_color_hex(0x242424), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->messages_convo_screen_img_message_bar_bottom, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->messages_convo_screen_img_message_bar_bottom, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->messages_convo_screen_img_message_bar_bottom, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes messages_convo_screen_label_choose_emote
    ui->messages_convo_screen_label_choose_emote = lv_label_create(ui->messages_convo_screen);
    lv_label_set_text(ui->messages_convo_screen_label_choose_emote, "Choose emote here...");
    lv_label_set_long_mode(ui->messages_convo_screen_label_choose_emote, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->messages_convo_screen_label_choose_emote, 30, 209);
    lv_obj_set_size(ui->messages_convo_screen_label_choose_emote, 181, 12);
    lv_obj_add_flag(ui->messages_convo_screen_label_choose_emote, LV_OBJ_FLAG_FLOATING);

    //Write style for messages_convo_screen_label_choose_emote, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->messages_convo_screen_label_choose_emote, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->messages_convo_screen_label_choose_emote, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->messages_convo_screen_label_choose_emote, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->messages_convo_screen_label_choose_emote, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->messages_convo_screen_label_choose_emote, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->messages_convo_screen_label_choose_emote, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->messages_convo_screen_label_choose_emote, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->messages_convo_screen_label_choose_emote, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->messages_convo_screen_label_choose_emote, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->messages_convo_screen_label_choose_emote, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->messages_convo_screen_label_choose_emote, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->messages_convo_screen_label_choose_emote, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->messages_convo_screen_label_choose_emote, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->messages_convo_screen_label_choose_emote, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of messages_convo_screen.


    //Update current screen layout.
    lv_obj_update_layout(ui->messages_convo_screen);

    //Init events for screen.
    events_init_messages_convo_screen(ui);
}
