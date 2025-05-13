/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"

#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif

#include "../../common.h" // Added by Kacper (KSCB)


static void home_digital_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_TOP:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.home_menu_messages, guider_ui.home_menu_messages_del, &guider_ui.home_digital_del, setup_scr_home_menu_messages, LV_SCR_LOAD_ANIM_OVER_TOP, 200, 200, false, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

void events_init_home_digital (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->home_digital, home_digital_event_handler, LV_EVENT_ALL, ui);
}

static void home_menu_messages_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_BOTTOM:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.home_digital, guider_ui.home_digital_del, &guider_ui.home_menu_messages_del, setup_scr_home_digital, LV_SCR_LOAD_ANIM_OVER_BOTTOM, 200, 200, false, true);
            break;
        }
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.home_menu_alert, guider_ui.home_menu_alert_del, &guider_ui.home_menu_messages_del, setup_scr_home_menu_alert, LV_SCR_LOAD_ANIM_OVER_LEFT, 200, 200, false, true);
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.home_menu_groups, guider_ui.home_menu_groups_del, &guider_ui.home_menu_messages_del, setup_scr_home_menu_groups, LV_SCR_LOAD_ANIM_OVER_RIGHT, 200, 200, false, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void home_menu_messages_messages_menu_button_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.messages_list, guider_ui.messages_list_del, &guider_ui.home_menu_messages_del, setup_scr_messages_list, LV_SCR_LOAD_ANIM_MOVE_LEFT, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_home_menu_messages (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->home_menu_messages, home_menu_messages_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->home_menu_messages_messages_menu_button, home_menu_messages_messages_menu_button_event_handler, LV_EVENT_ALL, ui);
}

static void messages_list_cont_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCROLL:
    {
        break;
    }
    default:
        break;
    }
}

static void messages_list_img_contact_bar_Cornelia_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.messages_emoji_send_v2, guider_ui.messages_emoji_send_v2_del, &guider_ui.messages_list_del, setup_scr_messages_emoji_send_v2, LV_SCR_LOAD_ANIM_OVER_LEFT, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void messages_list_img_contact_bar_Maria_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.messages_emoji_send_v2, guider_ui.messages_emoji_send_v2_del, &guider_ui.messages_list_del, setup_scr_messages_emoji_send_v2, LV_SCR_LOAD_ANIM_OVER_LEFT, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void messages_list_img_contact_bar_Jake_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.messages_emoji_send_v2, guider_ui.messages_emoji_send_v2_del, &guider_ui.messages_list_del, setup_scr_messages_emoji_send_v2, LV_SCR_LOAD_ANIM_OVER_LEFT, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void messages_list_img_contact_bar_Adrian_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.messages_emoji_send_v2, guider_ui.messages_emoji_send_v2_del, &guider_ui.messages_list_del, setup_scr_messages_emoji_send_v2, LV_SCR_LOAD_ANIM_OVER_LEFT, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void messages_list_img_close_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home_menu_messages, guider_ui.home_menu_messages_del, &guider_ui.messages_list_del, setup_scr_home_menu_messages, LV_SCR_LOAD_ANIM_OVER_RIGHT, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_messages_list (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->messages_list_cont_1, messages_list_cont_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->messages_list_img_contact_bar_Cornelia, messages_list_img_contact_bar_Cornelia_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->messages_list_img_contact_bar_Maria, messages_list_img_contact_bar_Maria_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->messages_list_img_contact_bar_Jake, messages_list_img_contact_bar_Jake_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->messages_list_img_contact_bar_Adrian, messages_list_img_contact_bar_Adrian_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->messages_list_img_close, messages_list_img_close_event_handler, LV_EVENT_ALL, ui);
}

static void messages_emoji_send_v2_emoji_party_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {

        break;
    }
    default:
        break;
    }
}

static void messages_emoji_send_v2_emoji_heart_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {

        break;
    }
    default:
        break;
    }
}

static void messages_emoji_send_v2_emoji_wave_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {

        break;
    }
    default:
        break;
    }
}

static void messages_emoji_send_v2_emoji_like_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {

        break;
    }
    default:
        break;
    }
}

static void messages_emoji_send_v2_img_close_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.messages_list, guider_ui.messages_list_del, &guider_ui.messages_emoji_send_v2_del, setup_scr_messages_list, LV_SCR_LOAD_ANIM_OVER_RIGHT, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_messages_emoji_send_v2 (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->messages_emoji_send_v2_emoji_party, messages_emoji_send_v2_emoji_party_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->messages_emoji_send_v2_emoji_heart, messages_emoji_send_v2_emoji_heart_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->messages_emoji_send_v2_emoji_wave, messages_emoji_send_v2_emoji_wave_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->messages_emoji_send_v2_emoji_like, messages_emoji_send_v2_emoji_like_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->messages_emoji_send_v2_img_close, messages_emoji_send_v2_img_close_event_handler, LV_EVENT_ALL, ui);
}

