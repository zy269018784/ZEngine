#pragma once
#include <lvgl/lvgl.h>
#include "LVGLDemo/Point2.h"

typedef struct SystemInfoPage
{
	lv_obj_t* Parent;
	lv_obj_t* Handle;

	lv_obj_t* CPUUsage;
	lv_obj_t* CPUTemp;
	lv_obj_t* CPUFreq;
	lv_obj_t* MemUsage;
	lv_obj_t* UpSpeed;
	lv_obj_t* DownSpeed;

	lv_obj_t* CPUUsage_2;
	lv_obj_t* CPUTemp_2;
	lv_obj_t* CPUFreq_2;
	lv_obj_t* MemUsage_2;
	lv_obj_t* UpSpeed_2;
	lv_obj_t* DownSpeed_2;				
}SystemInfoPage;

#ifdef __cplusplus
extern "C"
{
#endif
	void CreateSystemInfoPage(SystemInfoPage* Page, lv_obj_t* Parent);
#ifdef __cplusplus
}
#endif