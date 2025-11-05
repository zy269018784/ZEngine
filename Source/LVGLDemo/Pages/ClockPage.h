#pragma once
#include <lvgl/lvgl.h>
#include "LVGLDemo/Point2.h"
typedef struct ClockPage
{
	lv_obj_t* Parent;
	lv_obj_t* Handle;
	/*
		时间到了显示这个页面
	*/
	lv_obj_t* TimeUpPageHandle;
	/*
		timer_mode_circle / horizontal		调节时间是圆环还是横向
		timer_start_button_size				番茄时钟界面的开始按钮的尺寸
		timer_start_button_postion			番茄时钟界面的开始按钮的位置
		timer_stop_button_size				番茄时钟界面的停止按钮的尺寸
		timer_stop_button_postion			番茄时钟界面的停止按钮的位置
		timer_back_button_size				番茄时钟界面的返回按钮的尺寸
		timer_back_button_postion			番茄时钟界面的返回按钮的位置

	*/


	/*
		开始按钮
	*/
	Point2 timer_start_button_size;
	Point2 timer_start_button_postion;
	lv_obj_t* start_button;
	lv_obj_t* start_button_label;
	/*
		结束按钮
	*/
	Point2 timer_stop_button_size;
	Point2 timer_stop_button_postion;
	lv_obj_t* stop_button;
	lv_obj_t* stop_button_label;

	/*
		设置时间
		setting_time_button_label			初始时, Parent为Handle.		计时结束时, Parent为Handle.
		timer_setting_time_font_size		番茄时钟界面的设置时间的尺寸
		timer_setting_time_font_postion		番茄时钟界面的设置时间的位置

	*/
	Point2 timer_setting_time_font_size;
	Point2 timer_setting_time_font_postion;

	lv_obj_t* setting_time_button_label;
	/*
		Page 1
	*/

	/*
		Page2 : Time up
	*/
	/*
		返回按钮
	*/
	Point2 timer_back_button_size;
	Point2 timer_back_button_postion;
	lv_obj_t* back_button;
	lv_obj_t* back_button_label;
	/*
		timer_end_time_font_size			番茄时钟界面的结束时间的尺寸
		timer_end_time_font_postion			番茄时钟界面的结束时间的位置
	*/
	Point2 timer_end_time_font_size;
	Point2 timer_end_time_font_postion;
	lv_obj_t* time_end_label;
}ClockPage;


#ifdef __cplusplus
extern "C"
{
#endif
	void CreateClockPage(ClockPage* Page, lv_obj_t* Parent);
	void CreateClockPageTimeUp(ClockPage* Page, lv_obj_t* Parent);
	void ClockTimeUpState(ClockPage* Page);
	void ClockDefaultState(ClockPage* Page);
	void ClockStartState(ClockPage* Page);
#ifdef __cplusplus
}
#endif