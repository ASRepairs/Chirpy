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



void setup_scr_groups_contacts(lv_ui *ui)
{
    //Write codes groups_contacts
    ui->groups_contacts = lv_obj_create(NULL);
    lv_obj_set_size(ui->groups_contacts, 240, 240);
    lv_obj_set_scrollbar_mode(ui->groups_contacts, LV_SCROLLBAR_MODE_OFF);

    //Write style for groups_contacts, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->groups_contacts, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->groups_contacts, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->groups_contacts, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_contacts_cont_1
    ui->groups_contacts_cont_1 = lv_obj_create(ui->groups_contacts);
    lv_obj_set_pos(ui->groups_contacts_cont_1, 20, 62);
    lv_obj_set_size(ui->groups_contacts_cont_1, 205, 218);
    lv_obj_set_scrollbar_mode(ui->groups_contacts_cont_1, LV_SCROLLBAR_MODE_ON);
    lv_obj_add_flag(ui->groups_contacts_cont_1, LV_OBJ_FLAG_SCROLLABLE);

    //Write style for groups_contacts_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->groups_contacts_cont_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->groups_contacts_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->groups_contacts_cont_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->groups_contacts_cont_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_contacts_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->groups_contacts_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->groups_contacts_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->groups_contacts_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->groups_contacts_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->groups_contacts_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->groups_contacts_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_contacts_img_contact_bar_4
    ui->groups_contacts_img_contact_bar_4 = lv_img_create(ui->groups_contacts_cont_1);
    lv_obj_add_flag(ui->groups_contacts_img_contact_bar_4, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->groups_contacts_img_contact_bar_4, &_message_list_rectangle_alpha_200x50);
    lv_img_set_pivot(ui->groups_contacts_img_contact_bar_4, 50,50);
    lv_img_set_angle(ui->groups_contacts_img_contact_bar_4, 0);
    lv_obj_set_pos(ui->groups_contacts_img_contact_bar_4, 0, 162);
    lv_obj_set_size(ui->groups_contacts_img_contact_bar_4, 200, 50);

    //Write style for groups_contacts_img_contact_bar_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->groups_contacts_img_contact_bar_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->groups_contacts_img_contact_bar_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_contacts_img_contact_bar_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->groups_contacts_img_contact_bar_4, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_contacts_img_pfp_4
    ui->groups_contacts_img_pfp_4 = lv_img_create(ui->groups_contacts_cont_1);
    lv_obj_add_flag(ui->groups_contacts_img_pfp_4, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->groups_contacts_img_pfp_4, &_img_avatar_4_alpha_30x30);
    lv_img_set_pivot(ui->groups_contacts_img_pfp_4, 50,50);
    lv_img_set_angle(ui->groups_contacts_img_pfp_4, 0);
    lv_obj_set_pos(ui->groups_contacts_img_pfp_4, 11, 172);
    lv_obj_set_size(ui->groups_contacts_img_pfp_4, 30, 30);

    //Write style for groups_contacts_img_pfp_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->groups_contacts_img_pfp_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->groups_contacts_img_pfp_4, lv_color_hex(0xB01A9F), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->groups_contacts_img_pfp_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_contacts_img_pfp_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->groups_contacts_img_pfp_4, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_contacts_label_name_4
    ui->groups_contacts_label_name_4 = lv_label_create(ui->groups_contacts_cont_1);
    lv_label_set_text(ui->groups_contacts_label_name_4, "Maria");
    lv_label_set_long_mode(ui->groups_contacts_label_name_4, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->groups_contacts_label_name_4, 55, 177);
    lv_obj_set_size(ui->groups_contacts_label_name_4, 116, 20);

    //Write style for groups_contacts_label_name_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->groups_contacts_label_name_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_contacts_label_name_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->groups_contacts_label_name_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->groups_contacts_label_name_4, &lv_font_montserratMedium_19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->groups_contacts_label_name_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->groups_contacts_label_name_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->groups_contacts_label_name_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->groups_contacts_label_name_4, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->groups_contacts_label_name_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->groups_contacts_label_name_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->groups_contacts_label_name_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->groups_contacts_label_name_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->groups_contacts_label_name_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->groups_contacts_label_name_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_contacts_img_contact_bar_3
    ui->groups_contacts_img_contact_bar_3 = lv_img_create(ui->groups_contacts_cont_1);
    lv_obj_add_flag(ui->groups_contacts_img_contact_bar_3, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->groups_contacts_img_contact_bar_3, &_message_list_rectangle_alpha_200x50);
    lv_img_set_pivot(ui->groups_contacts_img_contact_bar_3, 50,50);
    lv_img_set_angle(ui->groups_contacts_img_contact_bar_3, 0);
    lv_obj_set_pos(ui->groups_contacts_img_contact_bar_3, 0, 108);
    lv_obj_set_size(ui->groups_contacts_img_contact_bar_3, 200, 50);

    //Write style for groups_contacts_img_contact_bar_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->groups_contacts_img_contact_bar_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->groups_contacts_img_contact_bar_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_contacts_img_contact_bar_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->groups_contacts_img_contact_bar_3, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_contacts_img_pfp_3
    ui->groups_contacts_img_pfp_3 = lv_img_create(ui->groups_contacts_cont_1);
    lv_obj_add_flag(ui->groups_contacts_img_pfp_3, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->groups_contacts_img_pfp_3, &_img_avatar_2_alpha_30x30);
    lv_img_set_pivot(ui->groups_contacts_img_pfp_3, 50,50);
    lv_img_set_angle(ui->groups_contacts_img_pfp_3, 0);
    lv_obj_set_pos(ui->groups_contacts_img_pfp_3, 11, 118);
    lv_obj_set_size(ui->groups_contacts_img_pfp_3, 30, 30);

    //Write style for groups_contacts_img_pfp_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->groups_contacts_img_pfp_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->groups_contacts_img_pfp_3, lv_color_hex(0x2FDA64), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->groups_contacts_img_pfp_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_contacts_img_pfp_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->groups_contacts_img_pfp_3, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_contacts_label_name_3
    ui->groups_contacts_label_name_3 = lv_label_create(ui->groups_contacts_cont_1);
    lv_label_set_text(ui->groups_contacts_label_name_3, "Jake");
    lv_label_set_long_mode(ui->groups_contacts_label_name_3, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->groups_contacts_label_name_3, 55, 124);
    lv_obj_set_size(ui->groups_contacts_label_name_3, 116, 18);

    //Write style for groups_contacts_label_name_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->groups_contacts_label_name_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_contacts_label_name_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->groups_contacts_label_name_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->groups_contacts_label_name_3, &lv_font_montserratMedium_19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->groups_contacts_label_name_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->groups_contacts_label_name_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->groups_contacts_label_name_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->groups_contacts_label_name_3, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->groups_contacts_label_name_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->groups_contacts_label_name_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->groups_contacts_label_name_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->groups_contacts_label_name_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->groups_contacts_label_name_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->groups_contacts_label_name_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_contacts_img_contact_bar_2
    ui->groups_contacts_img_contact_bar_2 = lv_img_create(ui->groups_contacts_cont_1);
    lv_obj_add_flag(ui->groups_contacts_img_contact_bar_2, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->groups_contacts_img_contact_bar_2, &_message_list_rectangle_alpha_200x50);
    lv_img_set_pivot(ui->groups_contacts_img_contact_bar_2, 50,50);
    lv_img_set_angle(ui->groups_contacts_img_contact_bar_2, 0);
    lv_obj_set_pos(ui->groups_contacts_img_contact_bar_2, 0, 53);
    lv_obj_set_size(ui->groups_contacts_img_contact_bar_2, 200, 50);

    //Write style for groups_contacts_img_contact_bar_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->groups_contacts_img_contact_bar_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->groups_contacts_img_contact_bar_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_contacts_img_contact_bar_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->groups_contacts_img_contact_bar_2, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_contacts_img_pfp_2
    ui->groups_contacts_img_pfp_2 = lv_img_create(ui->groups_contacts_cont_1);
    lv_obj_add_flag(ui->groups_contacts_img_pfp_2, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->groups_contacts_img_pfp_2, &_img_avatar_3_alpha_30x30);
    lv_img_set_pivot(ui->groups_contacts_img_pfp_2, 50,50);
    lv_img_set_angle(ui->groups_contacts_img_pfp_2, 0);
    lv_obj_set_pos(ui->groups_contacts_img_pfp_2, 11, 63);
    lv_obj_set_size(ui->groups_contacts_img_pfp_2, 30, 30);

    //Write style for groups_contacts_img_pfp_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->groups_contacts_img_pfp_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->groups_contacts_img_pfp_2, lv_color_hex(0x2F92DA), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->groups_contacts_img_pfp_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_contacts_img_pfp_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->groups_contacts_img_pfp_2, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_contacts_label_name_2
    ui->groups_contacts_label_name_2 = lv_label_create(ui->groups_contacts_cont_1);
    lv_label_set_text(ui->groups_contacts_label_name_2, "Cornelia");
    lv_label_set_long_mode(ui->groups_contacts_label_name_2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->groups_contacts_label_name_2, 55, 68);
    lv_obj_set_size(ui->groups_contacts_label_name_2, 116, 20);

    //Write style for groups_contacts_label_name_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->groups_contacts_label_name_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_contacts_label_name_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->groups_contacts_label_name_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->groups_contacts_label_name_2, &lv_font_montserratMedium_19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->groups_contacts_label_name_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->groups_contacts_label_name_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->groups_contacts_label_name_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->groups_contacts_label_name_2, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->groups_contacts_label_name_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->groups_contacts_label_name_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->groups_contacts_label_name_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->groups_contacts_label_name_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->groups_contacts_label_name_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->groups_contacts_label_name_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_contacts_img_contact_bar_1
    ui->groups_contacts_img_contact_bar_1 = lv_img_create(ui->groups_contacts_cont_1);
    lv_obj_add_flag(ui->groups_contacts_img_contact_bar_1, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->groups_contacts_img_contact_bar_1, &_message_list_rectangle_alpha_200x50);
    lv_img_set_pivot(ui->groups_contacts_img_contact_bar_1, 50,50);
    lv_img_set_angle(ui->groups_contacts_img_contact_bar_1, 0);
    lv_obj_set_pos(ui->groups_contacts_img_contact_bar_1, 0, -1);
    lv_obj_set_size(ui->groups_contacts_img_contact_bar_1, 200, 50);

    //Write style for groups_contacts_img_contact_bar_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->groups_contacts_img_contact_bar_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->groups_contacts_img_contact_bar_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_contacts_img_contact_bar_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->groups_contacts_img_contact_bar_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_contacts_img_pfp_1
    ui->groups_contacts_img_pfp_1 = lv_img_create(ui->groups_contacts_cont_1);
    lv_obj_add_flag(ui->groups_contacts_img_pfp_1, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->groups_contacts_img_pfp_1, &_img_avatar_1_alpha_30x30);
    lv_img_set_pivot(ui->groups_contacts_img_pfp_1, 50,50);
    lv_img_set_angle(ui->groups_contacts_img_pfp_1, 0);
    lv_obj_set_pos(ui->groups_contacts_img_pfp_1, 11, 9);
    lv_obj_set_size(ui->groups_contacts_img_pfp_1, 30, 30);

    //Write style for groups_contacts_img_pfp_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->groups_contacts_img_pfp_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->groups_contacts_img_pfp_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->groups_contacts_img_pfp_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_contacts_img_pfp_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->groups_contacts_img_pfp_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_contacts_label_name_1
    ui->groups_contacts_label_name_1 = lv_label_create(ui->groups_contacts_cont_1);
    lv_label_set_text(ui->groups_contacts_label_name_1, "Adrian");
    lv_label_set_long_mode(ui->groups_contacts_label_name_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->groups_contacts_label_name_1, 55, 14);
    lv_obj_set_size(ui->groups_contacts_label_name_1, 116, 20);

    //Write style for groups_contacts_label_name_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->groups_contacts_label_name_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_contacts_label_name_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->groups_contacts_label_name_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->groups_contacts_label_name_1, &lv_font_montserratMedium_19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->groups_contacts_label_name_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->groups_contacts_label_name_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->groups_contacts_label_name_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->groups_contacts_label_name_1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->groups_contacts_label_name_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->groups_contacts_label_name_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->groups_contacts_label_name_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->groups_contacts_label_name_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->groups_contacts_label_name_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->groups_contacts_label_name_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_contacts_img_top_grey_bar
    ui->groups_contacts_img_top_grey_bar = lv_img_create(ui->groups_contacts);
    lv_obj_add_flag(ui->groups_contacts_img_top_grey_bar, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->groups_contacts_img_top_grey_bar, &_menu_bar_alpha_240x55);
    lv_img_set_pivot(ui->groups_contacts_img_top_grey_bar, 50,50);
    lv_img_set_angle(ui->groups_contacts_img_top_grey_bar, 0);
    lv_obj_set_pos(ui->groups_contacts_img_top_grey_bar, 0, 0);
    lv_obj_set_size(ui->groups_contacts_img_top_grey_bar, 240, 55);
    lv_obj_add_flag(ui->groups_contacts_img_top_grey_bar, LV_OBJ_FLAG_FLOATING);

    //Write style for groups_contacts_img_top_grey_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->groups_contacts_img_top_grey_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->groups_contacts_img_top_grey_bar, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_contacts_img_top_grey_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->groups_contacts_img_top_grey_bar, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_contacts_label_groups_bar
    ui->groups_contacts_label_groups_bar = lv_label_create(ui->groups_contacts);
    lv_label_set_text(ui->groups_contacts_label_groups_bar, "Groups");
    lv_label_set_long_mode(ui->groups_contacts_label_groups_bar, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->groups_contacts_label_groups_bar, 93, 16);
    lv_obj_set_size(ui->groups_contacts_label_groups_bar, 81, 23);
    lv_obj_add_flag(ui->groups_contacts_label_groups_bar, LV_OBJ_FLAG_FLOATING);

    //Write style for groups_contacts_label_groups_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->groups_contacts_label_groups_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_contacts_label_groups_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->groups_contacts_label_groups_bar, lv_color_hex(0x496ADE), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->groups_contacts_label_groups_bar, &lv_font_montserratMedium_21, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->groups_contacts_label_groups_bar, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->groups_contacts_label_groups_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->groups_contacts_label_groups_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->groups_contacts_label_groups_bar, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->groups_contacts_label_groups_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->groups_contacts_label_groups_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->groups_contacts_label_groups_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->groups_contacts_label_groups_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->groups_contacts_label_groups_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->groups_contacts_label_groups_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_contacts_img_close
    ui->groups_contacts_img_close = lv_img_create(ui->groups_contacts);
    lv_img_set_src(ui->groups_contacts_img_close, &_x_thin_alpha_40x40);
    lv_img_set_pivot(ui->groups_contacts_img_close, 50,50);
    lv_img_set_angle(ui->groups_contacts_img_close, 0);
    lv_obj_set_pos(ui->groups_contacts_img_close, 10, 8);
    lv_obj_set_size(ui->groups_contacts_img_close, 40, 40);
    lv_obj_add_flag(ui->groups_contacts_img_close, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_flag(ui->groups_contacts_img_close, LV_OBJ_FLAG_FLOATING);

    //Write style for groups_contacts_img_close, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->groups_contacts_img_close, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->groups_contacts_img_close, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->groups_contacts_img_close, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_contacts_img_close, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->groups_contacts_img_close, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of groups_contacts.


    //Update current screen layout.
    lv_obj_update_layout(ui->groups_contacts);

    //Init events for screen.
    events_init_groups_contacts(ui);
}
