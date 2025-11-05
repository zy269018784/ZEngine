#pragma once
#include "lvgl/lvgl.h"
#include "ThemeSetting.h"
#include "WallpaperSetting.h"
#include "TimeSetting.h"
#include "UpgradeSetting.h"
#include "OtherSetting.h"
#include "DockSetting.h"
struct Settings
{
	lv_obj_t* ButtonTheme;
	lv_obj_t* LabelTheme;
	struct ThemeSetting* ThemeSubPage;

	lv_obj_t* ButtonWallpaper;
	lv_obj_t* LabelWallpaper;
	struct WallpaperSetting* WallpaperSubPage;

	lv_obj_t* ButtonDock;
	lv_obj_t* LabelDock;
	struct DockSetting* DockSubPage;

	lv_obj_t* ButtonTime;
	lv_obj_t* LabelTime;
	struct TimeSetting* TimeSubPage;

	lv_obj_t* ButtonOtherSetting;
	lv_obj_t* LabelOtherSetting;
	struct OtherSetting* OtherSettingSubPage;

	lv_obj_t* ButtonUpgradeSetting;
	lv_obj_t* LabelUpgradeSetting;
	struct UpgradeSetting* UpgradeSettingSubPage;
};
#ifdef __cplusplus
extern "C"
{
#endif
	struct Settings* CreateSettings(lv_obj_t* Parent);
#ifdef __cplusplus
}
#endif