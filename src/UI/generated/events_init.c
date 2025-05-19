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

lv_ui guider_ui;
extern lv_ui guider_ui;

static void home_digital_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_TOP:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.home_messages, guider_ui.home_messages_del, &guider_ui.home_digital_del, setup_scr_home_messages, LV_SCR_LOAD_ANIM_OVER_TOP, 200, 200, false, true);
            break;
        }
        case LV_DIR_BOTTOM:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.home_menu_groups, guider_ui.home_menu_groups_del, &guider_ui.home_digital_del, setup_scr_home_menu_groups, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
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

static void home_digital_img_4_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.digital_settings, guider_ui.digital_settings_del, &guider_ui.home_digital_del, setup_scr_digital_settings, LV_SCR_LOAD_ANIM_MOVE_LEFT, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_home_digital (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->home_digital, home_digital_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->home_digital_img_4, home_digital_img_4_event_handler, LV_EVENT_ALL, ui);
}

static void digital_settings_img_close_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home_digital, guider_ui.home_digital_del, &guider_ui.digital_settings_del, setup_scr_home_digital, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_digital_settings (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->digital_settings_img_close, digital_settings_img_close_event_handler, LV_EVENT_ALL, ui);
}

static void home_messages_event_handler (lv_event_t *e)
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
            ui_load_scr_animation(&guider_ui, &guider_ui.home_digital, guider_ui.home_digital_del, &guider_ui.home_messages_del, setup_scr_home_digital, LV_SCR_LOAD_ANIM_OVER_BOTTOM, 200, 200, false, true);
            break;
        }
        case LV_DIR_TOP:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.home_menu_alert, guider_ui.home_menu_alert_del, &guider_ui.home_messages_del, setup_scr_home_menu_alert, LV_SCR_LOAD_ANIM_OVER_TOP, 200, 200, false, true);
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

static void home_messages_messages_menu_button_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.messages_emoji_send_v2, guider_ui.messages_emoji_send_v2_del, &guider_ui.home_messages_del, setup_scr_messages_emoji_send_v2, LV_SCR_LOAD_ANIM_MOVE_LEFT, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_home_messages (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->home_messages, home_messages_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->home_messages_messages_menu_button, home_messages_messages_menu_button_event_handler, LV_EVENT_ALL, ui);
}

static void messages_emoji_send_v2_img_close_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home_messages, guider_ui.home_messages_del, &guider_ui.messages_emoji_send_v2_del, setup_scr_home_messages, LV_SCR_LOAD_ANIM_OVER_RIGHT, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void messages_emoji_send_v2_emoji_party_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {

        ui_load_scr_animation(&guider_ui, &guider_ui.messages_send_successful, guider_ui.messages_send_successful_del, &guider_ui.messages_emoji_send_v2_del, setup_scr_messages_send_successful, LV_SCR_LOAD_ANIM_OVER_LEFT, 200, 200, false, true);
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

        ui_load_scr_animation(&guider_ui, &guider_ui.messages_send_successful, guider_ui.messages_send_successful_del, &guider_ui.messages_emoji_send_v2_del, setup_scr_messages_send_successful, LV_SCR_LOAD_ANIM_OVER_LEFT, 200, 200, false, true);
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

        ui_load_scr_animation(&guider_ui, &guider_ui.messages_send_successful, guider_ui.messages_send_successful_del, &guider_ui.messages_emoji_send_v2_del, setup_scr_messages_send_successful, LV_SCR_LOAD_ANIM_OVER_LEFT, 200, 200, false, true);
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

        ui_load_scr_animation(&guider_ui, &guider_ui.messages_send_successful, guider_ui.messages_send_successful_del, &guider_ui.messages_emoji_send_v2_del, setup_scr_messages_send_successful, LV_SCR_LOAD_ANIM_OVER_LEFT, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_messages_emoji_send_v2 (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->messages_emoji_send_v2_img_close, messages_emoji_send_v2_img_close_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->messages_emoji_send_v2_emoji_party, messages_emoji_send_v2_emoji_party_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->messages_emoji_send_v2_emoji_heart, messages_emoji_send_v2_emoji_heart_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->messages_emoji_send_v2_emoji_wave, messages_emoji_send_v2_emoji_wave_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->messages_emoji_send_v2_emoji_like, messages_emoji_send_v2_emoji_like_event_handler, LV_EVENT_ALL, ui);
}

static void message_received_like_img_close_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home_digital, guider_ui.home_digital_del, &guider_ui.message_received_like_del, setup_scr_home_digital, LV_SCR_LOAD_ANIM_OVER_BOTTOM, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_message_received_like (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->message_received_like_img_close, message_received_like_img_close_event_handler, LV_EVENT_ALL, ui);
}

static void message_received_wave_img_close_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home_digital, guider_ui.home_digital_del, &guider_ui.message_received_wave_del, setup_scr_home_digital, LV_SCR_LOAD_ANIM_OVER_BOTTOM, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_message_received_wave (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->message_received_wave_img_close, message_received_wave_img_close_event_handler, LV_EVENT_ALL, ui);
}

static void message_received_heart_img_close_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home_digital, guider_ui.home_digital_del, &guider_ui.message_received_heart_del, setup_scr_home_digital, LV_SCR_LOAD_ANIM_OVER_BOTTOM, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_message_received_heart (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->message_received_heart_img_close, message_received_heart_img_close_event_handler, LV_EVENT_ALL, ui);
}

