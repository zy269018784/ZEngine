#include "DockSetting.h"

struct DockSetting* CreateDockSetting(lv_obj_t* Parent)
{
	struct DockSetting* Page = (struct DockSetting*)malloc(sizeof(struct DockSetting));

	Page->Handle = lv_obj_create(Parent);
	lv_obj_set_size(Page->Handle, LV_PCT(100) - 200, LV_PCT(100)); // 全屏
	lv_obj_set_style_border_width(Page->Handle, 0, 0);       // 无边框
	lv_obj_set_style_radius(Page->Handle, 0, 0);             // 无圆角
	lv_obj_set_style_bg_color(Page->Handle, lv_color_white(), 0); // 背景色
	lv_obj_set_pos(Page->Handle, 200, 0);

	Page->MusicName		    = lv_label_create(Page->Handle);
	Page->MusicName_2		= lv_label_create(Page->Handle);
	lv_label_set_text_static(Page->MusicName,		"Music Name");
	lv_label_set_text_static(Page->MusicName_2,	   "Time Setting");
	lv_obj_set_pos(Page->MusicName, 0, 0);
	lv_obj_set_pos(Page->MusicName_2, 100, 0);

	Page->SingerName		= lv_label_create(Page->Handle);
	Page->SingerName_2	= lv_label_create(Page->Handle);
	lv_label_set_text_static(Page->SingerName,	"Singer Name");
	lv_label_set_text_static(Page->SingerName_2,	"1");
	lv_obj_set_pos(Page->SingerName, 0, 50);
	lv_obj_set_pos(Page->SingerName_2, 100, 50);

	Page->AlbumName		= lv_label_create(Page->Handle);
	Page->AlbumName_2		= lv_label_create(Page->Handle);
	lv_label_set_text_static(Page->AlbumName,		"Album Name");
	lv_label_set_text_static(Page->AlbumName_2,	"1");
	lv_obj_set_pos(Page->AlbumName, 0, 100);
	lv_obj_set_pos(Page->AlbumName_2, 100, 100);

	Page->Duration		= lv_label_create(Page->Handle);
	Page->Duration_2		= lv_label_create(Page->Handle);
	lv_label_set_text_static(Page->Duration,		"Duration");
	lv_label_set_text_static(Page->Duration_2,	"100s");
	lv_obj_set_pos(Page->Duration, 0, 150);
	lv_obj_set_pos(Page->Duration_2, 100, 150);

	Page->ProgressBar		= lv_label_create(Page->Handle);
	Page->ProgressBar_2	= lv_label_create(Page->Handle);
	lv_label_set_text_static(Page->ProgressBar,	"ProgressBar");
	lv_label_set_text_static(Page->ProgressBar_2, "10%");
	lv_obj_set_pos(Page->ProgressBar, 0, 200);
	lv_obj_set_pos(Page->ProgressBar_2, 100, 200);

	Page->Pause           = lv_button_create(Page->Handle);
	lv_obj_set_pos(Page->Pause, 0,   250);
	lv_obj_set_pos(Page->Pause, 100, 250);


	Page->LabelPause = lv_label_create(Page->Pause);
	lv_label_set_text_static(Page->LabelPause, "Pause");
	return Page;
}
