#pragma once
#include "lvgl/lvgl.h"

struct UpgradeSetting
{
	lv_obj_t* Handle;

	lv_obj_t* CurrentVersion;
	lv_obj_t* CurrentVersion_2;

	lv_obj_t* Pause;
	lv_obj_t* LabelPause;
};
#ifdef __cplusplus
extern "C"
{
#endif
	struct UpgradeSetting* CreateUpgradeSetting(lv_obj_t* Parent);
#ifdef __cplusplus
}
#endif