#include "OtherSetting.h"

struct OtherSetting* CreateOtherSetting(lv_obj_t* Parent)
{
	struct OtherSetting* Page = (struct OtherSetting*)malloc(sizeof(struct OtherSetting));

	Page->Handle = lv_obj_create(Parent);
	lv_obj_set_size(Page->Handle, LV_PCT(100) - 200, LV_PCT(100)); // 全屏
	lv_obj_set_style_border_width(Page->Handle, 0, 0);       // 无边框
	lv_obj_set_style_radius(Page->Handle, 0, 0);             // 无圆角
	lv_obj_set_style_bg_color(Page->Handle, lv_color_white(), 0); // 背景色
	lv_obj_set_pos(Page->Handle, 200, 0);

	/*
		屏幕常亮
	*/
	Page->LabelScreenAlwaysOn = lv_label_create(Page->Handle);
	lv_obj_set_pos(Page->LabelScreenAlwaysOn, 0, 0);
	//lv_obj_align(Page->LabelScreenAlwaysOn, LV_ALIGN_CENTER, 0, 0);
	lv_label_set_text_static(Page->LabelScreenAlwaysOn, "Screen Always On");

	Page->SwitchScreenAlwaysOn = lv_switch_create(Page->Handle);
	lv_obj_set_pos(Page->SwitchScreenAlwaysOn, 200, 0);

	/*
		熄屏时间
	*/
	Page->LabelScreenTimeout = lv_label_create(Page->Handle);
	lv_obj_set_pos(Page->LabelScreenTimeout, 0, 100);
	lv_label_set_text_static(Page->LabelScreenTimeout, "Screen Timeout");

	Page->PopupScreenTimeout = lv_dropdown_create(Page->Handle);
	lv_obj_set_pos(Page->PopupScreenTimeout, 200, 100);
	lv_dropdown_set_options(Page->PopupScreenTimeout, "1\n"
													  "2\n"
													  "5\n"
													  "10\n"
													  "20\n"
													  "30\n");

	/*
		恢复出厂
	*/
	Page->ButtonFactoryReset = lv_button_create(Page->Handle);
	lv_obj_set_pos(Page->ButtonFactoryReset, 0, 200);

	Page->LabelFactoryReset = lv_label_create(Page->ButtonFactoryReset);
	lv_label_set_text_static(Page->LabelFactoryReset, "Factory Reset");
	return Page;
}