static void home_menu_alert_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_BOTTOM:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.home_digital, guider_ui.home_digital_del, &guider_ui.home_menu_alert_del, setup_scr_home_digital, LV_SCR_LOAD_ANIM_OVER_BOTTOM, 200, 200, false, true);
            break;
        }
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.home_menu_groups, guider_ui.home_menu_groups_del, &guider_ui.home_menu_alert_del, setup_scr_home_menu_groups, LV_SCR_LOAD_ANIM_OVER_LEFT, 200, 200, false, true);
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.home_menu_messages, guider_ui.home_menu_messages_del, &guider_ui.home_menu_alert_del, setup_scr_home_menu_messages, LV_SCR_LOAD_ANIM_OVER_RIGHT, 200, 200, false, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void home_menu_alert_alert_menu_button_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.alert_menu, guider_ui.alert_menu_del, &guider_ui.home_menu_alert_del, setup_scr_alert_menu, LV_SCR_LOAD_ANIM_MOVE_LEFT, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_home_menu_alert (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->home_menu_alert, home_menu_alert_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->home_menu_alert_alert_menu_button, home_menu_alert_alert_menu_button_event_handler, LV_EVENT_ALL, ui);
}

static void alert_menu_alert_button_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        common_sendMessage(8);
        break;
    }
    default:
        break;
    }
}

static void alert_menu_img_close_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home_menu_alert, guider_ui.home_menu_alert_del, &guider_ui.alert_menu_del, setup_scr_home_menu_alert, LV_SCR_LOAD_ANIM_OVER_RIGHT, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_alert_menu (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->alert_menu_alert_button, alert_menu_alert_button_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->alert_menu_img_close, alert_menu_img_close_event_handler, LV_EVENT_ALL, ui);
}

static void home_menu_groups_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_BOTTOM:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.home_digital, guider_ui.home_digital_del, &guider_ui.home_menu_groups_del, setup_scr_home_digital, LV_SCR_LOAD_ANIM_OVER_BOTTOM, 200, 200, false, true);
            break;
        }
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.home_menu_messages, guider_ui.home_menu_messages_del, &guider_ui.home_menu_groups_del, setup_scr_home_menu_messages, LV_SCR_LOAD_ANIM_OVER_LEFT, 200, 200, false, true);
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.home_menu_alert, guider_ui.home_menu_alert_del, &guider_ui.home_menu_groups_del, setup_scr_home_menu_alert, LV_SCR_LOAD_ANIM_OVER_RIGHT, 200, 200, false, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void home_menu_groups_groups_menu_button_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.groups_list, guider_ui.groups_list_del, &guider_ui.home_menu_groups_del, setup_scr_groups_list, LV_SCR_LOAD_ANIM_MOVE_LEFT, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_home_menu_groups (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->home_menu_groups, home_menu_groups_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->home_menu_groups_groups_menu_button, home_menu_groups_groups_menu_button_event_handler, LV_EVENT_ALL, ui);
}

static void groups_list_cont_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCROLL:
    {
        break;
    }
    default:
        break;
    }
}

static void groups_list_img_group_bar_4_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.groups_contacts, guider_ui.groups_contacts_del, &guider_ui.groups_list_del, setup_scr_groups_contacts, LV_SCR_LOAD_ANIM_OVER_LEFT, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void groups_list_img_group_bar_3_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.groups_contacts, guider_ui.groups_contacts_del, &guider_ui.groups_list_del, setup_scr_groups_contacts, LV_SCR_LOAD_ANIM_OVER_LEFT, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void groups_list_img_group_bar_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.groups_contacts, guider_ui.groups_contacts_del, &guider_ui.groups_list_del, setup_scr_groups_contacts, LV_SCR_LOAD_ANIM_OVER_LEFT, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void groups_list_img_group_bar_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.groups_contacts, guider_ui.groups_contacts_del, &guider_ui.groups_list_del, setup_scr_groups_contacts, LV_SCR_LOAD_ANIM_OVER_LEFT, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void groups_list_img_close_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home_menu_groups, guider_ui.home_menu_groups_del, &guider_ui.groups_list_del, setup_scr_home_menu_groups, LV_SCR_LOAD_ANIM_OVER_RIGHT, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_groups_list (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->groups_list_cont_1, groups_list_cont_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->groups_list_img_group_bar_4, groups_list_img_group_bar_4_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->groups_list_img_group_bar_3, groups_list_img_group_bar_3_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->groups_list_img_group_bar_2, groups_list_img_group_bar_2_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->groups_list_img_group_bar_1, groups_list_img_group_bar_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->groups_list_img_close, groups_list_img_close_event_handler, LV_EVENT_ALL, ui);
}

static void groups_contacts_cont_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCROLL:
    {
        break;
    }
    default:
        break;
    }
}

static void groups_contacts_img_close_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.groups_list, guider_ui.groups_list_del, &guider_ui.groups_contacts_del, setup_scr_groups_list, LV_SCR_LOAD_ANIM_OVER_RIGHT, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_groups_contacts (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->groups_contacts_cont_1, groups_contacts_cont_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->groups_contacts_img_close, groups_contacts_img_close_event_handler, LV_EVENT_ALL, ui);
}


void events_init(lv_ui *ui)
{

}
