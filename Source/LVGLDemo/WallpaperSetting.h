#pragma once
#include "lvgl/lvgl.h"

struct WallpaperSetting
{
	lv_obj_t* Handle;
	struct Wallpaper* themes[10];
};

struct Wallpaper
{
	lv_obj_t* Handle;
	lv_obj_t* LabelWallpaperTitle;
	lv_obj_t* ImageWallpaper;
};

#ifdef __cplusplus
extern "C"
{
#endif
	struct WallpaperSetting* CreateWallpaperSetting(lv_obj_t* Parent);
	struct Wallpaper* CreateWallpaper(lv_obj_t* Parent, const char* Title, int X, int Y, int W, int H, void* Pixels);

#ifdef __cplusplus
}
#endif

