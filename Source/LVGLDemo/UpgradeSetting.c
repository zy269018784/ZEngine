#include "UpgradeSetting.h"

struct UpgradeSetting* CreateUpgradeSetting(lv_obj_t* Parent)
{
	struct UpgradeSetting* Page = (struct UpgradeSetting*)malloc(sizeof(struct UpgradeSetting));

	Page->Handle = lv_obj_create(Parent);
	lv_obj_set_size(Page->Handle, LV_PCT(100) - 200, LV_PCT(100)); // 全屏
	lv_obj_set_style_border_width(Page->Handle, 0, 0);       // 无边框
	lv_obj_set_style_radius(Page->Handle, 0, 0);             // 无圆角
	lv_obj_set_style_bg_color(Page->Handle, lv_color_white(), 0); // 背景色
	lv_obj_set_pos(Page->Handle, 200, 0);

	Page->CurrentVersion = lv_label_create(Page->Handle);
	Page->CurrentVersion_2 = lv_label_create(Page->Handle);
	lv_label_set_text_static(Page->CurrentVersion, "Current Version: ");
	lv_label_set_text_static(Page->CurrentVersion_2, "v1.2.3");
	lv_obj_set_pos(Page->CurrentVersion,   0, 0);
	lv_obj_set_pos(Page->CurrentVersion_2, 200, 0);

	Page->Pause = lv_button_create(Page->Handle);
	lv_obj_set_pos(Page->Pause, 0,  50);

	Page->LabelPause = lv_label_create(Page->Pause);
	lv_label_set_text_static(Page->LabelPause, "Check Update");
	return Page;
}
