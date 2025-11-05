#pragma once
#include "LVGLDemo/Point2.h"
typedef struct {
	/*
		Music
	*/
		
	Point2 music_cover_size;									//		音乐界面的封面尺寸
	Point2 music_cover_postion;									//		音乐界面的封面位置
	Point2 music_cover_roundness;								//		音乐界面的封面圆角大小
	bool music_play_button_on;									//		音乐界面的播放按钮是否显示
	Point2 music_play_button_size;								//		音乐界面的按钮尺寸
	Point2 music_play_button_postion;							//		音乐界面的按钮位置
	bool music_previous_button_on;								//		音乐界面的上一曲按钮是否显示
	Point2 music_previous_button_size;							//		音乐界面的上一曲按钮尺寸
	Point2 music_previous_button_postion;						//		音乐界面的上一曲按钮位置
	bool music_next_button_on ;									//		音乐界面的下一曲按钮是否显示
	Point2 music_next_button_size;								//		音乐界面的下一曲按钮尺寸
	Point2 music_next_button_postion;							//		音乐界面的下一曲按钮位置
	bool music_progressbar_on;									//		音乐界面的进度条开关
	Point2 music_progressbar_size;								//		音乐界面的进度条尺寸
	Point2 music_progressbar_postion;							//		音乐界面的进度条位置
	bool music_progressbar_vertical;							//		音乐界面的进度条是横向还是纵向
}Theme;


