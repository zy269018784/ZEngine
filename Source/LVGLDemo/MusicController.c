#include "MusicController.h"

struct MusicController* CreateMusicController(lv_obj_t* Parent)
{
	struct MusicController* Handle = (struct MusicController*)malloc(sizeof(struct MusicController));
	Handle->MusicName		= lv_label_create(Parent);
	Handle->MusicName_2		= lv_label_create(Parent);
	lv_label_set_text_static(Handle->MusicName,		"Music Name");
	lv_label_set_text_static(Handle->MusicName_2,	"shi nian");
	lv_obj_set_pos(Handle->MusicName, 0, 0);
	lv_obj_set_pos(Handle->MusicName_2, 100, 0);

	Handle->SingerName		= lv_label_create(Parent);
	Handle->SingerName_2	= lv_label_create(Parent);
	lv_label_set_text_static(Handle->SingerName,	"Singer Name");
	lv_label_set_text_static(Handle->SingerName_2,	"1");
	lv_obj_set_pos(Handle->SingerName, 0, 50);
	lv_obj_set_pos(Handle->SingerName_2, 100, 50);

	Handle->AlbumName		= lv_label_create(Parent);
	Handle->AlbumName_2		= lv_label_create(Parent);
	lv_label_set_text_static(Handle->AlbumName,		"Album Name");
	lv_label_set_text_static(Handle->AlbumName_2,	"1");
	lv_obj_set_pos(Handle->AlbumName, 0, 100);
	lv_obj_set_pos(Handle->AlbumName_2, 100, 100);

	Handle->Duration		= lv_label_create(Parent);
	Handle->Duration_2		= lv_label_create(Parent);
	lv_label_set_text_static(Handle->Duration,		"Duration");
	lv_label_set_text_static(Handle->Duration_2,	"100s");
	lv_obj_set_pos(Handle->Duration, 0, 150);
	lv_obj_set_pos(Handle->Duration_2, 100, 150);

	Handle->ProgressBar		= lv_label_create(Parent);
	Handle->ProgressBar_2	= lv_label_create(Parent);
	lv_label_set_text_static(Handle->ProgressBar,	"ProgressBar");
	lv_label_set_text_static(Handle->ProgressBar_2, "10%");
	lv_obj_set_pos(Handle->ProgressBar, 0, 200);
	lv_obj_set_pos(Handle->ProgressBar_2, 100, 200);

	Handle->Pause           = lv_button_create(Parent);
	lv_obj_set_pos(Handle->Pause, 0,   250);
	lv_obj_set_pos(Handle->Pause, 100, 250);


	Handle->LabelPause = lv_label_create(Handle->Pause);
	lv_label_set_text_static(Handle->LabelPause, "Pause");
	return Handle;
}
