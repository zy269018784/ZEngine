#include "WallpaperSetting.h"

struct WallpaperSetting* CreateWallpaperSetting(lv_obj_t* Parent)
{
	struct WallpaperSetting* Page = (struct WallpaperSetting*)malloc(sizeof(struct WallpaperSetting));

	lv_color_t color = { 255, 255, 255 };

	Page->Handle = lv_obj_create(Parent);
	lv_obj_set_size(Page->Handle, LV_PCT(100) - 200, LV_PCT(100)); // 全屏
	lv_obj_set_style_border_width(Page->Handle, 0, 0);       // 无边框
	lv_obj_set_style_radius(Page->Handle, 0, 0);             // 无圆角
	lv_obj_set_style_bg_color(Page->Handle, color, 0); // 背景色
	lv_obj_set_pos(Page->Handle, 200, 0);


	Page->themes[0] = CreateWallpaper(Page->Handle, "wallpaper1", 0, 0, 200, 400, NULL);
	Page->themes[1] = CreateWallpaper(Page->Handle, "wallpaper2", 300, 0, 200, 400, NULL);
	Page->themes[2] = CreateWallpaper(Page->Handle, "wallpaper3", 600, 0, 200, 400, NULL);
	Page->themes[3] = CreateWallpaper(Page->Handle, "wallpaper4", 900, 0, 200, 400, NULL);
	Page->themes[4] = CreateWallpaper(Page->Handle, "wallpaper5", 0, 500, 200, 400, NULL);
	Page->themes[5] = CreateWallpaper(Page->Handle, "wallpaper6", 300, 500, 200, 400, NULL);
	Page->themes[6] = CreateWallpaper(Page->Handle, "wallpaper7", 600, 500, 200, 400, NULL);
	Page->themes[7] = CreateWallpaper(Page->Handle, "wallpaper8", 900, 500, 200, 400, NULL);
	return Page;
}

struct Wallpaper* CreateWallpaper(lv_obj_t* Parent, const char* Title, int X, int Y, int W, int H, void* Pixels)
{
	struct Wallpaper* Page = (struct Wallpaper*)malloc(sizeof(struct Wallpaper));

	Page->Handle = lv_obj_create(Parent);
	lv_obj_set_pos(Page->Handle, X, Y);
	lv_obj_set_size(Page->Handle, W, H);
	lv_obj_set_style_border_width(Page->Handle, 1, 0);       // 无边框
	lv_obj_set_style_radius(Page->Handle, 0, 0);             // 无圆角
	lv_obj_set_style_bg_color(Page->Handle, lv_color_white(), 0); // 背景色

	Page->LabelWallpaperTitle = lv_label_create(Page->Handle);
	lv_label_set_text_static(Page->LabelWallpaperTitle, Title);
	lv_obj_set_pos(Page->LabelWallpaperTitle, 0, 0);
	lv_obj_set_size(Page->LabelWallpaperTitle, W - 20, 100);

	//Page->ImageWallpaper = lv_image_create(Page->Handle);
	//lv_label_set_text_static(Page->ImageWallpaper, Title);
	//lv_obj_set_pos(Page->ImageWallpaper,  0, 100);
	//lv_obj_set_size(Page->ImageWallpaper, W, H - 100);

	return Page;
}