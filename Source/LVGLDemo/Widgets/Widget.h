#pragma once
#include <lvgl/lvgl.h>

lv_obj_t* CreateBase(lv_obj_t* Parent, int32_t x, int32_t y, int32_t w, int32_t h,  lv_color_t bgvalue);
lv_obj_t* CreateLabel(lv_obj_t* Parent, int32_t x, int32_t y, int32_t w, int32_t h, const char* text, lv_color_t bgvalue);
lv_obj_t* CreateButton(lv_obj_t* Parent, int32_t x, int32_t y, int32_t w, int32_t h, lv_color_t bgvalue);