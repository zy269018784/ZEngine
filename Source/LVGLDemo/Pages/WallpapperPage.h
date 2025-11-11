#pragma once
#include <lvgl/lvgl.h>
#include "LVGLDemo/Point2.h"

typedef struct WallpapperPage
{
	lv_obj_t* Parent;
	lv_obj_t* Handle;
}WallpapperPage;

#ifdef __cplusplus
extern "C"
{
#endif
	void CreateWallpapperPage(WallpapperPage* Page, lv_obj_t* Parent);
#ifdef __cplusplus
}
#endif