#include "Widget.h"


lv_obj_t* CreateLabel(lv_obj_t* Parent, int32_t x, int32_t y, int32_t w, int32_t h, const char* text, lv_color_t bgvalue)
{
	lv_obj_t* Handle = NULL;

    Handle = lv_label_create(Parent);
    /*
        设置位置和尺寸
    */
    lv_obj_set_pos(Handle, x, y);
    lv_obj_set_size(Handle, w, h);
    lv_label_set_text_static(Handle, text);
    /*
        设置盒子模型
    */
    lv_obj_set_style_pad_all(Handle, 0, 0);
    lv_obj_set_style_border_width(Handle, 0, 0);
    lv_obj_set_style_margin_all(Handle, 0, 0);
    /*
      设置背景颜色
    */
    lv_obj_set_style_bg_color(Handle, bgvalue, 0);
    /*
        设置radius
    */
    lv_obj_set_style_radius(Handle, 0, 0);
    /*
        关闭滚动条
    */
    lv_obj_clear_flag(Handle, LV_OBJ_FLAG_SCROLLABLE);

	return Handle;
}