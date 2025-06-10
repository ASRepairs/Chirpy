SET(SOURCES screens/ui_MainScreen.c
    screens/ui_AvatarScreen.c
    screens/ui_GroupsScreen.c
    screens/ui_MessagesMenu.c
    screens/ui_EmergencyMenu.c
    screens/ui_AvatarMenu.c
    screens/ui_GroupsMenu.c
    screens/ui_PhoneConnectScreen.c
    screens/ui_PhoneQRMenu.c
    screens/ui_NotificationScreen.c
    screens/ui_Images.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    ui_events.c
    images/ui_img_ui_png.c
    images/ui_img_froggy_png.c
    images/ui_img_avatar_png.c
    images/ui_img_groups_png.c
    images/ui_img_messagepanel_png.c
    images/ui_img_checkmark_png.c
    images/ui_img_emojismsg_png.c
    images/ui_img_emergency_png.c
    images/ui_img_whitepanel_png.c
    images/ui_img_profiles_png.c
    images/ui_img_phoneconnect_png.c
    images/ui_img_celebrationemoji_png.c
    images/ui_img_waveemoji_png.c
    images/ui_img_likeemoji_png.c
    images/ui_img_heartemoji_png.c
    images/ui_img_piggy_png.c
    images/ui_img_horsy_png.c
    images/ui_img_pandy_png.c
    images/ui_img_emergencyemoji_png.c)

add_library(ui ${SOURCES})
