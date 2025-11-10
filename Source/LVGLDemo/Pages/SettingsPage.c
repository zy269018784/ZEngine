#include "SettingsPage.h"
#include "LVGLDemo/Widgets/Widget.h"
void CreateSettingsPage(SettingsPage* Page, lv_obj_t* Parent)
{
    Page->Parent = Parent;
    /*---------------------------------------------------------------------*/
    Page->Handle  = CreateBase(Parent, 0, 0, LV_PCT(100), LV_PCT(100), lv_color_hex3(0xF00));
    Page->HomePageHandle = CreateBase(Page->Handle, 0, 0, LV_PCT(100), LV_PCT(100), lv_color_hex3(0x0F0));
    Page->SubPageHandle = CreateBase(Page->Handle, 0, 0, LV_PCT(100), LV_PCT(100), lv_color_hex3(0x00F));
    //return;
    CreateThemePage(&Page->ThemeSettingPage, Page->SubPageHandle);
    CreateWallpapperPage(&Page->WallpapperSettingPage, Page->SubPageHandle);
    printf("aaa 1 : %p\n", Page->ThemeSettingPage.Handle);
    //lv_obj_add_flag(Page->ThemeSettingPage.Handle, LV_OBJ_FLAG_HIDDEN);
    printf("aaa 2");
    /*---------------------------------------------------------------------*/
    int32_t w = LV_PCT(100);
    Page->ButtonWallpapper  = CreateButton(Page->HomePageHandle, 0, 0,          w, 50, lv_color_hex3(0xF0F));
    Page->LabelWallpapper   = CreateLabel(Page->ButtonWallpapper, 0, 0, w, 50, "Wallpapper", lv_color_hex3(0xF00));
    lv_obj_set_style_text_align(Page->LabelWallpapper, LV_TEXT_ALIGN_CENTER, 0);
    Page->ButtonTheme       = CreateButton(Page->HomePageHandle, 0, 50,        w, 50, lv_color_hex3(0x00F));
    Page->LabelTheme        = CreateLabel(Page->ButtonTheme, 0, 0,      w, 50, "Theme", lv_color_hex3(0x00F));
    Page->ButtonDock        = CreateButton(Page->HomePageHandle, 0, 100,       w, 50, lv_color_hex3(0x00F));
    Page->LabelDock         = CreateLabel(Page->ButtonDock, 0, 0,       w, 50, "Dock", lv_color_hex3(0x00F));
    Page->ButtonClock       = CreateButton(Page->HomePageHandle, 0, 150,       w, 50, lv_color_hex3(0x00F));
    Page->LabelClock        = CreateLabel(Page->ButtonClock, 0, 0,      w, 50, "Clock", lv_color_hex3(0x00F));
    Page->ButtonOther       = CreateButton(Page->HomePageHandle, 0, 200,       w, 50, lv_color_hex3(0x00F));
    Page->LabelOther        = CreateLabel(Page->ButtonOther, 0, 0,      w, 50, "Other", lv_color_hex3(0x00F));
    Page->ButtonUpdate      = CreateButton(Page->HomePageHandle, 0, 250,       w, 50, lv_color_hex3(0x00F));
    Page->LabelUpdate       = CreateLabel(Page->ButtonUpdate, 0, 0,     w, 50, "Update", lv_color_hex3(0x00F));
    /*---------------------------------------------------------------------*/
}

void ShowSettingPage(SettingsPage* Page, int PageNo)
{
    lv_obj_add_flag(Page->HomePageHandle, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(Page->SubPageHandle, LV_OBJ_FLAG_HIDDEN);

    //lv_obj_add_flag(Page->ThemeSettingPage.Handle, LV_OBJ_FLAG_HIDDEN);
    //lv_obj_add_flag(Page->WallpapperSettingPage.Handle, LV_OBJ_FLAG_HIDDEN);
    switch (PageNo)
    {
    case SettingHomePageNum:
        lv_obj_clear_flag(Page->HomePageHandle, LV_OBJ_FLAG_HIDDEN);
        break;
    case ThemePageNum:
        lv_obj_clear_flag(Page->SubPageHandle, LV_OBJ_FLAG_HIDDEN);
       // lv_obj_clear_flag(Page->ThemeSettingPage.Handle, LV_OBJ_FLAG_HIDDEN);
        break;
    case WallpaperPageNum:
        lv_obj_clear_flag(Page->SubPageHandle, LV_OBJ_FLAG_HIDDEN);
       // lv_obj_clear_flag(Page->WallpapperSettingPage.Handle, LV_OBJ_FLAG_HIDDEN);
        break;
    }
}