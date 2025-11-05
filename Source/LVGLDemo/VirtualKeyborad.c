#include "VirtualKeyborad.h"

struct VirtualKeyborad* CreateVirtualKeyborad(lv_obj_t *Parent)
{
	struct VirtualKeyborad* VB = (struct VirtualKeyborad *)malloc(sizeof(struct VirtualKeyborad));

	VB->Handle = lv_button_create(Parent);
	VB->ButtonPrint		= lv_button_create(Parent);
	VB->ButtonScroll	= lv_button_create(Parent);
	VB->ButtonPause		= lv_button_create(Parent);
	VB->ButtonInsert	= lv_button_create(Parent);
	VB->ButtonHome		= lv_button_create(Parent);
	VB->ButtonPageUp	= lv_button_create(Parent);
	VB->ButtonPageDown	= lv_button_create(Parent);
	VB->ButtonDelete	= lv_button_create(Parent);
	VB->ButtonEnd		= lv_button_create(Parent);

	VB->LabelPrint		= lv_label_create(VB->ButtonPrint);
	VB->LabelScroll		= lv_label_create(VB->ButtonScroll);
	VB->LabelPause		= lv_label_create(VB->ButtonPause);
	VB->LabelInsert		= lv_label_create(VB->ButtonInsert);
	VB->LabelHome		= lv_label_create(VB->ButtonHome);
	VB->LabelPageUp		= lv_label_create(VB->ButtonPageUp);
	VB->LabelPageDown	= lv_label_create(VB->ButtonPageDown);
	VB->LabelDelete		= lv_label_create(VB->ButtonDelete);
	VB->LabelEnd		= lv_label_create(VB->ButtonEnd);

	lv_label_set_text_static(VB->LabelPrint,	"Print");
	lv_label_set_text_static(VB->LabelScroll,	"Scroll");
	lv_label_set_text_static(VB->LabelPause,	"Pause");
	lv_label_set_text_static(VB->LabelInsert,	"Insert");
	lv_label_set_text_static(VB->LabelHome,		"Home");
	lv_label_set_text_static(VB->LabelPageUp,	"PageUp");
	lv_label_set_text_static(VB->LabelPageDown, "PageDown");
	lv_label_set_text_static(VB->LabelDelete,	"Delete");
	lv_label_set_text_static(VB->LabelEnd,		"End");



	lv_obj_set_pos(VB->ButtonPrint,		100 * 0,  0);
	lv_obj_set_pos(VB->ButtonScroll,	100 * 1,  0);
	lv_obj_set_pos(VB->ButtonPause,		100 * 2,  0);
	lv_obj_set_pos(VB->ButtonInsert,	100 * 3,  0);
	lv_obj_set_pos(VB->ButtonHome,		100 * 4,  0);
	lv_obj_set_pos(VB->ButtonPageUp,	100 * 5,  0);
	lv_obj_set_pos(VB->ButtonPageDown,	100 * 6,  0);
	lv_obj_set_pos(VB->ButtonDelete,	100 * 8,  0);
	lv_obj_set_pos(VB->ButtonEnd,		100 * 9,  0);

	return VB;
}
