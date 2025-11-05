#include "Settings.h"

struct Settings* CreateSettings(lv_obj_t* Parent)
{
	struct Settings* Handle = (struct Settings*)malloc(sizeof(struct Settings));

	/*
		Theme Setting
	*/
	Handle->ButtonTheme = lv_button_create(Parent);
	lv_obj_set_pos(Handle->ButtonTheme, 0,   0);

	Handle->LabelTheme = lv_label_create(Handle->ButtonTheme);
	lv_label_set_text_static(Handle->LabelTheme, "Theme");

	//Handle->ThemeSubPage = CreateThemeSetting(Parent);
	//lv_obj_add_flag(Handle->ThemeSubPage->Handle, LV_OBJ_FLAG_HIDDEN);

	/*
		壁纸
	*/
	Handle->ButtonWallpaper = lv_button_create(Parent);
	lv_obj_set_pos(Handle->ButtonWallpaper, 0,   100);

	Handle->LabelWallpaper = lv_label_create(Handle->ButtonWallpaper);
	lv_label_set_text_static(Handle->LabelWallpaper, "Wallpaper");

	Handle->WallpaperSubPage = CreateWallpaperSetting(Parent);
	lv_obj_clear_flag(Handle->WallpaperSubPage->Handle, LV_OBJ_FLAG_HIDDEN);


	/*
		Dock
	*/
	Handle->ButtonDock = lv_button_create(Parent);
	lv_obj_set_pos(Handle->ButtonDock, 0, 200);

	Handle->LabelDock = lv_label_create(Handle->ButtonDock);
	lv_label_set_text_static(Handle->LabelDock, "Dock Setting");

	Handle->DockSubPage = CreateDockSetting(Parent);
	lv_obj_add_flag(Handle->DockSubPage->Handle, LV_OBJ_FLAG_HIDDEN);


	/*
		Time
	*/
	Handle->ButtonTime = lv_button_create(Parent);
	lv_obj_set_pos(Handle->ButtonTime, 0, 300);

	Handle->LabelTime = lv_label_create(Handle->ButtonTime);
	lv_label_set_text_static(Handle->LabelTime, "Time Setting");

	Handle->TimeSubPage = CreateTimeSetting(Parent);
	lv_obj_add_flag(Handle->TimeSubPage->Handle, LV_OBJ_FLAG_HIDDEN);

	/*
		Other
	*/
	Handle->ButtonOtherSetting = lv_button_create(Parent);
	lv_obj_set_pos(Handle->ButtonOtherSetting, 0, 400);

	Handle->LabelOtherSetting = lv_label_create(Handle->ButtonOtherSetting);
	lv_label_set_text_static(Handle->LabelOtherSetting, "Other Setting");

	Handle->OtherSettingSubPage = CreateOtherSetting(Parent);
	lv_obj_add_flag(Handle->OtherSettingSubPage->Handle, LV_OBJ_FLAG_HIDDEN);

	/*
		Upgrade
	*/
	Handle->ButtonUpgradeSetting = lv_button_create(Parent);
	lv_obj_set_pos(Handle->ButtonUpgradeSetting, 0, 500);

	Handle->LabelUpgradeSetting = lv_label_create(Handle->ButtonUpgradeSetting);
	lv_label_set_text_static(Handle->LabelUpgradeSetting, "Upgrade Setting");

	Handle->UpgradeSettingSubPage = CreateUpgradeSetting(Parent);
	lv_obj_add_flag(Handle->UpgradeSettingSubPage->Handle, LV_OBJ_FLAG_HIDDEN);

	return Handle;
}
