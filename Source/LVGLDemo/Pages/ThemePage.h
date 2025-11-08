#pragma once
#include <lvgl/lvgl.h>
#include "LVGLDemo/Point2.h"

typedef struct ThemePage
{
	lv_obj_t* Parent;
	lv_obj_t* Handle;
	/*
		控件
			上一曲按钮
			下一曲按钮
			播放按钮
			进度条
	*/
	lv_obj_t* prev_button;
	lv_obj_t* next_button;
	lv_obj_t* play_button;

	lv_obj_t* music_name_label;
	Point2    music_name_label_size;
	Point2    music_name_label_pos;

	lv_obj_t* singer_name_label;
	Point2    singer_name_label_size;
	Point2    singer_name_label_pos;	

	lv_obj_t* progress_bar;
	Point2    progress_bar_size;
	Point2    progress_bar_pos;
}ThemePage;

#ifdef __cplusplus
extern "C"
{
#endif
	void CreateThemePage(ThemePage* Page, lv_obj_t* Parent);
#ifdef __cplusplus
}
#endif