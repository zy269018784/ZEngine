#include "SystemInfoPage.h"
#include "LVGLDemo/Widgets/Widget.h"
void CreateSystemInfoPage(SystemInfoPage* Page, lv_obj_t* Parent)
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
    lv_obj_set_style_bg_color(Page->Handle, lv_color_hex3(0xF00), 0);
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
        label
    */
    Page->CPUUsage      = CreateLabel(Page->Handle,  10, 10, 150, 50, "CPUUsage", lv_color_hex3(0x00F));
    Page->CPUUsage_2    = CreateLabel(Page->Handle, 200, 10, 150, 50, "78%", lv_color_hex3(0x00F));
    Page->CPUTemp       = CreateLabel(Page->Handle,  10, 60, 150, 50, "Temp", lv_color_hex3(0x00F));
    Page->CPUTemp_2     = CreateLabel(Page->Handle, 200, 60, 150, 50, "50", lv_color_hex3(0x00F));
    Page->CPUFreq       = CreateLabel(Page->Handle,  10, 110, 150, 50, "Freq", lv_color_hex3(0x00F));
    Page->CPUFreq_2     = CreateLabel(Page->Handle, 200, 110, 150, 50, "1GHz", lv_color_hex3(0x00F));
    Page->MemUsage      = CreateLabel(Page->Handle,  10, 160, 150, 50, "Mem Usage", lv_color_hex3(0x00F));
    Page->MemUsage_2    = CreateLabel(Page->Handle, 200, 160, 150, 50, "31%", lv_color_hex3(0x00F));
    Page->UpSpeed       = CreateLabel(Page->Handle,  10, 210, 150, 50, "UpSpeed", lv_color_hex3(0x00F));
    Page->UpSpeed_2     = CreateLabel(Page->Handle, 200, 210, 150, 50, "100MB", lv_color_hex3(0x00F));
    Page->DownSpeed     = CreateLabel(Page->Handle,  10,  260, 150, 50, "DownSpeed", lv_color_hex3(0x00F));
    Page->DownSpeed_2   = CreateLabel(Page->Handle, 200, 260, 150, 50, "200MB", lv_color_hex3(0x00F));
    /*---------------------------------------------------------------------*/
}

