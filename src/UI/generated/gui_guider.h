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
	lv_obj_t *messages_list;
	bool messages_list_del;
	lv_obj_t *messages_list_cont_1;
	lv_obj_t *messages_list_img_contact_bar_Cornelia;
	lv_obj_t *messages_list_img_pfp_Cornelia;
	lv_obj_t *messages_list_label_name_Cornelia;
	lv_obj_t *messages_list_img_contact_bar_Maria;
	lv_obj_t *messages_list_img_pfp_Maria;
	lv_obj_t *messages_list_label_name_Maria;
	lv_obj_t *messages_list_img_contact_bar_Jake;
	lv_obj_t *messages_list_img_pfp_Jake;
	lv_obj_t *messages_list_label_name_Jake;
	lv_obj_t *messages_list_img_contact_bar_Adrian;
	lv_obj_t *messages_list_img_pfp_Adrian;
	lv_obj_t *messages_list_label_name_Adrian;
	lv_obj_t *messages_list_img_grey_top_bar;
	lv_obj_t *messages_list_label_messages_bar;
	lv_obj_t *messages_list_img_close;
	lv_obj_t *messages_convo_screen;
	bool messages_convo_screen_del;
	lv_obj_t *messages_convo_screen_img_top_grey_bar;
	lv_obj_t *messages_convo_screen_label_messages_bar;
	lv_obj_t *messages_convo_screen_img_close;
	lv_obj_t *messages_convo_screen_img_message_bar_bottom;
	lv_obj_t *messages_convo_screen_label_choose_emote;
	lv_obj_t *messages_emotes_send;
	bool messages_emotes_send_del;
	lv_obj_t *messages_emotes_send_cont_1;
	lv_obj_t *messages_emotes_send_emoji_party;
	lv_obj_t *messages_emotes_send_emoji_heart;
	lv_obj_t *messages_emotes_send_emoji_wave;
	lv_obj_t *messages_emotes_send_emoji_like;
	lv_obj_t *messages_emotes_send_img_top_grey_bar;
	lv_obj_t *messages_emotes_send_label_messages_bar;
	lv_obj_t *messages_emotes_send_img_close;
	lv_obj_t *home_menu_alert;
	bool home_menu_alert_del;
	lv_obj_t *home_menu_alert_alert_menu_button;
	lv_obj_t *home_menu_alert_alert_menu_button_label;
	lv_obj_t *home_menu_alert_label_alert;
	lv_obj_t *alert_menu;
	bool alert_menu_del;
	lv_obj_t *alert_menu_img_top_grey_bar;
	lv_obj_t *alert_menu_label_alert_bar;
	lv_obj_t *alert_menu_img_close;
	lv_obj_t *alert_menu_alert_button_descrition;
	lv_obj_t *alert_menu_alert_button;
	lv_obj_t *alert_menu_alert_button_label;
	lv_obj_t *home_menu_groups;
	bool home_menu_groups_del;
	lv_obj_t *home_menu_groups_groups_menu_button;
	lv_obj_t *home_menu_groups_groups_menu_button_label;
	lv_obj_t *home_menu_groups_label_groups;
	lv_obj_t *groups_list;
	bool groups_list_del;
	lv_obj_t *groups_list_cont_1;
	lv_obj_t *groups_list_img_group_bar_4;
	lv_obj_t *groups_list_img_group_4;
	lv_obj_t *groups_list_label_group_name_4;
	lv_obj_t *groups_list_img_group_bar_3;
	lv_obj_t *groups_list_img_group_3;
	lv_obj_t *groups_list_label_group_name_3;
	lv_obj_t *groups_list_img_group_bar_2;
	lv_obj_t *groups_list_img_group_2;
	lv_obj_t *groups_list_label_group_name_2;
	lv_obj_t *groups_list_img_group_bar_1;
	lv_obj_t *groups_list_img_group_1;
	lv_obj_t *groups_list_label_group_name_1;
	lv_obj_t *groups_list_img_top_grey_bar;
	lv_obj_t *groups_list_img_close;
	lv_obj_t *groups_list_label_groups_bar;
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
	lv_obj_t *groups_contacts_img_close;
	lv_obj_t *groups_contacts_label_groups_bar;
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
void setup_scr_messages_list(lv_ui *ui);
void setup_scr_messages_convo_screen(lv_ui *ui);
void setup_scr_messages_emotes_send(lv_ui *ui);
void setup_scr_home_menu_alert(lv_ui *ui);
void setup_scr_alert_menu(lv_ui *ui);
void setup_scr_home_menu_groups(lv_ui *ui);
void setup_scr_groups_list(lv_ui *ui);
void setup_scr_groups_contacts(lv_ui *ui);

