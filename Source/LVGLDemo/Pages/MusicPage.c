#include "MusicPage.h"

void CreateMusicPage(MusicPage* Page, lv_obj_t* Parent)
{
    Page->Parent = Parent;
    /*---------------------------------------------------------------------*/
    Page->Handle = lv_obj_create(Parent);
    /*
        设置位置和尺寸
    */
    lv_obj_set_size(Page->Handle, LV_PCT(100), LV_PCT(100)); // 全屏
    /*
        设置盒子模型
    */
    lv_obj_set_style_pad_all(Page->Handle, 0, 0);
    lv_obj_set_style_border_width(Page->Handle, 0, 0);
    lv_obj_set_style_margin_all(Page->Handle, 0, 0);
    /*
          设置背景颜色
      */
    lv_obj_set_style_bg_color(Page->Handle, lv_color_hex3(0xFF0), 0);
    /*
        设置radius
    */
    lv_obj_set_style_radius(Page->Handle, 0, 0);
    /*
        关闭滚动条
    */
    lv_obj_clear_flag(Page->Handle, LV_OBJ_FLAG_SCROLLABLE);
    /*---------------------------------------------------------------------*/
    /*
        播放按钮
    */
    Page->play_button = lv_button_create(Page->Handle);
    /*
        设置位置和尺寸
    */
    lv_obj_set_pos(Page->play_button,   0,  0);
    lv_obj_set_size(Page->play_button, 50, 50);
    /*
        设置盒子模型
    */
    lv_obj_set_style_pad_all(Page->play_button, 0, 0);
    lv_obj_set_style_border_width(Page->play_button, 0, 0);
    lv_obj_set_style_margin_all(Page->play_button, 0, 0);
    /*
      设置背景颜色
    */
    lv_obj_set_style_bg_color(Page->play_button, lv_color_hex3(0x00F), 0);
    /*
        设置radius
    */
    lv_obj_set_style_radius(Page->play_button, 25, 0);
    /*
        关闭滚动条
    */
    lv_obj_clear_flag(Page->play_button, LV_OBJ_FLAG_SCROLLABLE);
    /*---------------------------------------------------------------------*/
}