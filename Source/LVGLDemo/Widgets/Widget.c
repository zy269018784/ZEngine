#include "Widget.h"

lv_obj_t* CreateBase(lv_obj_t* Parent, int32_t x, int32_t y, int32_t w, int32_t h, lv_color_t bgvalue)
{
    lv_obj_t* Handle = NULL;

    Handle = lv_obj_create(Parent);
    /*
        设置位置和尺寸
    */
    lv_obj_set_size(Handle, w, h); // 全屏
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

lv_obj_t* CreateButton(lv_obj_t* Parent, int32_t x, int32_t y, int32_t w, int32_t h, lv_color_t bgvalue)
{
    lv_obj_t* Handle = NULL;

    Handle = lv_button_create(Parent);
    /*
        设置位置和尺寸
    */
    lv_obj_set_pos(Handle, x, y);
    lv_obj_set_size(Handle, w, h);

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

lv_obj_t* CreateImage(lv_obj_t* Parent, int32_t x, int32_t y, int32_t w, int32_t h, lv_color_t bgvalue)
{
    lv_obj_t* Handle = NULL;

    Handle = lv_image_create(Parent);
    /*
        设置位置和尺寸
    */
    lv_obj_set_pos(Handle, x, y);
    lv_obj_set_size(Handle, w, h);

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

/*
    Base
        Theme image
            apply button
        Theme Name
*/
lv_obj_t* CreateThemeWidget(lv_obj_t* Parent, int32_t x, int32_t y, int32_t w, int32_t h, lv_color_t bgvalue)
{
    lv_obj_t* Handle = NULL;

    Handle = CreateBase(Parent, x, y, w, h, bgvalue);

    lv_obj_t* ThemeImage = CreateImage(Handle, 0, 0, w, h - 60, bgvalue);

    lv_obj_t* ApplyButton = CreateButton(ThemeImage, 0, h - 60 - 20, 80, 30, (lv_color_t) {255, 0, 0});

    lv_obj_t* ApplyButtonLabel = CreateLabel(ApplyButton, 0, 0, 80, 30, "Apply", lv_color_hex3(0xF00));

    lv_obj_t* ThemeNameLabel   = CreateLabel(Handle, 0, 0, h - 60, 60, "Reel to Reel", lv_color_hex3(0xF00));

    return Handle;
}