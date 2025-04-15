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



void setup_scr_messages_list(lv_ui *ui)
{
    //Write codes messages_list
    ui->messages_list = lv_obj_create(NULL);
    lv_obj_set_size(ui->messages_list, 240, 240);
    lv_obj_set_scrollbar_mode(ui->messages_list, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->messages_list, LV_OBJ_FLAG_SCROLLABLE);

    //Write style for messages_list, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->messages_list, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->messages_list, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->messages_list, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes messages_list_cont_1
    ui->messages_list_cont_1 = lv_obj_create(ui->messages_list);
    lv_obj_set_pos(ui->messages_list_cont_1, 20, 65);
    lv_obj_set_size(ui->messages_list_cont_1, 201, 215);
    lv_obj_set_scrollbar_mode(ui->messages_list_cont_1, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->messages_list_cont_1, LV_OBJ_FLAG_SCROLLABLE);

    //Write style for messages_list_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->messages_list_cont_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->messages_list_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->messages_list_cont_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->messages_list_cont_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->messages_list_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->messages_list_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->messages_list_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->messages_list_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->messages_list_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->messages_list_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->messages_list_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes messages_list_img_contact_bar_Cornelia
    ui->messages_list_img_contact_bar_Cornelia = lv_img_create(ui->messages_list_cont_1);
    lv_obj_add_flag(ui->messages_list_img_contact_bar_Cornelia, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->messages_list_img_contact_bar_Cornelia, &_message_list_rectangle_alpha_200x50);
    lv_img_set_pivot(ui->messages_list_img_contact_bar_Cornelia, 50,50);
    lv_img_set_angle(ui->messages_list_img_contact_bar_Cornelia, 0);
    lv_obj_set_pos(ui->messages_list_img_contact_bar_Cornelia, -2, 161);
    lv_obj_set_size(ui->messages_list_img_contact_bar_Cornelia, 200, 50);

    //Write style for messages_list_img_contact_bar_Cornelia, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->messages_list_img_contact_bar_Cornelia, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->messages_list_img_contact_bar_Cornelia, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->messages_list_img_contact_bar_Cornelia, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->messages_list_img_contact_bar_Cornelia, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes messages_list_img_pfp_Cornelia
    ui->messages_list_img_pfp_Cornelia = lv_img_create(ui->messages_list_cont_1);
    lv_obj_add_flag(ui->messages_list_img_pfp_Cornelia, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->messages_list_img_pfp_Cornelia, &_img_avatar_4_alpha_30x30);
    lv_img_set_pivot(ui->messages_list_img_pfp_Cornelia, 50,50);
    lv_img_set_angle(ui->messages_list_img_pfp_Cornelia, 0);
    lv_obj_set_pos(ui->messages_list_img_pfp_Cornelia, 11, 172);
    lv_obj_set_size(ui->messages_list_img_pfp_Cornelia, 30, 30);

    //Write style for messages_list_img_pfp_Cornelia, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->messages_list_img_pfp_Cornelia, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->messages_list_img_pfp_Cornelia, lv_color_hex(0xB01A9F), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->messages_list_img_pfp_Cornelia, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->messages_list_img_pfp_Cornelia, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->messages_list_img_pfp_Cornelia, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes messages_list_label_name_Cornelia
    ui->messages_list_label_name_Cornelia = lv_label_create(ui->messages_list_cont_1);
    lv_label_set_text(ui->messages_list_label_name_Cornelia, "Cornelia");
    lv_label_set_long_mode(ui->messages_list_label_name_Cornelia, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->messages_list_label_name_Cornelia, 55, 177);
    lv_obj_set_size(ui->messages_list_label_name_Cornelia, 116, 20);

    //Write style for messages_list_label_name_Cornelia, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->messages_list_label_name_Cornelia, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->messages_list_label_name_Cornelia, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->messages_list_label_name_Cornelia, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->messages_list_label_name_Cornelia, &lv_font_montserratMedium_19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->messages_list_label_name_Cornelia, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->messages_list_label_name_Cornelia, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->messages_list_label_name_Cornelia, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->messages_list_label_name_Cornelia, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->messages_list_label_name_Cornelia, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->messages_list_label_name_Cornelia, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->messages_list_label_name_Cornelia, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->messages_list_label_name_Cornelia, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->messages_list_label_name_Cornelia, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->messages_list_label_name_Cornelia, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes messages_list_img_contact_bar_Maria
    ui->messages_list_img_contact_bar_Maria = lv_img_create(ui->messages_list_cont_1);
    lv_obj_add_flag(ui->messages_list_img_contact_bar_Maria, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->messages_list_img_contact_bar_Maria, &_message_list_rectangle_alpha_200x50);
    lv_img_set_pivot(ui->messages_list_img_contact_bar_Maria, 50,50);
    lv_img_set_angle(ui->messages_list_img_contact_bar_Maria, 0);
    lv_obj_set_pos(ui->messages_list_img_contact_bar_Maria, -2, 107);
    lv_obj_set_size(ui->messages_list_img_contact_bar_Maria, 200, 50);

    //Write style for messages_list_img_contact_bar_Maria, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->messages_list_img_contact_bar_Maria, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->messages_list_img_contact_bar_Maria, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->messages_list_img_contact_bar_Maria, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->messages_list_img_contact_bar_Maria, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes messages_list_img_pfp_Maria
    ui->messages_list_img_pfp_Maria = lv_img_create(ui->messages_list_cont_1);
    lv_obj_add_flag(ui->messages_list_img_pfp_Maria, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->messages_list_img_pfp_Maria, &_img_avatar_2_alpha_30x30);
    lv_img_set_pivot(ui->messages_list_img_pfp_Maria, 50,50);
    lv_img_set_angle(ui->messages_list_img_pfp_Maria, 0);
    lv_obj_set_pos(ui->messages_list_img_pfp_Maria, 11, 118);
    lv_obj_set_size(ui->messages_list_img_pfp_Maria, 30, 30);

    //Write style for messages_list_img_pfp_Maria, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->messages_list_img_pfp_Maria, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->messages_list_img_pfp_Maria, lv_color_hex(0x2FDA64), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->messages_list_img_pfp_Maria, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->messages_list_img_pfp_Maria, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->messages_list_img_pfp_Maria, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes messages_list_label_name_Maria
    ui->messages_list_label_name_Maria = lv_label_create(ui->messages_list_cont_1);
    lv_label_set_text(ui->messages_list_label_name_Maria, "Maria");
    lv_label_set_long_mode(ui->messages_list_label_name_Maria, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->messages_list_label_name_Maria, 55, 123);
    lv_obj_set_size(ui->messages_list_label_name_Maria, 116, 20);

    //Write style for messages_list_label_name_Maria, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->messages_list_label_name_Maria, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->messages_list_label_name_Maria, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->messages_list_label_name_Maria, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->messages_list_label_name_Maria, &lv_font_montserratMedium_19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->messages_list_label_name_Maria, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->messages_list_label_name_Maria, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->messages_list_label_name_Maria, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->messages_list_label_name_Maria, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->messages_list_label_name_Maria, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->messages_list_label_name_Maria, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->messages_list_label_name_Maria, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->messages_list_label_name_Maria, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->messages_list_label_name_Maria, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->messages_list_label_name_Maria, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes messages_list_img_contact_bar_Jake
    ui->messages_list_img_contact_bar_Jake = lv_img_create(ui->messages_list_cont_1);
    lv_obj_add_flag(ui->messages_list_img_contact_bar_Jake, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->messages_list_img_contact_bar_Jake, &_message_list_rectangle_alpha_200x50);
    lv_img_set_pivot(ui->messages_list_img_contact_bar_Jake, 50,50);
    lv_img_set_angle(ui->messages_list_img_contact_bar_Jake, 0);
    lv_obj_set_pos(ui->messages_list_img_contact_bar_Jake, -2, 53);
    lv_obj_set_size(ui->messages_list_img_contact_bar_Jake, 200, 50);

    //Write style for messages_list_img_contact_bar_Jake, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->messages_list_img_contact_bar_Jake, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->messages_list_img_contact_bar_Jake, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->messages_list_img_contact_bar_Jake, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->messages_list_img_contact_bar_Jake, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes messages_list_img_pfp_Jake
    ui->messages_list_img_pfp_Jake = lv_img_create(ui->messages_list_cont_1);
    lv_obj_add_flag(ui->messages_list_img_pfp_Jake, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->messages_list_img_pfp_Jake, &_img_avatar_3_alpha_30x30);
    lv_img_set_pivot(ui->messages_list_img_pfp_Jake, 50,50);
    lv_img_set_angle(ui->messages_list_img_pfp_Jake, 0);
    lv_obj_set_pos(ui->messages_list_img_pfp_Jake, 11, 64);
    lv_obj_set_size(ui->messages_list_img_pfp_Jake, 30, 30);

    //Write style for messages_list_img_pfp_Jake, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->messages_list_img_pfp_Jake, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->messages_list_img_pfp_Jake, lv_color_hex(0x2F92DA), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->messages_list_img_pfp_Jake, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->messages_list_img_pfp_Jake, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->messages_list_img_pfp_Jake, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes messages_list_label_name_Jake
    ui->messages_list_label_name_Jake = lv_label_create(ui->messages_list_cont_1);
    lv_label_set_text(ui->messages_list_label_name_Jake, "Jake");
    lv_label_set_long_mode(ui->messages_list_label_name_Jake, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->messages_list_label_name_Jake, 55, 69);
    lv_obj_set_size(ui->messages_list_label_name_Jake, 116, 20);

    //Write style for messages_list_label_name_Jake, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->messages_list_label_name_Jake, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->messages_list_label_name_Jake, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->messages_list_label_name_Jake, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->messages_list_label_name_Jake, &lv_font_montserratMedium_19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->messages_list_label_name_Jake, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->messages_list_label_name_Jake, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->messages_list_label_name_Jake, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->messages_list_label_name_Jake, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->messages_list_label_name_Jake, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->messages_list_label_name_Jake, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->messages_list_label_name_Jake, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->messages_list_label_name_Jake, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->messages_list_label_name_Jake, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->messages_list_label_name_Jake, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes messages_list_img_contact_bar_Adrian
    ui->messages_list_img_contact_bar_Adrian = lv_img_create(ui->messages_list_cont_1);
    lv_obj_add_flag(ui->messages_list_img_contact_bar_Adrian, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->messages_list_img_contact_bar_Adrian, &_message_list_rectangle_alpha_200x50);
    lv_img_set_pivot(ui->messages_list_img_contact_bar_Adrian, 50,50);
    lv_img_set_angle(ui->messages_list_img_contact_bar_Adrian, 0);
    lv_obj_set_pos(ui->messages_list_img_contact_bar_Adrian, -2, -1);
    lv_obj_set_size(ui->messages_list_img_contact_bar_Adrian, 200, 50);

    //Write style for messages_list_img_contact_bar_Adrian, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->messages_list_img_contact_bar_Adrian, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->messages_list_img_contact_bar_Adrian, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->messages_list_img_contact_bar_Adrian, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->messages_list_img_contact_bar_Adrian, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes messages_list_img_pfp_Adrian
    ui->messages_list_img_pfp_Adrian = lv_img_create(ui->messages_list_cont_1);
    lv_obj_add_flag(ui->messages_list_img_pfp_Adrian, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->messages_list_img_pfp_Adrian, &_img_avatar_1_alpha_30x30);
    lv_img_set_pivot(ui->messages_list_img_pfp_Adrian, 50,50);
    lv_img_set_angle(ui->messages_list_img_pfp_Adrian, 0);
    lv_obj_set_pos(ui->messages_list_img_pfp_Adrian, 11, 9);
    lv_obj_set_size(ui->messages_list_img_pfp_Adrian, 30, 30);

    //Write style for messages_list_img_pfp_Adrian, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->messages_list_img_pfp_Adrian, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->messages_list_img_pfp_Adrian, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->messages_list_img_pfp_Adrian, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->messages_list_img_pfp_Adrian, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->messages_list_img_pfp_Adrian, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes messages_list_label_name_Adrian
    ui->messages_list_label_name_Adrian = lv_label_create(ui->messages_list_cont_1);
    lv_label_set_text(ui->messages_list_label_name_Adrian, "Adrian");
    lv_label_set_long_mode(ui->messages_list_label_name_Adrian, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->messages_list_label_name_Adrian, 55, 15);
    lv_obj_set_size(ui->messages_list_label_name_Adrian, 116, 20);

    //Write style for messages_list_label_name_Adrian, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->messages_list_label_name_Adrian, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->messages_list_label_name_Adrian, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->messages_list_label_name_Adrian, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->messages_list_label_name_Adrian, &lv_font_montserratMedium_19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->messages_list_label_name_Adrian, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->messages_list_label_name_Adrian, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->messages_list_label_name_Adrian, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->messages_list_label_name_Adrian, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->messages_list_label_name_Adrian, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->messages_list_label_name_Adrian, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->messages_list_label_name_Adrian, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->messages_list_label_name_Adrian, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->messages_list_label_name_Adrian, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->messages_list_label_name_Adrian, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes messages_list_img_grey_top_bar
    ui->messages_list_img_grey_top_bar = lv_img_create(ui->messages_list);
    lv_obj_add_flag(ui->messages_list_img_grey_top_bar, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->messages_list_img_grey_top_bar, &_menu_bar_alpha_240x55);
    lv_img_set_pivot(ui->messages_list_img_grey_top_bar, 50,50);
    lv_img_set_angle(ui->messages_list_img_grey_top_bar, 0);
    lv_obj_set_pos(ui->messages_list_img_grey_top_bar, 0, 0);
    lv_obj_set_size(ui->messages_list_img_grey_top_bar, 240, 55);
    lv_obj_add_flag(ui->messages_list_img_grey_top_bar, LV_OBJ_FLAG_FLOATING);

    //Write style for messages_list_img_grey_top_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->messages_list_img_grey_top_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->messages_list_img_grey_top_bar, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->messages_list_img_grey_top_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->messages_list_img_grey_top_bar, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes messages_list_label_messages_bar
    ui->messages_list_label_messages_bar = lv_label_create(ui->messages_list);
    lv_label_set_text(ui->messages_list_label_messages_bar, "Messages");
    lv_label_set_long_mode(ui->messages_list_label_messages_bar, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->messages_list_label_messages_bar, 59, 16);
    lv_obj_set_size(ui->messages_list_label_messages_bar, 121, 23);
    lv_obj_add_flag(ui->messages_list_label_messages_bar, LV_OBJ_FLAG_FLOATING);

    //Write style for messages_list_label_messages_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->messages_list_label_messages_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->messages_list_label_messages_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->messages_list_label_messages_bar, lv_color_hex(0x09AF2E), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->messages_list_label_messages_bar, &lv_font_montserratMedium_21, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->messages_list_label_messages_bar, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->messages_list_label_messages_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->messages_list_label_messages_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->messages_list_label_messages_bar, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->messages_list_label_messages_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->messages_list_label_messages_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->messages_list_label_messages_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->messages_list_label_messages_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->messages_list_label_messages_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->messages_list_label_messages_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes messages_list_img_close
    ui->messages_list_img_close = lv_img_create(ui->messages_list);
    lv_img_set_src(ui->messages_list_img_close, &_close_icon_alpha_20x20);
    lv_img_set_pivot(ui->messages_list_img_close, 50,50);
    lv_img_set_angle(ui->messages_list_img_close, 0);
    lv_obj_set_pos(ui->messages_list_img_close, 17, 17);
    lv_obj_set_size(ui->messages_list_img_close, 20, 20);
    lv_obj_add_flag(ui->messages_list_img_close, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_flag(ui->messages_list_img_close, LV_OBJ_FLAG_FLOATING);

    //Write style for messages_list_img_close, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->messages_list_img_close, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->messages_list_img_close, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->messages_list_img_close, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->messages_list_img_close, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of messages_list.


    //Update current screen layout.
    lv_obj_update_layout(ui->messages_list);

    //Init events for screen.
    events_init_messages_list(ui);
}
