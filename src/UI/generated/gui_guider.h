/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct
{
  
	lv_obj_t *home_digital;
	bool home_digital_del;
	lv_obj_t *home_digital_label_week;
	lv_obj_t *home_digital_label_date;
	lv_obj_t *home_digital_label_time;
	lv_obj_t *home_menu_messages;
	bool home_menu_messages_del;
	lv_obj_t *home_menu_messages_messages_menu_button;
	lv_obj_t *home_menu_messages_messages_menu_button_label;
	lv_obj_t *home_menu_messages_label_messages;
	lv_obj_t *home_menu_messages_img_2;
	lv_obj_t *home_menu_messages_img_3;
	lv_obj_t *home_menu_alert;
	bool home_menu_alert_del;
	lv_obj_t *home_menu_alert_alert_menu_button;
	lv_obj_t *home_menu_alert_alert_menu_button_label;
	lv_obj_t *home_menu_alert_label_alert;
	lv_obj_t *home_menu_alert_img_1;
	lv_obj_t *home_menu_alert_img_2;
	lv_obj_t *home_menu_groups;
	bool home_menu_groups_del;
	lv_obj_t *home_menu_groups_groups_menu_button;
	lv_obj_t *home_menu_groups_groups_menu_button_label;
	lv_obj_t *home_menu_groups_label_groups;
	lv_obj_t *home_menu_groups_img_1;
	lv_obj_t *home_menu_groups_img_2;
	lv_obj_t *messages_emoji_send_v2;
	bool messages_emoji_send_v2_del;
	lv_obj_t *messages_emoji_send_v2_img_top_grey_bar;
	lv_obj_t *messages_emoji_send_v2_label_messages_bar;
	lv_obj_t *messages_emoji_send_v2_img_close;
	lv_obj_t *messages_emoji_send_v2_cont_1;
	lv_obj_t *messages_emoji_send_v2_emoji_party;
	lv_obj_t *messages_emoji_send_v2_emoji_heart;
	lv_obj_t *messages_emoji_send_v2_emoji_wave;
	lv_obj_t *messages_emoji_send_v2_emoji_like;
	lv_obj_t *messages_send_successful;
	bool messages_send_successful_del;
	lv_obj_t *messages_send_successful_img_top_grey_bar;
	lv_obj_t *messages_send_successful_img_close;
	lv_obj_t *messages_send_successful_label_messages_bar;
	lv_obj_t *messages_send_successful_label_message_info_send;
	lv_obj_t *messages_send_failed;
	bool messages_send_failed_del;
	lv_obj_t *messages_send_failed_img_top_grey_bar;
	lv_obj_t *messages_send_failed_img_close;
	lv_obj_t *messages_send_failed_label_messages_bar;
	lv_obj_t *messages_send_failed_label_message_info_send;
	lv_obj_t *message_received_like;
	bool message_received_like_del;
	lv_obj_t *message_received_like_img_top_grey_bar;
	lv_obj_t *message_received_like_img_close;
	lv_obj_t *message_received_like_label_messages_bar;
	lv_obj_t *message_received_like_label_message_received;
	lv_obj_t *message_received_like_emoji_like;
	lv_obj_t *message_received_wave;
	bool message_received_wave_del;
	lv_obj_t *message_received_wave_img_top_grey_bar;
	lv_obj_t *message_received_wave_img_close;
	lv_obj_t *message_received_wave_label_messages_bar;
	lv_obj_t *message_received_wave_label_message_received;
	lv_obj_t *message_received_wave_emoji_wave;
	lv_obj_t *message_received_heart;
	bool message_received_heart_del;
	lv_obj_t *message_received_heart_img_top_grey_bar;
	lv_obj_t *message_received_heart_img_close;
	lv_obj_t *message_received_heart_label_messages_bar;
	lv_obj_t *message_received_heart_label_message_received;
	lv_obj_t *message_received_heart_emoji_heart;
	lv_obj_t *message_received_party;
	bool message_received_party_del;
	lv_obj_t *message_received_party_img_top_grey_bar;
	lv_obj_t *message_received_party_img_close;
	lv_obj_t *message_received_party_label_messages_bar;
	lv_obj_t *message_received_party_label_message_received;
	lv_obj_t *message_received_party_emoji_party;
	lv_obj_t *alert_menu;
	bool alert_menu_del;
	lv_obj_t *alert_menu_img_top_grey_bar;
	lv_obj_t *alert_menu_label_alert_bar;
	lv_obj_t *alert_menu_alert_button_descrition;
	lv_obj_t *alert_menu_alert_button;
	lv_obj_t *alert_menu_alert_button_label;
	lv_obj_t *alert_menu_img_close;
	lv_obj_t *groups_list;
	bool groups_list_del;
	lv_obj_t *groups_list_cont_groups_scroll;
	lv_obj_t *groups_list_cont_gr_1;
	lv_obj_t *groups_list_img_group_bar_1;
	lv_obj_t *groups_list_img_group_1;
	lv_obj_t *groups_list_label_group_1;
	lv_obj_t *groups_list_cont_gr_2;
	lv_obj_t *groups_list_img_group_bar_2;
	lv_obj_t *groups_list_img_group_2;
	lv_obj_t *groups_list_label_group_2;
	lv_obj_t *groups_list_cont_gr_3;
	lv_obj_t *groups_list_img_group_bar_3;
	lv_obj_t *groups_list_img_group_3;
	lv_obj_t *groups_list_label_group_3;
	lv_obj_t *groups_list_cont_gr_4;
	lv_obj_t *groups_list_img_group_bar_4;
	lv_obj_t *groups_list_img_group_4;
	lv_obj_t *groups_list_label_group_4;
	lv_obj_t *groups_list_cont_gr_6;
	lv_obj_t *groups_list_img_group_bar_6;
	lv_obj_t *groups_list_img_group_6;
	lv_obj_t *groups_list_label_group_6;
	lv_obj_t *groups_list_cont_gr_8;
	lv_obj_t *groups_list_img_group_bar_8;
	lv_obj_t *groups_list_img_group_8;
	lv_obj_t *groups_list_label_group_8;
	lv_obj_t *groups_list_cont_gr_7;
	lv_obj_t *groups_list_img_group_bar_7;
	lv_obj_t *groups_list_img_group_7;
	lv_obj_t *groups_list_label_group_7;
	lv_obj_t *groups_list_cont_gr_5;
	lv_obj_t *groups_list_img_group_bar_5;
	lv_obj_t *groups_list_img_group_5;
	lv_obj_t *groups_list_label_group_5;
	lv_obj_t *groups_list_cont_gr_10;
	lv_obj_t *groups_list_img_group_bar_10;
	lv_obj_t *groups_list_img_group_10;
	lv_obj_t *groups_list_label_group_10;
	lv_obj_t *groups_list_cont_gr_9;
	lv_obj_t *groups_list_img_group_bar_9;
	lv_obj_t *groups_list_img_group_9;
	lv_obj_t *groups_list_label_group_9;
	lv_obj_t *groups_list_img_top_grey_bar;
	lv_obj_t *groups_list_label_groups_bar;
	lv_obj_t *groups_list_img_close;
	lv_obj_t *groups_contacts;
	bool groups_contacts_del;
	lv_obj_t *groups_contacts_cont_1;
	lv_obj_t *groups_contacts_img_contact_bar_4;
	lv_obj_t *groups_contacts_img_pfp_4;
	lv_obj_t *groups_contacts_label_name_4;
	lv_obj_t *groups_contacts_img_contact_bar_3;
	lv_obj_t *groups_contacts_img_pfp_3;
	lv_obj_t *groups_contacts_label_name_3;
	lv_obj_t *groups_contacts_img_contact_bar_2;
	lv_obj_t *groups_contacts_img_pfp_2;
	lv_obj_t *groups_contacts_label_name_2;
	lv_obj_t *groups_contacts_img_contact_bar_1;
	lv_obj_t *groups_contacts_img_pfp_1;
	lv_obj_t *groups_contacts_label_name_1;
	lv_obj_t *groups_contacts_img_top_grey_bar;
	lv_obj_t *groups_contacts_label_groups_bar;
	lv_obj_t *groups_contacts_img_close;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_animation(void * var, int32_t duration, int32_t delay, int32_t start_value, int32_t end_value, lv_anim_path_cb_t path_cb,
                       uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                       lv_anim_exec_xcb_t exec_cb, lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);


void init_scr_del_flag(lv_ui *ui);

void setup_ui(lv_ui *ui);

void init_keyboard(lv_ui *ui);

extern lv_ui guider_ui;


void setup_scr_home_digital(lv_ui *ui);
void setup_scr_home_menu_messages(lv_ui *ui);
void setup_scr_home_menu_alert(lv_ui *ui);
void setup_scr_home_menu_groups(lv_ui *ui);
void setup_scr_messages_emoji_send_v2(lv_ui *ui);
void setup_scr_messages_send_successful(lv_ui *ui);
void setup_scr_messages_send_failed(lv_ui *ui);
void setup_scr_message_received_like(lv_ui *ui);
void setup_scr_message_received_wave(lv_ui *ui);
void setup_scr_message_received_heart(lv_ui *ui);
void setup_scr_message_received_party(lv_ui *ui);
void setup_scr_alert_menu(lv_ui *ui);
void setup_scr_groups_list(lv_ui *ui);
void setup_scr_groups_contacts(lv_ui *ui);

LV_IMG_DECLARE(_homescreen_UI_240x240);
LV_IMG_DECLARE(_message_icon_alpha_100x100);
LV_IMG_DECLARE(_message_icon_alpha_100x100);
LV_IMG_DECLARE(_message_icon_alpha_100x100);
LV_IMG_DECLARE(_message_icon_alpha_100x100);
LV_IMG_DECLARE(_three_dot_icon1321_alpha_50x50);
LV_IMG_DECLARE(_three_dot_icon13214214214_alpha_49x17);
LV_IMG_DECLARE(_alert_icon_alpha_100x100);
LV_IMG_DECLARE(_alert_icon_alpha_100x100);
LV_IMG_DECLARE(_alert_icon_alpha_100x100);
LV_IMG_DECLARE(_alert_icon_alpha_100x100);
LV_IMG_DECLARE(_three_dot_icon13214214214_alpha_46x16);
LV_IMG_DECLARE(_three_dot_icon1321_alpha_50x50);
LV_IMG_DECLARE(_groups_icon_alpha_100x100);
LV_IMG_DECLARE(_groups_icon_alpha_100x100);
LV_IMG_DECLARE(_groups_icon_alpha_100x100);
LV_IMG_DECLARE(_groups_icon_alpha_100x100);
LV_IMG_DECLARE(_three_dot_icon1321_alpha_50x50);
LV_IMG_DECLARE(_three_dot_icon13214214214_alpha_49x17);
LV_IMG_DECLARE(_menu_bar_alpha_240x55);
LV_IMG_DECLARE(_x_thin_alpha_40x40);
LV_IMG_DECLARE(_emoji_4_alpha_80x80);
LV_IMG_DECLARE(_emoji_3_alpha_80x80);
LV_IMG_DECLARE(_emoji_2_alpha_80x80);
LV_IMG_DECLARE(_emoji_1_alpha_80x80);
LV_IMG_DECLARE(_menu_bar_alpha_240x55);
LV_IMG_DECLARE(_x_thin_alpha_40x40);
LV_IMG_DECLARE(_menu_bar_alpha_240x55);
LV_IMG_DECLARE(_x_thin_alpha_40x40);
LV_IMG_DECLARE(_menu_bar_alpha_240x55);
LV_IMG_DECLARE(_x_thin_alpha_40x40);
LV_IMG_DECLARE(_emoji_1_alpha_80x80);
LV_IMG_DECLARE(_menu_bar_alpha_240x55);
LV_IMG_DECLARE(_x_thin_alpha_40x40);
LV_IMG_DECLARE(_emoji_2_alpha_80x80);
LV_IMG_DECLARE(_menu_bar_alpha_240x55);
LV_IMG_DECLARE(_x_thin_alpha_40x40);
LV_IMG_DECLARE(_emoji_3_alpha_80x80);
LV_IMG_DECLARE(_menu_bar_alpha_240x55);
LV_IMG_DECLARE(_x_thin_alpha_40x40);
LV_IMG_DECLARE(_emoji_4_alpha_80x80);
LV_IMG_DECLARE(_menu_bar_alpha_240x55);
LV_IMG_DECLARE(_alert_icon_alpha_90x90);
LV_IMG_DECLARE(_alert_icon_alpha_90x90);
LV_IMG_DECLARE(_alert_icon_alpha_90x90);
LV_IMG_DECLARE(_alert_icon_alpha_90x90);
LV_IMG_DECLARE(_x_thin_alpha_40x40);
LV_IMG_DECLARE(_message_list_rectangle_alpha_200x50);
LV_IMG_DECLARE(_img_avatar_1_alpha_30x30);
LV_IMG_DECLARE(_message_list_rectangle_alpha_200x50);
LV_IMG_DECLARE(_img_avatar_1_alpha_30x30);
LV_IMG_DECLARE(_message_list_rectangle_alpha_200x50);
LV_IMG_DECLARE(_img_avatar_1_alpha_30x30);
LV_IMG_DECLARE(_message_list_rectangle_alpha_200x50);
LV_IMG_DECLARE(_img_avatar_1_alpha_30x30);
LV_IMG_DECLARE(_message_list_rectangle_alpha_200x50);
LV_IMG_DECLARE(_img_avatar_1_alpha_30x30);
LV_IMG_DECLARE(_message_list_rectangle_alpha_200x50);
LV_IMG_DECLARE(_img_avatar_1_alpha_30x30);
LV_IMG_DECLARE(_message_list_rectangle_alpha_200x50);
LV_IMG_DECLARE(_img_avatar_1_alpha_30x30);
LV_IMG_DECLARE(_message_list_rectangle_alpha_200x50);
LV_IMG_DECLARE(_img_avatar_1_alpha_30x30);
LV_IMG_DECLARE(_message_list_rectangle_alpha_200x50);
LV_IMG_DECLARE(_img_avatar_1_alpha_30x30);
LV_IMG_DECLARE(_message_list_rectangle_alpha_200x50);
LV_IMG_DECLARE(_img_avatar_1_alpha_30x30);
LV_IMG_DECLARE(_menu_bar_alpha_240x55);
LV_IMG_DECLARE(_x_thin_alpha_40x40);
LV_IMG_DECLARE(_message_list_rectangle_alpha_200x50);
LV_IMG_DECLARE(_img_avatar_4_alpha_30x30);
LV_IMG_DECLARE(_message_list_rectangle_alpha_200x50);
LV_IMG_DECLARE(_img_avatar_2_alpha_30x30);
LV_IMG_DECLARE(_message_list_rectangle_alpha_200x50);
LV_IMG_DECLARE(_img_avatar_3_alpha_30x30);
LV_IMG_DECLARE(_message_list_rectangle_alpha_200x50);
LV_IMG_DECLARE(_img_avatar_1_alpha_30x30);
LV_IMG_DECLARE(_menu_bar_alpha_240x55);
LV_IMG_DECLARE(_x_thin_alpha_40x40);

LV_FONT_DECLARE(lv_font_montserratMedium_13)
LV_FONT_DECLARE(lv_font_montserratMedium_10)
LV_FONT_DECLARE(lv_font_montserratMedium_45)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_montserratMedium_21)
LV_FONT_DECLARE(lv_font_montserratMedium_19)


#ifdef __cplusplus
}
#endif
#endif
