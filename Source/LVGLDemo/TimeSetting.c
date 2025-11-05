#include "TimeSetting.h"

struct TimeSetting* CreateTimeSetting(lv_obj_t* Parent)
{
	struct TimeSetting* Page = (struct TimeSetting*)malloc(sizeof(struct TimeSetting));

	Page->Handle = lv_obj_create(Parent);
	lv_obj_set_size(Page->Handle, LV_PCT(100) - 200, LV_PCT(100)); // 全屏
	lv_obj_set_style_border_width(Page->Handle, 0, 0);       // 无边框
	lv_obj_set_style_radius(Page->Handle, 0, 0);             // 无圆角
	lv_obj_set_style_bg_color(Page->Handle, lv_color_white(), 0); // 背景色
	lv_obj_set_pos(Page->Handle, 200, 0);
	/*
	
	*/
	Page->LabeLTimeDateSetting = lv_label_create(Page->Handle);
	lv_obj_set_pos(Page->LabeLTimeDateSetting, 0, 0);
	//lv_obj_align(Page->LabelScreenAlwaysOn, LV_ALIGN_CENTER, 0, 0);
	lv_label_set_text_static(Page->LabeLTimeDateSetting, "Time Date Setting");

	/*
		是否显示时间
	*/
	Page->LabelIsShowTime = lv_label_create(Page->Handle);
	lv_obj_set_pos(Page->LabelIsShowTime, 0, 100);
	//lv_obj_align(Page->LabelScreenAlwaysOn, LV_ALIGN_CENTER, 0, 0);
	lv_label_set_text_static(Page->LabelIsShowTime, "Show Time");

	Page->SwitchIsShowTime = lv_switch_create(Page->Handle);
	lv_obj_set_pos(Page->SwitchIsShowTime, 200, 100);


	/*
		时间格式
	*/
	Page->TimeFormat = lv_label_create(Page->Handle);
	lv_obj_set_pos(Page->TimeFormat, 0, 200);
	lv_label_set_text_static(Page->TimeFormat, "Time Format");

	/*
		日期格式
	*/
	Page->DateFormat = lv_label_create(Page->Handle);
	lv_obj_set_pos(Page->DateFormat, 0, 300);
	lv_label_set_text_static(Page->DateFormat, "Date Format");

	return Page;
}
