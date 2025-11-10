#include "WallpapperPage.h"

void CreateWallpapperPage(WallpapperPage* Page, lv_obj_t* Parent)
{
    Page->Parent = Parent;
    /*---------------------------------------------------------------------*/
    Page->Handle = CreateBase(Parent, 0, 0, LV_PCT(100), LV_PCT(100), lv_color_hex3(0x00F));
    /*---------------------------------------------------------------------*/
}

