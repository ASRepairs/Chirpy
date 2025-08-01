// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.5.2
// LVGL version: 8.3.11
// Project name: ChirpyUI

#include "../ui.h"

lv_obj_t * uic_EmergencyEmojiImg;
lv_obj_t * uic_KittyImg;
lv_obj_t * uic_PuppyImg;
lv_obj_t * uic_LizzyImg;
lv_obj_t * uic_PhoenyImg;
lv_obj_t * uic_PandyImg;
lv_obj_t * uic_HorsyImg;
lv_obj_t * uic_PiggyImg;
lv_obj_t * uic_FroggyImg;
lv_obj_t * uic_CelebrateEmojiImg;
lv_obj_t * uic_HeartEmojiImg;
lv_obj_t * uic_LikeEmojiImg;
lv_obj_t * uic_WaveEmojiImg;
lv_obj_t * uic_Images;
lv_obj_t * ui_Images;
lv_obj_t * ui_WaveEmojiImg;
lv_obj_t * ui_LikeEmojiImg;
lv_obj_t * ui_HeartEmojiImg;
lv_obj_t * ui_CelebrateEmojiImg;
lv_obj_t * ui_FroggyImg;
lv_obj_t * ui_PiggyImg;
lv_obj_t * ui_HorsyImg;
lv_obj_t * ui_PandyImg;
lv_obj_t * ui_PhoenyImg;
lv_obj_t * ui_LizzyImg;
lv_obj_t * ui_PuppyImg;
lv_obj_t * ui_KittyImg;
lv_obj_t * ui_EmergencyEmojiImg;

// event funtions

// build funtions

