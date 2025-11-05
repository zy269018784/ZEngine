#include "ClockPage.h"

void CreateClockPage(ClockPage* Page, lv_obj_t* Parent)
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
    lv_obj_set_style_bg_color(Page->Handle, lv_color_hex3(0x0F0), 0);
    /*
        设置radius
    */
    lv_obj_set_style_radius(Page->Handle, 0, 0);
    /*
        关闭滚动条
    */
    lv_obj_clear_flag(Page->Handle, LV_OBJ_FLAG_SCROLLABLE);
    /*---------------------------------------------------------------------*/

    /*---------------------------------------------------------------------*/
    /*
        开始按钮
    */
    Page->start_button = lv_button_create(Page->Handle);
    /*
        设置位置和尺寸
    */
    Page->timer_start_button_postion = (Point2){ 420, 10 };
    Page->timer_start_button_size = (Point2){ 50, 50 };
    lv_obj_set_pos(Page->start_button, Page->timer_start_button_postion.x, Page->timer_start_button_postion.y);
    lv_obj_set_size(Page->start_button, Page->timer_start_button_size.x, Page->timer_start_button_size.y);
    /*
        设置盒子模型
    */
    lv_obj_set_style_pad_all(Page->start_button, 0, 0);
    lv_obj_set_style_border_width(Page->start_button, 0, 0);
    lv_obj_set_style_margin_all(Page->start_button, 0, 0);
    /*
      设置背景颜色
    */
    lv_obj_set_style_bg_color(Page->start_button, lv_color_hex3(0x00F), 0);
    /*
        设置radius
    */
    lv_obj_set_style_radius(Page->start_button, 25, 0);
    /*
        关闭滚动条
    */
    lv_obj_clear_flag(Page->start_button, LV_OBJ_FLAG_SCROLLABLE);
    /*---------------------------------------------------------------------*/
    /*
        结束按钮
    */
    Page->stop_button = lv_button_create(Page->Handle);
    /*
        设置位置和尺寸
    */
    Page->timer_stop_button_postion = (Point2){ 420, 10 };
    Page->timer_stop_button_size = (Point2){ 50, 50 };
    lv_obj_set_pos(Page->stop_button, Page->timer_stop_button_postion.x, Page->timer_stop_button_postion.y);
    lv_obj_set_size(Page->stop_button, Page->timer_stop_button_size.x, Page->timer_stop_button_size.y);
    /*
        设置盒子模型
    */
    lv_obj_set_style_pad_all(Page->stop_button, 0, 0);
    lv_obj_set_style_border_width(Page->stop_button, 0, 0);
    lv_obj_set_style_margin_all(Page->stop_button, 0, 0);
    /*
      设置背景颜色
    */
    lv_obj_set_style_bg_color(Page->stop_button, lv_color_hex3(0xF0F), 0);
    /*
        设置radius
    */
    lv_obj_set_style_radius(Page->stop_button, 25, 0);
    /*
        关闭滚动条
    */
    lv_obj_clear_flag(Page->stop_button, LV_OBJ_FLAG_SCROLLABLE);
    /*---------------------------------------------------------------------*/
    ///*
    //    设置时间按钮
    //*/
    //Page->setting_time_button = lv_button_create(Page->Handle);
    ///*
    //    设置位置和尺寸
    //*/
    //Page->timer_setting_time_font_postion = (Point2){ 10, 350 };
    //Page->timer_setting_time_font_size = (Point2){ 200, 50 };
    //lv_obj_set_pos(Page->setting_time_button, Page->timer_setting_time_font_postion.x, Page->timer_setting_time_font_postion.y);
    //lv_obj_set_size(Page->setting_time_button, Page->timer_setting_time_font_size.x, Page->timer_setting_time_font_size.y);
    ///*
    //    设置盒子模型
    //*/
    //lv_obj_set_style_pad_all(Page->setting_time_button, 0, 0);
    //lv_obj_set_style_border_width(Page->setting_time_button, 0, 0);
    //lv_obj_set_style_margin_all(Page->setting_time_button, 0, 0);
    ///*
    //  设置背景颜色
    //*/
    //lv_obj_set_style_bg_color(Page->setting_time_button, lv_color_hex3(0x000), 0);
    ///*
    //    设置radius
    //*/
    //lv_obj_set_style_radius(Page->setting_time_button, 0, 0);
    ///*
    //    关闭滚动条
    //*/
    //lv_obj_clear_flag(Page->setting_time_button, LV_OBJ_FLAG_SCROLLABLE);
    /*---------------------------------------------------------------------*/
    /*
        设置时间按钮标签
    */
    Page->setting_time_button_label = lv_label_create(Page->Handle);
    lv_label_set_text_static(Page->setting_time_button_label, "25:00");
    /*
        设置文本居中
    */
    lv_obj_set_style_text_align(Page->setting_time_button_label, LV_TEXT_ALIGN_CENTER, 0);
    /*
        设置位置和尺寸
    */
    lv_obj_set_pos(Page->setting_time_button_label, 10, 400);
    lv_obj_set_size(Page->setting_time_button_label, 200, 50);
    /*
        设置盒子模型
    */
    lv_obj_set_style_pad_all(Page->setting_time_button_label, 0, 0);
    lv_obj_set_style_border_width(Page->setting_time_button_label, 0, 0);
    lv_obj_set_style_margin_all(Page->setting_time_button_label, 0, 0);
    /*
      设置背景颜色
    */
    lv_obj_set_style_bg_color(Page->setting_time_button_label, lv_color_hex3(0xFFF), 0);
    /*
        设置radius
    */
    lv_obj_set_style_radius(Page->setting_time_button_label, 0, 0);
    /*
        关闭滚动条
    */
    lv_obj_clear_flag(Page->setting_time_button_label, LV_OBJ_FLAG_SCROLLABLE);
    /*---------------------------------------------------------------------*/


    CreateClockPageTimeUp(Page, Parent);
}

