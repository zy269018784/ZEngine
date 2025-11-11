#pragma once
#include <lvgl/lvgl.h>
#include "LVGLDemo/Point2.h"
#include "ThemePage.h"
#include "WallpapperPage.h"

#define SettingHomePageNum 0
#define ThemePageNum 1
#define WallpaperPageNum 2


typedef struct SettingsPage
{
	lv_obj_t* Parent;

	lv_obj_t* Handle;
	lv_obj_t* HomePageHandle;
	lv_obj_t* SubPageHandle;

	lv_obj_t* ButtonWallpapper;
	lv_obj_t* ButtonTheme;
	lv_obj_t* ButtonDock;
	lv_obj_t* ButtonClock;
	lv_obj_t* ButtonOther;
	lv_obj_t* ButtonUpdate;

	lv_obj_t* LabelWallpapper;
	lv_obj_t* LabelTheme;
	lv_obj_t* LabelDock;
	lv_obj_t* LabelClock;
	lv_obj_t* LabelOther;
	lv_obj_t* LabelUpdate;



	ThemePage ThemeSettingPage;
	WallpapperPage WallpapperSettingPage;
}SettingsPage;

#ifdef __cplusplus
extern "C"
{
#endif
	void CreateSettingsPage(SettingsPage* Page, lv_obj_t* Parent);
	void ShowSettingPage(SettingsPage* Page, int PageNo);
#ifdef __cplusplus
}
#endif