#include "SystemInfo.h"

struct SystemInfo* CreateSystemInfo(lv_obj_t* Parent)
{
	struct SystemInfo* Handle = (struct SystemInfo*)malloc(sizeof(struct SystemInfo));

	Handle->CPUUsage = lv_label_create(Parent);
	Handle->CPUTemp = lv_label_create(Parent);
	Handle->CPUFreq = lv_label_create(Parent);
	Handle->MemUsage = lv_label_create(Parent);
	Handle->UpSpeed = lv_label_create(Parent);
	Handle->DownSpeed = lv_label_create(Parent);
	Handle->CPUUsage_2 = lv_label_create(Parent);
	Handle->CPUTemp_2 = lv_label_create(Parent);
	Handle->CPUFreq_2 = lv_label_create(Parent);
	Handle->MemUsage_2 = lv_label_create(Parent);
	Handle->UpSpeed_2 = lv_label_create(Parent);
	Handle->DownSpeed_2 = lv_label_create(Parent);


	lv_label_set_text_static(Handle->CPUUsage,		"CPUUsage");
	lv_label_set_text_static(Handle->CPUTemp,		"CPUTemp");
	lv_label_set_text_static(Handle->CPUFreq,		"CPUFreq");
	lv_label_set_text_static(Handle->MemUsage,		"MemUsage");
	lv_label_set_text_static(Handle->UpSpeed,		"UpSpeed");
	lv_label_set_text_static(Handle->DownSpeed,		"DownSpeed");
	lv_label_set_text_static(Handle->CPUUsage_2,	"80%");
	lv_label_set_text_static(Handle->CPUTemp_2,		"37F");
	lv_label_set_text_static(Handle->CPUFreq_2,		"1024MHZ");
	lv_label_set_text_static(Handle->MemUsage_2,	"30%");
	lv_label_set_text_static(Handle->UpSpeed_2,		"100KB/s");
	lv_label_set_text_static(Handle->DownSpeed_2,	"200KB/s");

	lv_obj_set_pos(Handle->CPUUsage,      0, 0);
	lv_obj_set_pos(Handle->CPUUsage_2,  100, 0);
									    
	lv_obj_set_pos(Handle->CPUTemp,       0,  50);
	lv_obj_set_pos(Handle->CPUTemp_2,   100,  50);
									    
	lv_obj_set_pos(Handle->CPUFreq,       0, 100);
	lv_obj_set_pos(Handle->CPUFreq_2,   100, 100);
									    
	lv_obj_set_pos(Handle->MemUsage,      0, 150);
	lv_obj_set_pos(Handle->MemUsage_2,  100, 150);
									    
	lv_obj_set_pos(Handle->UpSpeed,       0, 200);
	lv_obj_set_pos(Handle->UpSpeed_2,   100, 200);

	lv_obj_set_pos(Handle->DownSpeed,     0, 250);
	lv_obj_set_pos(Handle->DownSpeed_2, 100, 250);

	return Handle;
}