#pragma once
#include "lvgl/lvgl.h"

struct OtherSetting
{
	lv_obj_t* Handle;
	lv_obj_t* LabelScreenAlwaysOn;
	lv_obj_t* SwitchScreenAlwaysOn;
	lv_obj_t* LabelScreenTimeout;
	lv_obj_t* PopupScreenTimeout;

	lv_obj_t* ButtonFactoryReset;
	lv_obj_t* LabelFactoryReset;
};
#ifdef __cplusplus
extern "C"
{
#endif
	struct OtherSetting* CreateOtherSetting(lv_obj_t* Parent);
#ifdef __cplusplus
}
#endif