#pragma once
#include <lvgl/lvgl.h>
#include <lvgl/src/drivers/lv_drivers.h>
#include <lvgl/src/drivers/windows/lv_windows_display.h>
#include "Pages/ClockPage.h"
#include "Pages/MusicPage.h"
#include "Pages/SystemInfoPage.h"
#include "Pages/ThemePage.h"

#include "Point2.h"

typedef struct Theme
{
	/*
		main_font_color		字体主要颜色
		sub_font_color		字体辅助颜色
		main_color			主要颜色
		sub_color			辅助颜色
		focused_color		选中颜色
	*/
	lv_color_t main_font_color;
	lv_color_t sub_font_color;
	lv_color_t main_color;
	lv_color_t sub_color;
	lv_color_t focused_color;
}Theme;



#define HomePageNum 1
#define MusicPageNum 2
#define ClockPageNum 3
#define SystemInfoPageNum 4
#define SettingPageNum 5

typedef struct Application
{
	lv_display_t* Display;

	lv_obj_t* RowLayout;
	lv_obj_t* ButtonHomePage;
	lv_obj_t* ButtonMusic;
	lv_obj_t* ButtonClock;
	lv_obj_t* ButtonSystemInfo;
	lv_obj_t* ButtonSetting;

	Theme CurrentTheme;
	ThemePage PageTheme;
	SystemInfoPage PageSystemInfo;
	ClockPage PageClock;
	MusicPage PageMusic;
	int CurrentPage;
}Application;


#ifdef __cplusplus
extern "C"
{
#endif
	Application* CreateApplication();
	void ShowPage(Application* App, int index);
	void Run(struct Application* App);
#ifdef __cplusplus
}
#endif