static void message_received_party_img_close_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home_digital, guider_ui.home_digital_del, &guider_ui.message_received_party_del, setup_scr_home_digital, LV_SCR_LOAD_ANIM_OVER_BOTTOM, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_message_received_party (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->message_received_party_img_close, message_received_party_img_close_event_handler, LV_EVENT_ALL, ui);
}

static void messages_send_failed_img_close_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.messages_emoji_send_v2, guider_ui.messages_emoji_send_v2_del, &guider_ui.messages_send_failed_del, setup_scr_messages_emoji_send_v2, LV_SCR_LOAD_ANIM_OVER_RIGHT, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_messages_send_failed (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->messages_send_failed_img_close, messages_send_failed_img_close_event_handler, LV_EVENT_ALL, ui);
}

static void messages_send_successful_img_close_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.messages_emoji_send_v2, guider_ui.messages_emoji_send_v2_del, &guider_ui.messages_send_successful_del, setup_scr_messages_emoji_send_v2, LV_SCR_LOAD_ANIM_OVER_RIGHT, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_messages_send_successful (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->messages_send_successful_img_close, messages_send_successful_img_close_event_handler, LV_EVENT_ALL, ui);
}

static void home_menu_alert_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_TOP:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.home_menu_groups, guider_ui.home_menu_groups_del, &guider_ui.home_menu_alert_del, setup_scr_home_menu_groups, LV_SCR_LOAD_ANIM_OVER_TOP, 200, 200, false, true);
            break;
        }
        case LV_DIR_BOTTOM:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.home_messages, guider_ui.home_messages_del, &guider_ui.home_menu_alert_del, setup_scr_home_messages, LV_SCR_LOAD_ANIM_OVER_BOTTOM, 200, 200, false, true);
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
            ui_load_scr_animation(&guider_ui, &guider_ui.home_menu_alert, guider_ui.home_menu_alert_del, &guider_ui.home_menu_groups_del, setup_scr_home_menu_alert, LV_SCR_LOAD_ANIM_OVER_BOTTOM, 200, 200, false, true);
            break;
        }
        case LV_DIR_TOP:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.home_digital, guider_ui.home_digital_del, &guider_ui.home_menu_groups_del, setup_scr_home_digital, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
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

static void groups_list_cont_groups_scroll_event_handler (lv_event_t *e)
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

static void groups_list_cont_gr_1_event_handler (lv_event_t *e)
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

static void groups_list_cont_gr_2_event_handler (lv_event_t *e)
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

static void groups_list_cont_gr_3_event_handler (lv_event_t *e)
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

static void groups_list_cont_gr_4_event_handler (lv_event_t *e)
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

static void groups_list_cont_gr_6_event_handler (lv_event_t *e)
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

static void groups_list_img_group_bar_6_event_handler (lv_event_t *e)
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

static void groups_list_cont_gr_8_event_handler (lv_event_t *e)
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

static void groups_list_img_group_bar_8_event_handler (lv_event_t *e)
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

static void groups_list_cont_gr_7_event_handler (lv_event_t *e)
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

static void groups_list_img_group_bar_7_event_handler (lv_event_t *e)
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

static void groups_list_cont_gr_5_event_handler (lv_event_t *e)
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

static void groups_list_img_group_bar_5_event_handler (lv_event_t *e)
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

static void groups_list_cont_gr_10_event_handler (lv_event_t *e)
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

static void groups_list_img_group_bar_10_event_handler (lv_event_t *e)
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

static void groups_list_cont_gr_9_event_handler (lv_event_t *e)
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

static void groups_list_img_group_bar_9_event_handler (lv_event_t *e)
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
    lv_obj_add_event_cb(ui->groups_list_cont_groups_scroll, groups_list_cont_groups_scroll_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->groups_list_cont_gr_1, groups_list_cont_gr_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->groups_list_img_group_bar_1, groups_list_img_group_bar_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->groups_list_cont_gr_2, groups_list_cont_gr_2_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->groups_list_img_group_bar_2, groups_list_img_group_bar_2_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->groups_list_cont_gr_3, groups_list_cont_gr_3_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->groups_list_img_group_bar_3, groups_list_img_group_bar_3_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->groups_list_cont_gr_4, groups_list_cont_gr_4_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->groups_list_img_group_bar_4, groups_list_img_group_bar_4_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->groups_list_cont_gr_6, groups_list_cont_gr_6_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->groups_list_img_group_bar_6, groups_list_img_group_bar_6_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->groups_list_cont_gr_8, groups_list_cont_gr_8_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->groups_list_img_group_bar_8, groups_list_img_group_bar_8_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->groups_list_cont_gr_7, groups_list_cont_gr_7_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->groups_list_img_group_bar_7, groups_list_img_group_bar_7_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->groups_list_cont_gr_5, groups_list_cont_gr_5_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->groups_list_img_group_bar_5, groups_list_img_group_bar_5_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->groups_list_cont_gr_10, groups_list_cont_gr_10_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->groups_list_img_group_bar_10, groups_list_img_group_bar_10_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->groups_list_cont_gr_9, groups_list_cont_gr_9_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->groups_list_img_group_bar_9, groups_list_img_group_bar_9_event_handler, LV_EVENT_ALL, ui);
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