void CreateClockPageTimeUp(ClockPage* Page, lv_obj_t* Parent)
{
    Page->TimeUpPageHandle = lv_obj_create(Parent);
    /*
        设置位置和尺寸
    */
    lv_obj_set_size(Page->TimeUpPageHandle, LV_PCT(100), LV_PCT(100)); // 全屏
    /*
        设置盒子模型
    */
    lv_obj_set_style_pad_all(Page->TimeUpPageHandle, 0, 0);
    lv_obj_set_style_border_width(Page->TimeUpPageHandle, 0, 0);
    lv_obj_set_style_margin_all(Page->TimeUpPageHandle, 0, 0);
    /*
          设置背景颜色
      */
    lv_obj_set_style_bg_color(Page->TimeUpPageHandle, lv_color_hex3(0xFF0), 0);
    /*
        设置radius
    */
    lv_obj_set_style_radius(Page->TimeUpPageHandle, 0, 0);
    /*
        关闭滚动条
    */
    lv_obj_clear_flag(Page->TimeUpPageHandle, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_flag(Page->TimeUpPageHandle, LV_OBJ_FLAG_HIDDEN);

    /*---------------------------------------------------------------------*/
    /*
        返回按钮
    */
    Page->back_button = lv_button_create(Page->TimeUpPageHandle);
    /*
        设置位置和尺寸
    */
    Page->timer_back_button_postion = (Point2){ 420, 10 };
    Page->timer_back_button_size = (Point2){ 50, 50 };
    lv_obj_set_pos(Page->back_button, Page->timer_back_button_postion.x, Page->timer_back_button_postion.y);
    lv_obj_set_size(Page->back_button, Page->timer_back_button_size.x, Page->timer_back_button_size.y);
    /*
        设置盒子模型
    */
    lv_obj_set_style_pad_all(Page->back_button, 0, 0);
    lv_obj_set_style_border_width(Page->back_button, 0, 0);
    lv_obj_set_style_margin_all(Page->back_button, 0, 0);
    /*
      设置背景颜色
    */
    lv_obj_set_style_bg_color(Page->back_button, lv_color_hex3(0xFF0), 0);
    /*
        设置radius
    */
    lv_obj_set_style_radius(Page->back_button, 25, 0);
    /*
        关闭滚动条
    */
    lv_obj_clear_flag(Page->back_button, LV_OBJ_FLAG_SCROLLABLE);
    /*---------------------------------------------------------------------*/
    /*
        设置时间按钮标签
    */
    Page->time_end_label = lv_label_create(Page->TimeUpPageHandle);
    lv_label_set_text_static(Page->time_end_label, "25:00");
    /*
        设置文本居中
    */
    lv_obj_set_style_text_align(Page->time_end_label, LV_TEXT_ALIGN_CENTER, 0);
    /*
        设置位置和尺寸
    */
    lv_obj_set_pos(Page->time_end_label, 10, 400);
    lv_obj_set_size(Page->time_end_label, 200, 50);
    /*
        设置盒子模型
    */
    lv_obj_set_style_pad_all(Page->time_end_label, 0, 0);
    lv_obj_set_style_border_width(Page->time_end_label, 0, 0);
    lv_obj_set_style_margin_all(Page->time_end_label, 0, 0);
    /*
      设置背景颜色
    */
    lv_obj_set_style_bg_color(Page->time_end_label, lv_color_hex3(0xFFF), 0);
    /*
        设置radius
    */
    lv_obj_set_style_radius(Page->time_end_label, 0, 0);
    /*
        关闭滚动条
    */
    lv_obj_clear_flag(Page->time_end_label, LV_OBJ_FLAG_SCROLLABLE);
    /*---------------------------------------------------------------------*/
}

void ClockTimeUpState(ClockPage* Page)
{
    lv_obj_add_flag(Page->Handle, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(Page->TimeUpPageHandle, LV_OBJ_FLAG_HIDDEN);
}

void ClockDefaultState(ClockPage* Page)
{
    lv_obj_add_flag(Page->TimeUpPageHandle, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(Page->Handle, LV_OBJ_FLAG_HIDDEN);
    /*
        隐藏开始按钮
        显示停止按钮
    */
    lv_obj_add_flag(Page->start_button, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(Page->stop_button, LV_OBJ_FLAG_HIDDEN);
}

void ClockStartState(ClockPage* Page)
{
    lv_obj_add_flag(Page->TimeUpPageHandle, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(Page->Handle, LV_OBJ_FLAG_HIDDEN);
    /*
        隐藏停止按钮
        显示开始按钮
    */
    lv_obj_add_flag(Page->stop_button, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(Page->start_button, LV_OBJ_FLAG_HIDDEN);
}
