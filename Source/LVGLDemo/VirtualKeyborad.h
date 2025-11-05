#pragma once
#include "lvgl/lvgl.h"

struct VirtualKeyborad
{
	lv_obj_t* Handle;
	lv_obj_t* ButtonPrint;
	lv_obj_t* ButtonScroll;
	lv_obj_t* ButtonPause;
	lv_obj_t* ButtonInsert;
	lv_obj_t* ButtonHome;
	lv_obj_t* ButtonPageUp;
	lv_obj_t* ButtonPageDown;
	lv_obj_t* ButtonDelete;
	lv_obj_t* ButtonEnd;

	lv_obj_t* LabelPrint;
	lv_obj_t* LabelScroll;
	lv_obj_t* LabelPause;
	lv_obj_t* LabelInsert;
	lv_obj_t* LabelHome;
	lv_obj_t* LabelPageUp;
	lv_obj_t* LabelPageDown;
	lv_obj_t* LabelDelete;
	lv_obj_t* LabelEnd;
};
#ifdef __cplusplus
extern "C"
{
#endif
	struct VirtualKeyborad* CreateVirtualKeyborad(lv_obj_t* Parent);
#ifdef __cplusplus
}
#endif



