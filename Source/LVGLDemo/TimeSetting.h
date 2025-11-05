#pragma once
#include "lvgl/lvgl.h"

struct TimeSetting
{
	lv_obj_t* Handle;
	/*
		时间日期设置	自动获取
		手动选择时区
		手动设置时间、日期
	*/
	lv_obj_t* LabeLTimeDateSetting;

	/*
		是否显示时间	是否在首页显示时间
	*/
	lv_obj_t* LabelIsShowTime;
	lv_obj_t* SwitchIsShowTime;

	/*
		时间格式	24:00或12:00 AM
	*/
	lv_obj_t* TimeFormat;
	/*
		日期格式	英文：9 August 2025或9 August或9 Aug
		中文：2025年8月9日或2025.8.9或8月9日
	*/
	lv_obj_t* DateFormat;
	/*
		时间、日期位置选择	靠左/靠右
	*/
	lv_obj_t* Position;
};
#ifdef __cplusplus
extern "C"
{
#endif
	struct TimeSetting* CreateTimeSetting(lv_obj_t* Parent);
#ifdef __cplusplus
}
#endif