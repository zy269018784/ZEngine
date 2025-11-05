#pragma once
#include "lvgl/lvgl.h"

struct MusicController
{
	lv_obj_t* MusicName;
	lv_obj_t* MusicName_2;

	lv_obj_t* SingerName;
	lv_obj_t* SingerName_2;

	lv_obj_t* AlbumName;
	lv_obj_t* AlbumName_2;

	lv_obj_t* Duration;
	lv_obj_t* Duration_2;

	lv_obj_t* ProgressBar;
	lv_obj_t* ProgressBar_2;

	lv_obj_t* Pause;
	lv_obj_t* LabelPause;
};
#ifdef __cplusplus
extern "C"
{
#endif
	struct MusicController* CreateMusicController(lv_obj_t* Parent);
#ifdef __cplusplus
}
#endif