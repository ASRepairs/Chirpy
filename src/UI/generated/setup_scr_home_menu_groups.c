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



void setup_scr_home_menu_groups(lv_ui *ui)
{
    //Write codes home_menu_groups
    ui->home_menu_groups = lv_obj_create(NULL);
    lv_obj_set_size(ui->home_menu_groups, 240, 240);
    lv_obj_set_scrollbar_mode(ui->home_menu_groups, LV_SCROLLBAR_MODE_OFF);

    //Write style for home_menu_groups, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->home_menu_groups, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->home_menu_groups, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->home_menu_groups, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_menu_groups_groups_menu_button
    ui->home_menu_groups_groups_menu_button = lv_imgbtn_create(ui->home_menu_groups);
    lv_obj_add_flag(ui->home_menu_groups_groups_menu_button, LV_OBJ_FLAG_CHECKABLE);
    lv_imgbtn_set_src(ui->home_menu_groups_groups_menu_button, LV_IMGBTN_STATE_RELEASED, NULL, &_groups_icon_alpha_100x100, NULL);
    lv_imgbtn_set_src(ui->home_menu_groups_groups_menu_button, LV_IMGBTN_STATE_PRESSED, NULL, &_groups_icon_alpha_100x100, NULL);
    lv_imgbtn_set_src(ui->home_menu_groups_groups_menu_button, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_groups_icon_alpha_100x100, NULL);
    lv_imgbtn_set_src(ui->home_menu_groups_groups_menu_button, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &_groups_icon_alpha_100x100, NULL);
    ui->home_menu_groups_groups_menu_button_label = lv_label_create(ui->home_menu_groups_groups_menu_button);
    lv_label_set_text(ui->home_menu_groups_groups_menu_button_label, "");
    lv_label_set_long_mode(ui->home_menu_groups_groups_menu_button_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->home_menu_groups_groups_menu_button_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->home_menu_groups_groups_menu_button, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->home_menu_groups_groups_menu_button, 70, 60);
    lv_obj_set_size(ui->home_menu_groups_groups_menu_button, 100, 100);
    lv_obj_add_flag(ui->home_menu_groups_groups_menu_button, LV_OBJ_FLAG_CLICKABLE);

    //Write style for home_menu_groups_groups_menu_button, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->home_menu_groups_groups_menu_button, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_menu_groups_groups_menu_button, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_menu_groups_groups_menu_button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_menu_groups_groups_menu_button, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_menu_groups_groups_menu_button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->home_menu_groups_groups_menu_button, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_menu_groups_groups_menu_button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for home_menu_groups_groups_menu_button, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->home_menu_groups_groups_menu_button, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->home_menu_groups_groups_menu_button, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->home_menu_groups_groups_menu_button, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->home_menu_groups_groups_menu_button, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->home_menu_groups_groups_menu_button, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->home_menu_groups_groups_menu_button, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for home_menu_groups_groups_menu_button, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->home_menu_groups_groups_menu_button, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->home_menu_groups_groups_menu_button, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->home_menu_groups_groups_menu_button, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->home_menu_groups_groups_menu_button, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->home_menu_groups_groups_menu_button, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->home_menu_groups_groups_menu_button, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for home_menu_groups_groups_menu_button, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->home_menu_groups_groups_menu_button, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->home_menu_groups_groups_menu_button, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes home_menu_groups_label_groups
    ui->home_menu_groups_label_groups = lv_label_create(ui->home_menu_groups);
    lv_label_set_text(ui->home_menu_groups_label_groups, "Groups");
    lv_label_set_long_mode(ui->home_menu_groups_label_groups, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->home_menu_groups_label_groups, 70, 170);
    lv_obj_set_size(ui->home_menu_groups_label_groups, 100, 32);

    //Write style for home_menu_groups_label_groups, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_menu_groups_label_groups, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_menu_groups_label_groups, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_menu_groups_label_groups, lv_color_hex(0x496ADE), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_menu_groups_label_groups, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_menu_groups_label_groups, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_menu_groups_label_groups, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_menu_groups_label_groups, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_menu_groups_label_groups, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_menu_groups_label_groups, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_menu_groups_label_groups, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_menu_groups_label_groups, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_menu_groups_label_groups, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_menu_groups_label_groups, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_menu_groups_label_groups, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of home_menu_groups.


    //Update current screen layout.
    lv_obj_update_layout(ui->home_menu_groups);

    //Init events for screen.
    events_init_home_menu_groups(ui);
}
