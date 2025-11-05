#pragma once
#include <lvgl/lvgl.h>
#include "Point2.h"

typedef struct MusicPage
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
	lv_obj_t* progress_bar;
}MusicPage;

#ifdef __cplusplus
extern "C"
{
#endif
	void CreateMusicPage(MusicPage* Page, lv_obj_t* Parent);
#ifdef __cplusplus
}
#endif