LV_IMG_DECLARE(_homescreen_UI_240x240);
LV_IMG_DECLARE(_message_icon_alpha_100x100);
LV_IMG_DECLARE(_message_icon_alpha_100x100);
LV_IMG_DECLARE(_message_icon_alpha_100x100);
LV_IMG_DECLARE(_message_icon_alpha_100x100);
LV_IMG_DECLARE(_message_list_rectangle_alpha_200x50);
LV_IMG_DECLARE(_img_avatar_4_alpha_30x30);
LV_IMG_DECLARE(_message_list_rectangle_alpha_200x50);
LV_IMG_DECLARE(_img_avatar_2_alpha_30x30);
LV_IMG_DECLARE(_message_list_rectangle_alpha_200x50);
LV_IMG_DECLARE(_img_avatar_3_alpha_30x30);
LV_IMG_DECLARE(_message_list_rectangle_alpha_200x50);
LV_IMG_DECLARE(_img_avatar_1_alpha_30x30);
LV_IMG_DECLARE(_menu_bar_alpha_240x55);
LV_IMG_DECLARE(_close_icon_alpha_20x20);
LV_IMG_DECLARE(_menu_bar_alpha_240x55);
LV_IMG_DECLARE(_close_icon_alpha_20x20);
LV_IMG_DECLARE(_img_bg_2_alpha_209x30);
LV_IMG_DECLARE(_emoji_4_alpha_100x100);
LV_IMG_DECLARE(_emoji_3_alpha_100x100);
LV_IMG_DECLARE(_emoji_2_alpha_100x100);
LV_IMG_DECLARE(_emoji_1_alpha_100x100);
LV_IMG_DECLARE(_menu_bar_alpha_240x55);
LV_IMG_DECLARE(_close_icon_alpha_20x20);
LV_IMG_DECLARE(_alert_icon_alpha_100x100);
LV_IMG_DECLARE(_alert_icon_alpha_100x100);
LV_IMG_DECLARE(_alert_icon_alpha_100x100);
LV_IMG_DECLARE(_alert_icon_alpha_100x100);
LV_IMG_DECLARE(_menu_bar_alpha_240x55);
LV_IMG_DECLARE(_close_icon_alpha_20x20);
LV_IMG_DECLARE(_alert_icon_alpha_90x90);
LV_IMG_DECLARE(_alert_icon_alpha_90x90);
LV_IMG_DECLARE(_alert_icon_alpha_90x90);
LV_IMG_DECLARE(_alert_icon_alpha_90x90);
LV_IMG_DECLARE(_groups_icon_alpha_100x100);
LV_IMG_DECLARE(_groups_icon_alpha_100x100);
LV_IMG_DECLARE(_groups_icon_alpha_100x100);
LV_IMG_DECLARE(_groups_icon_alpha_100x100);
LV_IMG_DECLARE(_message_list_rectangle_alpha_200x50);
LV_IMG_DECLARE(_img_avatar_4_alpha_30x30);
LV_IMG_DECLARE(_message_list_rectangle_alpha_200x50);
LV_IMG_DECLARE(_img_avatar_2_alpha_30x30);
LV_IMG_DECLARE(_message_list_rectangle_alpha_200x50);
LV_IMG_DECLARE(_img_avatar_3_alpha_30x30);
LV_IMG_DECLARE(_message_list_rectangle_alpha_200x50);
LV_IMG_DECLARE(_img_avatar_1_alpha_30x30);
LV_IMG_DECLARE(_menu_bar_alpha_240x55);
LV_IMG_DECLARE(_close_icon_alpha_20x20);
LV_IMG_DECLARE(_message_list_rectangle_alpha_200x50);
LV_IMG_DECLARE(_img_avatar_4_alpha_30x30);
LV_IMG_DECLARE(_message_list_rectangle_alpha_200x50);
LV_IMG_DECLARE(_img_avatar_2_alpha_30x30);
LV_IMG_DECLARE(_message_list_rectangle_alpha_200x50);
LV_IMG_DECLARE(_img_avatar_3_alpha_30x30);
LV_IMG_DECLARE(_message_list_rectangle_alpha_200x50);
LV_IMG_DECLARE(_img_avatar_1_alpha_30x30);
LV_IMG_DECLARE(_menu_bar_alpha_240x55);
LV_IMG_DECLARE(_close_icon_alpha_20x20);

LV_FONT_DECLARE(lv_font_montserratMedium_13)
LV_FONT_DECLARE(lv_font_montserratMedium_10)
LV_FONT_DECLARE(lv_font_montserratMedium_45)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_montserratMedium_19)
LV_FONT_DECLARE(lv_font_montserratMedium_21)


#ifdef __cplusplus
}
#endif
#endif
