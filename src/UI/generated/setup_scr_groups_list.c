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



void setup_scr_groups_list(lv_ui *ui)
{
    //Write codes groups_list
    ui->groups_list = lv_obj_create(NULL);
    lv_obj_set_size(ui->groups_list, 240, 240);
    lv_obj_set_scrollbar_mode(ui->groups_list, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->groups_list, LV_OBJ_FLAG_SCROLLABLE);

    //Write style for groups_list, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->groups_list, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->groups_list, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->groups_list, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_list_cont_groups_scroll
    ui->groups_list_cont_groups_scroll = lv_obj_create(ui->groups_list);
    lv_obj_set_pos(ui->groups_list_cont_groups_scroll, 20, 65);
    lv_obj_set_size(ui->groups_list_cont_groups_scroll, 208, 580);
    lv_obj_set_scrollbar_mode(ui->groups_list_cont_groups_scroll, LV_SCROLLBAR_MODE_ON);
    lv_obj_add_flag(ui->groups_list_cont_groups_scroll, LV_OBJ_FLAG_SCROLLABLE);

    //Write style for groups_list_cont_groups_scroll, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->groups_list_cont_groups_scroll, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->groups_list_cont_groups_scroll, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->groups_list_cont_groups_scroll, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->groups_list_cont_groups_scroll, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_list_cont_groups_scroll, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->groups_list_cont_groups_scroll, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->groups_list_cont_groups_scroll, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->groups_list_cont_groups_scroll, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->groups_list_cont_groups_scroll, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->groups_list_cont_groups_scroll, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->groups_list_cont_groups_scroll, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_list_cont_gr_1
    ui->groups_list_cont_gr_1 = lv_obj_create(ui->groups_list_cont_groups_scroll);
    lv_obj_set_pos(ui->groups_list_cont_gr_1, 1, 0);
    lv_obj_set_size(ui->groups_list_cont_gr_1, 210, 55);
    lv_obj_set_scrollbar_mode(ui->groups_list_cont_gr_1, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->groups_list_cont_gr_1, LV_OBJ_FLAG_CLICKABLE);

    //Write style for groups_list_cont_gr_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->groups_list_cont_gr_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->groups_list_cont_gr_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->groups_list_cont_gr_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->groups_list_cont_gr_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_list_cont_gr_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->groups_list_cont_gr_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->groups_list_cont_gr_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->groups_list_cont_gr_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->groups_list_cont_gr_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->groups_list_cont_gr_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->groups_list_cont_gr_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_list_img_group_bar_1
    ui->groups_list_img_group_bar_1 = lv_img_create(ui->groups_list_cont_gr_1);
    lv_obj_add_flag(ui->groups_list_img_group_bar_1, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->groups_list_img_group_bar_1, &_message_list_rectangle_alpha_200x50);
    lv_img_set_pivot(ui->groups_list_img_group_bar_1, 50,50);
    lv_img_set_angle(ui->groups_list_img_group_bar_1, 0);
    lv_obj_set_pos(ui->groups_list_img_group_bar_1, 0, -1);
    lv_obj_set_size(ui->groups_list_img_group_bar_1, 200, 50);

    //Write style for groups_list_img_group_bar_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->groups_list_img_group_bar_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->groups_list_img_group_bar_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_list_img_group_bar_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->groups_list_img_group_bar_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_list_img_group_1
    ui->groups_list_img_group_1 = lv_img_create(ui->groups_list_cont_gr_1);
    lv_obj_add_flag(ui->groups_list_img_group_1, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->groups_list_img_group_1, &_img_avatar_1_alpha_30x30);
    lv_img_set_pivot(ui->groups_list_img_group_1, 50,50);
    lv_img_set_angle(ui->groups_list_img_group_1, 0);
    lv_obj_set_pos(ui->groups_list_img_group_1, 15, 9);
    lv_obj_set_size(ui->groups_list_img_group_1, 30, 30);

    //Write style for groups_list_img_group_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->groups_list_img_group_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->groups_list_img_group_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->groups_list_img_group_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_list_img_group_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->groups_list_img_group_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_list_label_group_1
    ui->groups_list_label_group_1 = lv_label_create(ui->groups_list_cont_gr_1);
    lv_label_set_text(ui->groups_list_label_group_1, "Group 1\n");
    lv_label_set_long_mode(ui->groups_list_label_group_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->groups_list_label_group_1, 63, 14);
    lv_obj_set_size(ui->groups_list_label_group_1, 116, 20);

    //Write style for groups_list_label_group_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->groups_list_label_group_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_list_label_group_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->groups_list_label_group_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->groups_list_label_group_1, &lv_font_montserratMedium_19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->groups_list_label_group_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->groups_list_label_group_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->groups_list_label_group_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->groups_list_label_group_1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->groups_list_label_group_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->groups_list_label_group_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->groups_list_label_group_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->groups_list_label_group_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->groups_list_label_group_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->groups_list_label_group_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_list_cont_gr_2
    ui->groups_list_cont_gr_2 = lv_obj_create(ui->groups_list_cont_groups_scroll);
    lv_obj_set_pos(ui->groups_list_cont_gr_2, 1, 56);
    lv_obj_set_size(ui->groups_list_cont_gr_2, 210, 55);
    lv_obj_set_scrollbar_mode(ui->groups_list_cont_gr_2, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->groups_list_cont_gr_2, LV_OBJ_FLAG_CLICKABLE);

    //Write style for groups_list_cont_gr_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->groups_list_cont_gr_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->groups_list_cont_gr_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->groups_list_cont_gr_2, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->groups_list_cont_gr_2, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_list_cont_gr_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->groups_list_cont_gr_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->groups_list_cont_gr_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->groups_list_cont_gr_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->groups_list_cont_gr_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->groups_list_cont_gr_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->groups_list_cont_gr_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_list_img_group_bar_2
    ui->groups_list_img_group_bar_2 = lv_img_create(ui->groups_list_cont_gr_2);
    lv_img_set_src(ui->groups_list_img_group_bar_2, &_message_list_rectangle_alpha_200x50);
    lv_img_set_pivot(ui->groups_list_img_group_bar_2, 50,50);
    lv_img_set_angle(ui->groups_list_img_group_bar_2, 0);
    lv_obj_set_pos(ui->groups_list_img_group_bar_2, 0, 0);
    lv_obj_set_size(ui->groups_list_img_group_bar_2, 200, 50);
    lv_obj_add_flag(ui->groups_list_img_group_bar_2, LV_OBJ_FLAG_CLICKABLE);

    //Write style for groups_list_img_group_bar_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->groups_list_img_group_bar_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->groups_list_img_group_bar_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_list_img_group_bar_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->groups_list_img_group_bar_2, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_list_img_group_2
    ui->groups_list_img_group_2 = lv_img_create(ui->groups_list_cont_gr_2);
    lv_obj_add_flag(ui->groups_list_img_group_2, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->groups_list_img_group_2, &_img_avatar_1_alpha_30x30);
    lv_img_set_pivot(ui->groups_list_img_group_2, 50,50);
    lv_img_set_angle(ui->groups_list_img_group_2, 0);
    lv_obj_set_pos(ui->groups_list_img_group_2, 15, 10);
    lv_obj_set_size(ui->groups_list_img_group_2, 30, 30);

    //Write style for groups_list_img_group_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->groups_list_img_group_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->groups_list_img_group_2, lv_color_hex(0xF61414), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->groups_list_img_group_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_list_img_group_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->groups_list_img_group_2, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_list_label_group_2
    ui->groups_list_label_group_2 = lv_label_create(ui->groups_list_cont_gr_2);
    lv_label_set_text(ui->groups_list_label_group_2, "Group 2\n");
    lv_label_set_long_mode(ui->groups_list_label_group_2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->groups_list_label_group_2, 63, 15);
    lv_obj_set_size(ui->groups_list_label_group_2, 116, 20);

    //Write style for groups_list_label_group_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->groups_list_label_group_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_list_label_group_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->groups_list_label_group_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->groups_list_label_group_2, &lv_font_montserratMedium_19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->groups_list_label_group_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->groups_list_label_group_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->groups_list_label_group_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->groups_list_label_group_2, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->groups_list_label_group_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->groups_list_label_group_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->groups_list_label_group_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->groups_list_label_group_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->groups_list_label_group_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->groups_list_label_group_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_list_cont_gr_3
    ui->groups_list_cont_gr_3 = lv_obj_create(ui->groups_list_cont_groups_scroll);
    lv_obj_set_pos(ui->groups_list_cont_gr_3, 1, 114);
    lv_obj_set_size(ui->groups_list_cont_gr_3, 210, 55);
    lv_obj_set_scrollbar_mode(ui->groups_list_cont_gr_3, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->groups_list_cont_gr_3, LV_OBJ_FLAG_CLICKABLE);

    //Write style for groups_list_cont_gr_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->groups_list_cont_gr_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->groups_list_cont_gr_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->groups_list_cont_gr_3, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->groups_list_cont_gr_3, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_list_cont_gr_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->groups_list_cont_gr_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->groups_list_cont_gr_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->groups_list_cont_gr_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->groups_list_cont_gr_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->groups_list_cont_gr_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->groups_list_cont_gr_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_list_img_group_bar_3
    ui->groups_list_img_group_bar_3 = lv_img_create(ui->groups_list_cont_gr_3);
    lv_img_set_src(ui->groups_list_img_group_bar_3, &_message_list_rectangle_alpha_200x50);
    lv_img_set_pivot(ui->groups_list_img_group_bar_3, 50,50);
    lv_img_set_angle(ui->groups_list_img_group_bar_3, 0);
    lv_obj_set_pos(ui->groups_list_img_group_bar_3, 0, 1);
    lv_obj_set_size(ui->groups_list_img_group_bar_3, 200, 50);
    lv_obj_add_flag(ui->groups_list_img_group_bar_3, LV_OBJ_FLAG_CLICKABLE);

    //Write style for groups_list_img_group_bar_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->groups_list_img_group_bar_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->groups_list_img_group_bar_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_list_img_group_bar_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->groups_list_img_group_bar_3, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_list_img_group_3
    ui->groups_list_img_group_3 = lv_img_create(ui->groups_list_cont_gr_3);
    lv_obj_add_flag(ui->groups_list_img_group_3, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->groups_list_img_group_3, &_img_avatar_1_alpha_30x30);
    lv_img_set_pivot(ui->groups_list_img_group_3, 50,50);
    lv_img_set_angle(ui->groups_list_img_group_3, 0);
    lv_obj_set_pos(ui->groups_list_img_group_3, 15, 10);
    lv_obj_set_size(ui->groups_list_img_group_3, 30, 30);

    //Write style for groups_list_img_group_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->groups_list_img_group_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->groups_list_img_group_3, lv_color_hex(0x496ADE), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->groups_list_img_group_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_list_img_group_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->groups_list_img_group_3, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_list_label_group_3
    ui->groups_list_label_group_3 = lv_label_create(ui->groups_list_cont_gr_3);
    lv_label_set_text(ui->groups_list_label_group_3, "Group 3\n");
    lv_label_set_long_mode(ui->groups_list_label_group_3, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->groups_list_label_group_3, 63, 15);
    lv_obj_set_size(ui->groups_list_label_group_3, 116, 20);

    //Write style for groups_list_label_group_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->groups_list_label_group_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_list_label_group_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->groups_list_label_group_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->groups_list_label_group_3, &lv_font_montserratMedium_19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->groups_list_label_group_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->groups_list_label_group_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->groups_list_label_group_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->groups_list_label_group_3, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->groups_list_label_group_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->groups_list_label_group_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->groups_list_label_group_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->groups_list_label_group_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->groups_list_label_group_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->groups_list_label_group_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_list_cont_gr_4
    ui->groups_list_cont_gr_4 = lv_obj_create(ui->groups_list_cont_groups_scroll);
    lv_obj_set_pos(ui->groups_list_cont_gr_4, 1, 172);
    lv_obj_set_size(ui->groups_list_cont_gr_4, 210, 55);
    lv_obj_set_scrollbar_mode(ui->groups_list_cont_gr_4, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->groups_list_cont_gr_4, LV_OBJ_FLAG_CLICKABLE);

    //Write style for groups_list_cont_gr_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->groups_list_cont_gr_4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->groups_list_cont_gr_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->groups_list_cont_gr_4, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->groups_list_cont_gr_4, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_list_cont_gr_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->groups_list_cont_gr_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->groups_list_cont_gr_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->groups_list_cont_gr_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->groups_list_cont_gr_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->groups_list_cont_gr_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->groups_list_cont_gr_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_list_img_group_bar_4
    ui->groups_list_img_group_bar_4 = lv_img_create(ui->groups_list_cont_gr_4);
    lv_img_set_src(ui->groups_list_img_group_bar_4, &_message_list_rectangle_alpha_200x50);
    lv_img_set_pivot(ui->groups_list_img_group_bar_4, 50,50);
    lv_img_set_angle(ui->groups_list_img_group_bar_4, 0);
    lv_obj_set_pos(ui->groups_list_img_group_bar_4, 0, 0);
    lv_obj_set_size(ui->groups_list_img_group_bar_4, 200, 50);
    lv_obj_add_flag(ui->groups_list_img_group_bar_4, LV_OBJ_FLAG_CLICKABLE);

    //Write style for groups_list_img_group_bar_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->groups_list_img_group_bar_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->groups_list_img_group_bar_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_list_img_group_bar_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->groups_list_img_group_bar_4, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_list_img_group_4
    ui->groups_list_img_group_4 = lv_img_create(ui->groups_list_cont_gr_4);
    lv_obj_add_flag(ui->groups_list_img_group_4, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->groups_list_img_group_4, &_img_avatar_1_alpha_30x30);
    lv_img_set_pivot(ui->groups_list_img_group_4, 50,50);
    lv_img_set_angle(ui->groups_list_img_group_4, 0);
    lv_obj_set_pos(ui->groups_list_img_group_4, 15, 10);
    lv_obj_set_size(ui->groups_list_img_group_4, 30, 30);

    //Write style for groups_list_img_group_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->groups_list_img_group_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->groups_list_img_group_4, lv_color_hex(0x2FDAAE), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->groups_list_img_group_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_list_img_group_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->groups_list_img_group_4, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_list_label_group_4
    ui->groups_list_label_group_4 = lv_label_create(ui->groups_list_cont_gr_4);
    lv_label_set_text(ui->groups_list_label_group_4, "Group 4\n");
    lv_label_set_long_mode(ui->groups_list_label_group_4, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->groups_list_label_group_4, 63, 15);
    lv_obj_set_size(ui->groups_list_label_group_4, 116, 20);

    //Write style for groups_list_label_group_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->groups_list_label_group_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_list_label_group_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->groups_list_label_group_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->groups_list_label_group_4, &lv_font_montserratMedium_19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->groups_list_label_group_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->groups_list_label_group_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->groups_list_label_group_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->groups_list_label_group_4, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->groups_list_label_group_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->groups_list_label_group_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->groups_list_label_group_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->groups_list_label_group_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->groups_list_label_group_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->groups_list_label_group_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_list_cont_gr_6
    ui->groups_list_cont_gr_6 = lv_obj_create(ui->groups_list_cont_groups_scroll);
    lv_obj_set_pos(ui->groups_list_cont_gr_6, 1, 288);
    lv_obj_set_size(ui->groups_list_cont_gr_6, 210, 55);
    lv_obj_set_scrollbar_mode(ui->groups_list_cont_gr_6, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->groups_list_cont_gr_6, LV_OBJ_FLAG_CLICKABLE);

    //Write style for groups_list_cont_gr_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->groups_list_cont_gr_6, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->groups_list_cont_gr_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->groups_list_cont_gr_6, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->groups_list_cont_gr_6, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_list_cont_gr_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->groups_list_cont_gr_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->groups_list_cont_gr_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->groups_list_cont_gr_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->groups_list_cont_gr_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->groups_list_cont_gr_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->groups_list_cont_gr_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_list_img_group_bar_6
    ui->groups_list_img_group_bar_6 = lv_img_create(ui->groups_list_cont_gr_6);
    lv_img_set_src(ui->groups_list_img_group_bar_6, &_message_list_rectangle_alpha_200x50);
    lv_img_set_pivot(ui->groups_list_img_group_bar_6, 50,50);
    lv_img_set_angle(ui->groups_list_img_group_bar_6, 0);
    lv_obj_set_pos(ui->groups_list_img_group_bar_6, 0, 0);
    lv_obj_set_size(ui->groups_list_img_group_bar_6, 200, 50);
    lv_obj_add_flag(ui->groups_list_img_group_bar_6, LV_OBJ_FLAG_CLICKABLE);

    //Write style for groups_list_img_group_bar_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->groups_list_img_group_bar_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->groups_list_img_group_bar_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_list_img_group_bar_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->groups_list_img_group_bar_6, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_list_img_group_6
    ui->groups_list_img_group_6 = lv_img_create(ui->groups_list_cont_gr_6);
    lv_obj_add_flag(ui->groups_list_img_group_6, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->groups_list_img_group_6, &_img_avatar_1_alpha_30x30);
    lv_img_set_pivot(ui->groups_list_img_group_6, 50,50);
    lv_img_set_angle(ui->groups_list_img_group_6, 0);
    lv_obj_set_pos(ui->groups_list_img_group_6, 15, 10);
    lv_obj_set_size(ui->groups_list_img_group_6, 30, 30);

    //Write style for groups_list_img_group_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->groups_list_img_group_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->groups_list_img_group_6, lv_color_hex(0xBEAF14), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->groups_list_img_group_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_list_img_group_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->groups_list_img_group_6, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_list_label_group_6
    ui->groups_list_label_group_6 = lv_label_create(ui->groups_list_cont_gr_6);
    lv_label_set_text(ui->groups_list_label_group_6, "Group 6\n");
    lv_label_set_long_mode(ui->groups_list_label_group_6, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->groups_list_label_group_6, 63, 15);
    lv_obj_set_size(ui->groups_list_label_group_6, 116, 20);

    //Write style for groups_list_label_group_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->groups_list_label_group_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_list_label_group_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->groups_list_label_group_6, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->groups_list_label_group_6, &lv_font_montserratMedium_19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->groups_list_label_group_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->groups_list_label_group_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->groups_list_label_group_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->groups_list_label_group_6, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->groups_list_label_group_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->groups_list_label_group_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->groups_list_label_group_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->groups_list_label_group_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->groups_list_label_group_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->groups_list_label_group_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_list_cont_gr_8
    ui->groups_list_cont_gr_8 = lv_obj_create(ui->groups_list_cont_groups_scroll);
    lv_obj_set_pos(ui->groups_list_cont_gr_8, 1, 404);
    lv_obj_set_size(ui->groups_list_cont_gr_8, 210, 55);
    lv_obj_set_scrollbar_mode(ui->groups_list_cont_gr_8, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->groups_list_cont_gr_8, LV_OBJ_FLAG_CLICKABLE);

    //Write style for groups_list_cont_gr_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->groups_list_cont_gr_8, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->groups_list_cont_gr_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->groups_list_cont_gr_8, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->groups_list_cont_gr_8, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_list_cont_gr_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->groups_list_cont_gr_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->groups_list_cont_gr_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->groups_list_cont_gr_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->groups_list_cont_gr_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->groups_list_cont_gr_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->groups_list_cont_gr_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_list_img_group_bar_8
    ui->groups_list_img_group_bar_8 = lv_img_create(ui->groups_list_cont_gr_8);
    lv_img_set_src(ui->groups_list_img_group_bar_8, &_message_list_rectangle_alpha_200x50);
    lv_img_set_pivot(ui->groups_list_img_group_bar_8, 50,50);
    lv_img_set_angle(ui->groups_list_img_group_bar_8, 0);
    lv_obj_set_pos(ui->groups_list_img_group_bar_8, 0, 0);
    lv_obj_set_size(ui->groups_list_img_group_bar_8, 200, 50);
    lv_obj_add_flag(ui->groups_list_img_group_bar_8, LV_OBJ_FLAG_CLICKABLE);

    //Write style for groups_list_img_group_bar_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->groups_list_img_group_bar_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->groups_list_img_group_bar_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_list_img_group_bar_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->groups_list_img_group_bar_8, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_list_img_group_8
    ui->groups_list_img_group_8 = lv_img_create(ui->groups_list_cont_gr_8);
    lv_obj_add_flag(ui->groups_list_img_group_8, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->groups_list_img_group_8, &_img_avatar_1_alpha_30x30);
    lv_img_set_pivot(ui->groups_list_img_group_8, 50,50);
    lv_img_set_angle(ui->groups_list_img_group_8, 0);
    lv_obj_set_pos(ui->groups_list_img_group_8, 15, 10);
    lv_obj_set_size(ui->groups_list_img_group_8, 30, 30);

    //Write style for groups_list_img_group_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->groups_list_img_group_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->groups_list_img_group_8, lv_color_hex(0xD01FBB), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->groups_list_img_group_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_list_img_group_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->groups_list_img_group_8, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_list_label_group_8
    ui->groups_list_label_group_8 = lv_label_create(ui->groups_list_cont_gr_8);
    lv_label_set_text(ui->groups_list_label_group_8, "Group 8\n");
    lv_label_set_long_mode(ui->groups_list_label_group_8, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->groups_list_label_group_8, 63, 15);
    lv_obj_set_size(ui->groups_list_label_group_8, 116, 20);

    //Write style for groups_list_label_group_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->groups_list_label_group_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_list_label_group_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->groups_list_label_group_8, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->groups_list_label_group_8, &lv_font_montserratMedium_19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->groups_list_label_group_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->groups_list_label_group_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->groups_list_label_group_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->groups_list_label_group_8, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->groups_list_label_group_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->groups_list_label_group_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->groups_list_label_group_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->groups_list_label_group_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->groups_list_label_group_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->groups_list_label_group_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_list_cont_gr_7
    ui->groups_list_cont_gr_7 = lv_obj_create(ui->groups_list_cont_groups_scroll);
    lv_obj_set_pos(ui->groups_list_cont_gr_7, 1, 346);
    lv_obj_set_size(ui->groups_list_cont_gr_7, 210, 55);
    lv_obj_set_scrollbar_mode(ui->groups_list_cont_gr_7, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->groups_list_cont_gr_7, LV_OBJ_FLAG_CLICKABLE);

    //Write style for groups_list_cont_gr_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->groups_list_cont_gr_7, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->groups_list_cont_gr_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->groups_list_cont_gr_7, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->groups_list_cont_gr_7, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_list_cont_gr_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->groups_list_cont_gr_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->groups_list_cont_gr_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->groups_list_cont_gr_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->groups_list_cont_gr_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->groups_list_cont_gr_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->groups_list_cont_gr_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_list_img_group_bar_7
    ui->groups_list_img_group_bar_7 = lv_img_create(ui->groups_list_cont_gr_7);
    lv_img_set_src(ui->groups_list_img_group_bar_7, &_message_list_rectangle_alpha_200x50);
    lv_img_set_pivot(ui->groups_list_img_group_bar_7, 50,50);
    lv_img_set_angle(ui->groups_list_img_group_bar_7, 0);
    lv_obj_set_pos(ui->groups_list_img_group_bar_7, 0, 0);
    lv_obj_set_size(ui->groups_list_img_group_bar_7, 200, 50);
    lv_obj_add_flag(ui->groups_list_img_group_bar_7, LV_OBJ_FLAG_CLICKABLE);

    //Write style for groups_list_img_group_bar_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->groups_list_img_group_bar_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->groups_list_img_group_bar_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_list_img_group_bar_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->groups_list_img_group_bar_7, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_list_img_group_7
    ui->groups_list_img_group_7 = lv_img_create(ui->groups_list_cont_gr_7);
    lv_obj_add_flag(ui->groups_list_img_group_7, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->groups_list_img_group_7, &_img_avatar_1_alpha_30x30);
    lv_img_set_pivot(ui->groups_list_img_group_7, 50,50);
    lv_img_set_angle(ui->groups_list_img_group_7, 0);
    lv_obj_set_pos(ui->groups_list_img_group_7, 15, 10);
    lv_obj_set_size(ui->groups_list_img_group_7, 30, 30);

    //Write style for groups_list_img_group_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->groups_list_img_group_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->groups_list_img_group_7, lv_color_hex(0x938810), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->groups_list_img_group_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_list_img_group_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->groups_list_img_group_7, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_list_label_group_7
    ui->groups_list_label_group_7 = lv_label_create(ui->groups_list_cont_gr_7);
    lv_label_set_text(ui->groups_list_label_group_7, "Group 7\n");
    lv_label_set_long_mode(ui->groups_list_label_group_7, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->groups_list_label_group_7, 63, 15);
    lv_obj_set_size(ui->groups_list_label_group_7, 116, 20);

    //Write style for groups_list_label_group_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->groups_list_label_group_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_list_label_group_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->groups_list_label_group_7, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->groups_list_label_group_7, &lv_font_montserratMedium_19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->groups_list_label_group_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->groups_list_label_group_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->groups_list_label_group_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->groups_list_label_group_7, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->groups_list_label_group_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->groups_list_label_group_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->groups_list_label_group_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->groups_list_label_group_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->groups_list_label_group_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->groups_list_label_group_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_list_cont_gr_5
    ui->groups_list_cont_gr_5 = lv_obj_create(ui->groups_list_cont_groups_scroll);
    lv_obj_set_pos(ui->groups_list_cont_gr_5, 1, 230);
    lv_obj_set_size(ui->groups_list_cont_gr_5, 210, 55);
    lv_obj_set_scrollbar_mode(ui->groups_list_cont_gr_5, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->groups_list_cont_gr_5, LV_OBJ_FLAG_CLICKABLE);

    //Write style for groups_list_cont_gr_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->groups_list_cont_gr_5, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->groups_list_cont_gr_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->groups_list_cont_gr_5, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->groups_list_cont_gr_5, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_list_cont_gr_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->groups_list_cont_gr_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->groups_list_cont_gr_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->groups_list_cont_gr_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->groups_list_cont_gr_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->groups_list_cont_gr_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->groups_list_cont_gr_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_list_img_group_bar_5
    ui->groups_list_img_group_bar_5 = lv_img_create(ui->groups_list_cont_gr_5);
    lv_img_set_src(ui->groups_list_img_group_bar_5, &_message_list_rectangle_alpha_200x50);
    lv_img_set_pivot(ui->groups_list_img_group_bar_5, 50,50);
    lv_img_set_angle(ui->groups_list_img_group_bar_5, 0);
    lv_obj_set_pos(ui->groups_list_img_group_bar_5, 0, 0);
    lv_obj_set_size(ui->groups_list_img_group_bar_5, 200, 50);
    lv_obj_add_flag(ui->groups_list_img_group_bar_5, LV_OBJ_FLAG_CLICKABLE);

    //Write style for groups_list_img_group_bar_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->groups_list_img_group_bar_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->groups_list_img_group_bar_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_list_img_group_bar_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->groups_list_img_group_bar_5, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_list_img_group_5
    ui->groups_list_img_group_5 = lv_img_create(ui->groups_list_cont_gr_5);
    lv_obj_add_flag(ui->groups_list_img_group_5, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->groups_list_img_group_5, &_img_avatar_1_alpha_30x30);
    lv_img_set_pivot(ui->groups_list_img_group_5, 50,50);
    lv_img_set_angle(ui->groups_list_img_group_5, 0);
    lv_obj_set_pos(ui->groups_list_img_group_5, 15, 10);
    lv_obj_set_size(ui->groups_list_img_group_5, 30, 30);

    //Write style for groups_list_img_group_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->groups_list_img_group_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->groups_list_img_group_5, lv_color_hex(0x26B08C), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->groups_list_img_group_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_list_img_group_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->groups_list_img_group_5, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_list_label_group_5
    ui->groups_list_label_group_5 = lv_label_create(ui->groups_list_cont_gr_5);
    lv_label_set_text(ui->groups_list_label_group_5, "Group 5\n");
    lv_label_set_long_mode(ui->groups_list_label_group_5, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->groups_list_label_group_5, 63, 15);
    lv_obj_set_size(ui->groups_list_label_group_5, 116, 20);

    //Write style for groups_list_label_group_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->groups_list_label_group_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_list_label_group_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->groups_list_label_group_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->groups_list_label_group_5, &lv_font_montserratMedium_19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->groups_list_label_group_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->groups_list_label_group_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->groups_list_label_group_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->groups_list_label_group_5, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->groups_list_label_group_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->groups_list_label_group_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->groups_list_label_group_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->groups_list_label_group_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->groups_list_label_group_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->groups_list_label_group_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_list_cont_gr_10
    ui->groups_list_cont_gr_10 = lv_obj_create(ui->groups_list_cont_groups_scroll);
    lv_obj_set_pos(ui->groups_list_cont_gr_10, 1, 520);
    lv_obj_set_size(ui->groups_list_cont_gr_10, 210, 55);
    lv_obj_set_scrollbar_mode(ui->groups_list_cont_gr_10, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->groups_list_cont_gr_10, LV_OBJ_FLAG_CLICKABLE);

    //Write style for groups_list_cont_gr_10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->groups_list_cont_gr_10, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->groups_list_cont_gr_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->groups_list_cont_gr_10, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->groups_list_cont_gr_10, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_list_cont_gr_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->groups_list_cont_gr_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->groups_list_cont_gr_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->groups_list_cont_gr_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->groups_list_cont_gr_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->groups_list_cont_gr_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->groups_list_cont_gr_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_list_img_group_bar_10
    ui->groups_list_img_group_bar_10 = lv_img_create(ui->groups_list_cont_gr_10);
    lv_img_set_src(ui->groups_list_img_group_bar_10, &_message_list_rectangle_alpha_200x50);
    lv_img_set_pivot(ui->groups_list_img_group_bar_10, 50,50);
    lv_img_set_angle(ui->groups_list_img_group_bar_10, 0);
    lv_obj_set_pos(ui->groups_list_img_group_bar_10, 0, 0);
    lv_obj_set_size(ui->groups_list_img_group_bar_10, 200, 50);
    lv_obj_add_flag(ui->groups_list_img_group_bar_10, LV_OBJ_FLAG_CLICKABLE);

    //Write style for groups_list_img_group_bar_10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->groups_list_img_group_bar_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->groups_list_img_group_bar_10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_list_img_group_bar_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->groups_list_img_group_bar_10, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_list_img_group_10
    ui->groups_list_img_group_10 = lv_img_create(ui->groups_list_cont_gr_10);
    lv_obj_add_flag(ui->groups_list_img_group_10, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->groups_list_img_group_10, &_img_avatar_1_alpha_30x30);
    lv_img_set_pivot(ui->groups_list_img_group_10, 50,50);
    lv_img_set_angle(ui->groups_list_img_group_10, 0);
    lv_obj_set_pos(ui->groups_list_img_group_10, 15, 10);
    lv_obj_set_size(ui->groups_list_img_group_10, 30, 30);

    //Write style for groups_list_img_group_10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->groups_list_img_group_10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->groups_list_img_group_10, lv_color_hex(0xff9d00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->groups_list_img_group_10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_list_img_group_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->groups_list_img_group_10, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_list_label_group_10
    ui->groups_list_label_group_10 = lv_label_create(ui->groups_list_cont_gr_10);
    lv_label_set_text(ui->groups_list_label_group_10, "Group 10\n");
    lv_label_set_long_mode(ui->groups_list_label_group_10, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->groups_list_label_group_10, 63, 15);
    lv_obj_set_size(ui->groups_list_label_group_10, 116, 20);

    //Write style for groups_list_label_group_10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->groups_list_label_group_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_list_label_group_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->groups_list_label_group_10, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->groups_list_label_group_10, &lv_font_montserratMedium_19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->groups_list_label_group_10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->groups_list_label_group_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->groups_list_label_group_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->groups_list_label_group_10, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->groups_list_label_group_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->groups_list_label_group_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->groups_list_label_group_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->groups_list_label_group_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->groups_list_label_group_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->groups_list_label_group_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_list_cont_gr_9
    ui->groups_list_cont_gr_9 = lv_obj_create(ui->groups_list_cont_groups_scroll);
    lv_obj_set_pos(ui->groups_list_cont_gr_9, 1, 462);
    lv_obj_set_size(ui->groups_list_cont_gr_9, 210, 55);
    lv_obj_set_scrollbar_mode(ui->groups_list_cont_gr_9, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->groups_list_cont_gr_9, LV_OBJ_FLAG_CLICKABLE);

    //Write style for groups_list_cont_gr_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->groups_list_cont_gr_9, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->groups_list_cont_gr_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->groups_list_cont_gr_9, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->groups_list_cont_gr_9, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_list_cont_gr_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->groups_list_cont_gr_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->groups_list_cont_gr_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->groups_list_cont_gr_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->groups_list_cont_gr_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->groups_list_cont_gr_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->groups_list_cont_gr_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_list_img_group_bar_9
    ui->groups_list_img_group_bar_9 = lv_img_create(ui->groups_list_cont_gr_9);
    lv_img_set_src(ui->groups_list_img_group_bar_9, &_message_list_rectangle_alpha_200x50);
    lv_img_set_pivot(ui->groups_list_img_group_bar_9, 50,50);
    lv_img_set_angle(ui->groups_list_img_group_bar_9, 0);
    lv_obj_set_pos(ui->groups_list_img_group_bar_9, 0, 0);
    lv_obj_set_size(ui->groups_list_img_group_bar_9, 200, 50);
    lv_obj_add_flag(ui->groups_list_img_group_bar_9, LV_OBJ_FLAG_CLICKABLE);

    //Write style for groups_list_img_group_bar_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->groups_list_img_group_bar_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->groups_list_img_group_bar_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_list_img_group_bar_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->groups_list_img_group_bar_9, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_list_img_group_9
    ui->groups_list_img_group_9 = lv_img_create(ui->groups_list_cont_gr_9);
    lv_obj_add_flag(ui->groups_list_img_group_9, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->groups_list_img_group_9, &_img_avatar_1_alpha_30x30);
    lv_img_set_pivot(ui->groups_list_img_group_9, 50,50);
    lv_img_set_angle(ui->groups_list_img_group_9, 0);
    lv_obj_set_pos(ui->groups_list_img_group_9, 15, 10);
    lv_obj_set_size(ui->groups_list_img_group_9, 30, 30);

    //Write style for groups_list_img_group_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->groups_list_img_group_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->groups_list_img_group_9, lv_color_hex(0x861078), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->groups_list_img_group_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_list_img_group_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->groups_list_img_group_9, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_list_label_group_9
    ui->groups_list_label_group_9 = lv_label_create(ui->groups_list_cont_gr_9);
    lv_label_set_text(ui->groups_list_label_group_9, "Group 9\n");
    lv_label_set_long_mode(ui->groups_list_label_group_9, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->groups_list_label_group_9, 63, 15);
    lv_obj_set_size(ui->groups_list_label_group_9, 116, 20);

    //Write style for groups_list_label_group_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->groups_list_label_group_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_list_label_group_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->groups_list_label_group_9, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->groups_list_label_group_9, &lv_font_montserratMedium_19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->groups_list_label_group_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->groups_list_label_group_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->groups_list_label_group_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->groups_list_label_group_9, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->groups_list_label_group_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->groups_list_label_group_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->groups_list_label_group_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->groups_list_label_group_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->groups_list_label_group_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->groups_list_label_group_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_list_img_top_grey_bar
    ui->groups_list_img_top_grey_bar = lv_img_create(ui->groups_list);
    lv_obj_add_flag(ui->groups_list_img_top_grey_bar, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->groups_list_img_top_grey_bar, &_menu_bar_alpha_240x55);
    lv_img_set_pivot(ui->groups_list_img_top_grey_bar, 50,50);
    lv_img_set_angle(ui->groups_list_img_top_grey_bar, 0);
    lv_obj_set_pos(ui->groups_list_img_top_grey_bar, 0, 0);
    lv_obj_set_size(ui->groups_list_img_top_grey_bar, 240, 55);
    lv_obj_add_flag(ui->groups_list_img_top_grey_bar, LV_OBJ_FLAG_FLOATING);

    //Write style for groups_list_img_top_grey_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->groups_list_img_top_grey_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->groups_list_img_top_grey_bar, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_list_img_top_grey_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->groups_list_img_top_grey_bar, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_list_label_groups_bar
    ui->groups_list_label_groups_bar = lv_label_create(ui->groups_list);
    lv_label_set_text(ui->groups_list_label_groups_bar, "Groups");
    lv_label_set_long_mode(ui->groups_list_label_groups_bar, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->groups_list_label_groups_bar, 93, 16);
    lv_obj_set_size(ui->groups_list_label_groups_bar, 81, 23);
    lv_obj_add_flag(ui->groups_list_label_groups_bar, LV_OBJ_FLAG_FLOATING);

    //Write style for groups_list_label_groups_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->groups_list_label_groups_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_list_label_groups_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->groups_list_label_groups_bar, lv_color_hex(0x496ADE), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->groups_list_label_groups_bar, &lv_font_montserratMedium_21, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->groups_list_label_groups_bar, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->groups_list_label_groups_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->groups_list_label_groups_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->groups_list_label_groups_bar, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->groups_list_label_groups_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->groups_list_label_groups_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->groups_list_label_groups_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->groups_list_label_groups_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->groups_list_label_groups_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->groups_list_label_groups_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes groups_list_img_close
    ui->groups_list_img_close = lv_img_create(ui->groups_list);
    lv_img_set_src(ui->groups_list_img_close, &_x_thin_alpha_40x40);
    lv_img_set_pivot(ui->groups_list_img_close, 50,50);
    lv_img_set_angle(ui->groups_list_img_close, 0);
    lv_obj_set_pos(ui->groups_list_img_close, 10, 8);
    lv_obj_set_size(ui->groups_list_img_close, 40, 40);
    lv_obj_add_flag(ui->groups_list_img_close, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_flag(ui->groups_list_img_close, LV_OBJ_FLAG_FLOATING);

    //Write style for groups_list_img_close, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->groups_list_img_close, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->groups_list_img_close, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->groups_list_img_close, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->groups_list_img_close, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->groups_list_img_close, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of groups_list.


    //Update current screen layout.
    lv_obj_update_layout(ui->groups_list);

    //Init events for screen.
    events_init_groups_list(ui);
}