void ui_Images_screen_init(void)
{
    ui_Images = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Images, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_WaveEmojiImg = lv_img_create(ui_Images);
    lv_img_set_src(ui_WaveEmojiImg, &ui_img_waveemoji_png);
    lv_obj_set_width(ui_WaveEmojiImg, LV_SIZE_CONTENT);   /// 90
    lv_obj_set_height(ui_WaveEmojiImg, LV_SIZE_CONTENT);    /// 90
    lv_obj_set_align(ui_WaveEmojiImg, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_WaveEmojiImg, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_WaveEmojiImg, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_LikeEmojiImg = lv_img_create(ui_Images);
    lv_img_set_src(ui_LikeEmojiImg, &ui_img_likeemoji_png);
    lv_obj_set_width(ui_LikeEmojiImg, LV_SIZE_CONTENT);   /// 90
    lv_obj_set_height(ui_LikeEmojiImg, LV_SIZE_CONTENT);    /// 90
    lv_obj_set_align(ui_LikeEmojiImg, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_LikeEmojiImg, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_LikeEmojiImg, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_HeartEmojiImg = lv_img_create(ui_Images);
    lv_img_set_src(ui_HeartEmojiImg, &ui_img_heartemoji_png);
    lv_obj_set_width(ui_HeartEmojiImg, LV_SIZE_CONTENT);   /// 90
    lv_obj_set_height(ui_HeartEmojiImg, LV_SIZE_CONTENT);    /// 90
    lv_obj_set_align(ui_HeartEmojiImg, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_HeartEmojiImg, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_HeartEmojiImg, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_CelebrateEmojiImg = lv_img_create(ui_Images);
    lv_img_set_src(ui_CelebrateEmojiImg, &ui_img_celebrationemoji_png);
    lv_obj_set_width(ui_CelebrateEmojiImg, LV_SIZE_CONTENT);   /// 90
    lv_obj_set_height(ui_CelebrateEmojiImg, LV_SIZE_CONTENT);    /// 90
    lv_obj_set_align(ui_CelebrateEmojiImg, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_CelebrateEmojiImg, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_CelebrateEmojiImg, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_FroggyImg = lv_img_create(ui_Images);
    lv_img_set_src(ui_FroggyImg, &ui_img_froggy_png);
    lv_obj_set_width(ui_FroggyImg, LV_SIZE_CONTENT);   /// 64
    lv_obj_set_height(ui_FroggyImg, LV_SIZE_CONTENT);    /// 64
    lv_obj_set_align(ui_FroggyImg, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_FroggyImg, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_FroggyImg, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_PiggyImg = lv_img_create(ui_Images);
    lv_img_set_src(ui_PiggyImg, &ui_img_piggy_png);
    lv_obj_set_width(ui_PiggyImg, LV_SIZE_CONTENT);   /// 64
    lv_obj_set_height(ui_PiggyImg, LV_SIZE_CONTENT);    /// 64
    lv_obj_set_align(ui_PiggyImg, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_PiggyImg, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_PiggyImg, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_HorsyImg = lv_img_create(ui_Images);
    lv_img_set_src(ui_HorsyImg, &ui_img_horsy_png);
    lv_obj_set_width(ui_HorsyImg, LV_SIZE_CONTENT);   /// 64
    lv_obj_set_height(ui_HorsyImg, LV_SIZE_CONTENT);    /// 64
    lv_obj_set_align(ui_HorsyImg, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_HorsyImg, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_HorsyImg, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_PandyImg = lv_img_create(ui_Images);
    lv_img_set_src(ui_PandyImg, &ui_img_pandy_png);
    lv_obj_set_width(ui_PandyImg, LV_SIZE_CONTENT);   /// 64
    lv_obj_set_height(ui_PandyImg, LV_SIZE_CONTENT);    /// 64
    lv_obj_set_align(ui_PandyImg, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_PandyImg, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_PandyImg, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_PhoenyImg = lv_img_create(ui_Images);
    lv_img_set_src(ui_PhoenyImg, &ui_img_phoeny_png);
    lv_obj_set_width(ui_PhoenyImg, LV_SIZE_CONTENT);   /// 64
    lv_obj_set_height(ui_PhoenyImg, LV_SIZE_CONTENT);    /// 64
    lv_obj_set_align(ui_PhoenyImg, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_PhoenyImg, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_PhoenyImg, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_LizzyImg = lv_img_create(ui_Images);
    lv_img_set_src(ui_LizzyImg, &ui_img_lizzy_png);
    lv_obj_set_width(ui_LizzyImg, LV_SIZE_CONTENT);   /// 64
    lv_obj_set_height(ui_LizzyImg, LV_SIZE_CONTENT);    /// 64
    lv_obj_set_align(ui_LizzyImg, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_LizzyImg, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_LizzyImg, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_PuppyImg = lv_img_create(ui_Images);
    lv_img_set_src(ui_PuppyImg, &ui_img_puppy_png);
    lv_obj_set_width(ui_PuppyImg, LV_SIZE_CONTENT);   /// 64
    lv_obj_set_height(ui_PuppyImg, LV_SIZE_CONTENT);    /// 64
    lv_obj_set_align(ui_PuppyImg, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_PuppyImg, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_PuppyImg, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_KittyImg = lv_img_create(ui_Images);
    lv_img_set_src(ui_KittyImg, &ui_img_kitty_png);
    lv_obj_set_width(ui_KittyImg, LV_SIZE_CONTENT);   /// 64
    lv_obj_set_height(ui_KittyImg, LV_SIZE_CONTENT);    /// 64
    lv_obj_set_align(ui_KittyImg, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_KittyImg, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_KittyImg, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_EmergencyEmojiImg = lv_img_create(ui_Images);
    lv_img_set_src(ui_EmergencyEmojiImg, &ui_img_emergencyemoji_png);
    lv_obj_set_width(ui_EmergencyEmojiImg, LV_SIZE_CONTENT);   /// 90
    lv_obj_set_height(ui_EmergencyEmojiImg, LV_SIZE_CONTENT);    /// 90
    lv_obj_set_align(ui_EmergencyEmojiImg, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_EmergencyEmojiImg, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_EmergencyEmojiImg, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    uic_Images = ui_Images;
    uic_WaveEmojiImg = ui_WaveEmojiImg;
    uic_LikeEmojiImg = ui_LikeEmojiImg;
    uic_HeartEmojiImg = ui_HeartEmojiImg;
    uic_CelebrateEmojiImg = ui_CelebrateEmojiImg;
    uic_FroggyImg = ui_FroggyImg;
    uic_PiggyImg = ui_PiggyImg;
    uic_HorsyImg = ui_HorsyImg;
    uic_PandyImg = ui_PandyImg;
    uic_PhoenyImg = ui_PhoenyImg;
    uic_LizzyImg = ui_LizzyImg;
    uic_PuppyImg = ui_PuppyImg;
    uic_KittyImg = ui_KittyImg;
    uic_EmergencyEmojiImg = ui_EmergencyEmojiImg;

}

void ui_Images_screen_destroy(void)
{
    if(ui_Images) lv_obj_del(ui_Images);

    // NULL screen variables
    uic_Images = NULL;
    ui_Images = NULL;
    uic_WaveEmojiImg = NULL;
    ui_WaveEmojiImg = NULL;
    uic_LikeEmojiImg = NULL;
    ui_LikeEmojiImg = NULL;
    uic_HeartEmojiImg = NULL;
    ui_HeartEmojiImg = NULL;
    uic_CelebrateEmojiImg = NULL;
    ui_CelebrateEmojiImg = NULL;
    uic_FroggyImg = NULL;
    ui_FroggyImg = NULL;
    uic_PiggyImg = NULL;
    ui_PiggyImg = NULL;
    uic_HorsyImg = NULL;
    ui_HorsyImg = NULL;
    uic_PandyImg = NULL;
    ui_PandyImg = NULL;
    uic_PhoenyImg = NULL;
    ui_PhoenyImg = NULL;
    uic_LizzyImg = NULL;
    ui_LizzyImg = NULL;
    uic_PuppyImg = NULL;
    ui_PuppyImg = NULL;
    uic_KittyImg = NULL;
    ui_KittyImg = NULL;
    uic_EmergencyEmojiImg = NULL;
    ui_EmergencyEmojiImg = NULL;

}
