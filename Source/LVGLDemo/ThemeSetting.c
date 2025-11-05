//#include "ThemeSetting.h"
//
//struct ThemeSetting* CreateThemeSetting(lv_obj_t* Parent)
//{
//	struct ThemeSetting* Page = (struct ThemeSetting*)malloc(sizeof(struct ThemeSetting));
//
//	lv_color_t color = { 255, 255, 255 };
//
//	Page->Handle = lv_obj_create(Parent);
//	lv_obj_set_size(Page->Handle, LV_PCT(100) - 200, LV_PCT(100)); // 全屏
//	lv_obj_set_style_border_width(Page->Handle, 0, 0);       // 无边框
//	lv_obj_set_style_radius(Page->Handle, 0, 0);             // 无圆角
//	lv_obj_set_style_bg_color(Page->Handle, color, 0); // 背景色
//	lv_obj_set_pos(Page->Handle, 200, 0);
//
//
//	Page->themes[0] = CreateTheme(Page->Handle, "theme1", 0,     0, 200, 400, NULL);
//	Page->themes[1] = CreateTheme(Page->Handle, "theme2", 300,   0, 200, 400, NULL);
//	Page->themes[2] = CreateTheme(Page->Handle, "theme3", 600,   0, 200, 400, NULL);
//	Page->themes[3] = CreateTheme(Page->Handle, "theme4", 900,   0, 200, 400, NULL);
//	Page->themes[4] = CreateTheme(Page->Handle, "theme5", 0,   500, 200, 400, NULL);
//	Page->themes[5] = CreateTheme(Page->Handle, "theme6", 300, 500, 200, 400, NULL);
//	Page->themes[6] = CreateTheme(Page->Handle, "theme7", 600, 500, 200, 400, NULL);
//	Page->themes[7] = CreateTheme(Page->Handle, "theme8", 900, 500, 200, 400, NULL);
//	return Page;
//}
//
//struct Theme* CreateTheme(lv_obj_t* Parent, const char *Title, int X, int Y,int W, int H, void* Pixels)
//{
//	struct Theme* Page = (struct Theme*)malloc(sizeof(struct Theme));
//
//	Page->Handle = lv_obj_create(Parent);
//	lv_obj_set_pos(Page->Handle, X, Y);
//	lv_obj_set_size(Page->Handle, W, H); 
//	lv_obj_set_style_border_width(Page->Handle, 1, 0);       // 无边框
//	lv_obj_set_style_radius(Page->Handle, 0, 0);             // 无圆角
//	lv_obj_set_style_bg_color(Page->Handle, lv_color_white(), 0); // 背景色
//	
//	Page->LabelThemeTitle = lv_label_create(Page->Handle);
//	lv_label_set_text_static(Page->LabelThemeTitle, Title);
//	lv_obj_set_pos(Page->LabelThemeTitle,  0, 0);
//	lv_obj_set_size(Page->LabelThemeTitle, W - 20, 100);
//
//	//Page->ImageTheme = lv_image_create(Page->Handle);
//	//lv_label_set_text_static(Page->ImageTheme, Title);
//	//lv_obj_set_pos(Page->ImageTheme,  0, 100);
//	//lv_obj_set_size(Page->ImageTheme, W, H - 100);
//
//	return Page;
//}