#include "Application.h"

struct Application* CreateApplication()
{
    struct Application* App = (struct Application*)malloc(sizeof(struct Application));
    lv_init();
    App->Display = lv_windows_create_display(
        L"Milkyway Keyboard",
        480,
        480,
        100,
        false,
        true);

    lv_obj_t* ActiveScreen = lv_screen_active();
    lv_obj_set_style_pad_all(ActiveScreen, 0, 0);
    lv_obj_set_style_border_width(ActiveScreen, 0, 0);
    lv_obj_set_style_margin_all(ActiveScreen, 0, 0);

    //App->CurrentTheme = (struct Theme*)malloc(sizeof(struct Theme));
    App->CurrentTheme.main_font_color   = lv_color_hex3(0x00F);
    App->CurrentTheme.sub_font_color    = lv_color_hex3(0x0F0);
    App->CurrentTheme.main_color        = lv_color_hex3(0xF0F);
    App->CurrentTheme.sub_color         = lv_color_hex3(0x0FF);
    App->CurrentTheme.focused_color     = lv_color_hex3(0xFF0);


    /*
        水平布局
    */
    App->RowLayout = lv_obj_create(ActiveScreen);
    int RowLayoutWidth = 30 * 5 + 7 * 4;
    lv_obj_set_pos(App->RowLayout, 10, 420);
    lv_obj_set_size(App->RowLayout, RowLayoutWidth, 38);
    lv_obj_set_style_bg_color(App->RowLayout, lv_color_hex3(0x000), 0);
    lv_obj_set_style_border_width(App->RowLayout, 0, 0);
    lv_obj_set_style_pad_all(App->RowLayout, 0, 0);
    lv_obj_clear_flag(App->RowLayout, LV_OBJ_FLAG_SCROLLABLE);
    //lv_obj_set_flex_flow(App->RowLayout, LV_FLEX_FLOW_ROW);
    //lv_obj_set_flex_align(
    //    App->RowLayout,
    //    LV_FLEX_ALIGN_SPACE_BETWEEN,     // 主轴对齐（水平方向）
    //    LV_FLEX_ALIGN_CENTER,    // 交叉轴对齐（垂直方向）- 垂直居中
    //    LV_FLEX_ALIGN_CENTER     // 跟踪对齐
    //);

    App->ButtonHomePage = lv_button_create(App->RowLayout);
    lv_obj_set_pos(App->ButtonHomePage, 4 * 1 + 30 * 0, 4);
    lv_obj_set_size(App->ButtonHomePage, 30, 30);
    lv_obj_set_style_bg_color(App->ButtonHomePage, App->CurrentTheme.main_color, 0);
    lv_obj_clear_flag(App->ButtonHomePage, LV_OBJ_FLAG_SCROLLABLE);

    App->ButtonMusic = lv_button_create(App->RowLayout);
    lv_obj_set_pos(App->ButtonMusic,   4 * 2 + 30 * 1, 4);
    lv_obj_set_size(App->ButtonMusic, 30, 30);
    lv_obj_set_style_bg_color(App->ButtonMusic, App->CurrentTheme.sub_color, 0);
    lv_obj_clear_flag(App->ButtonMusic, LV_OBJ_FLAG_SCROLLABLE);

    App->ButtonClock = lv_button_create(App->RowLayout);
    lv_obj_set_pos(App->ButtonClock,  4 * 3 + 30 * 2, 4);
    lv_obj_set_size(App->ButtonClock, 30, 30);
    lv_obj_set_style_bg_color(App->ButtonClock, App->CurrentTheme.sub_color, 0);
    lv_obj_clear_flag(App->ButtonClock, LV_OBJ_FLAG_SCROLLABLE);

    App->ButtonSystemInfo = lv_button_create(App->RowLayout);
    lv_obj_set_pos(App->ButtonSystemInfo, 4 * 4 + 30 * 3, 4);
    lv_obj_set_size(App->ButtonSystemInfo, 30, 30);
    lv_obj_set_style_bg_color(App->ButtonSystemInfo, App->CurrentTheme.sub_color, 0);
    lv_obj_clear_flag(App->ButtonSystemInfo, LV_OBJ_FLAG_SCROLLABLE);


    App->ButtonSetting = lv_button_create(App->RowLayout);
    lv_obj_set_pos(App->ButtonSetting, 4 * 5 + 30 * 4, 4);
    lv_obj_set_size(App->ButtonSetting, 30, 30);
    lv_obj_set_style_bg_color(App->ButtonSetting, App->CurrentTheme.sub_color, 0);
    lv_obj_clear_flag(App->ButtonSetting, LV_OBJ_FLAG_SCROLLABLE);

    CreateThemePage(&App->PageTheme, ActiveScreen);
    CreateSystemInfoPage(&App->PageSystemInfo, ActiveScreen);
    CreateClockPage(&App->PageClock, ActiveScreen);
    CreateMusicPage(&App->PageMusic, ActiveScreen);

    lv_obj_set_parent(App->RowLayout, App->PageClock.Handle);

	return App;
}

void ShowPage(struct Application* App, int PageNo)
{
    lv_obj_add_flag(App->PageTheme.Handle,          LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(App->PageSystemInfo.Handle,     LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(App->PageMusic.Handle,          LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(App->PageClock.Handle,          LV_OBJ_FLAG_HIDDEN);

    switch (PageNo)
    {
    case MusicPageNum:
        lv_obj_clear_flag(App->PageMusic.Handle, LV_OBJ_FLAG_HIDDEN);
        break;
    case ClockPageNum:
        lv_obj_clear_flag(App->PageClock.Handle, LV_OBJ_FLAG_HIDDEN);
        break;
    case SystemInfoPageNum:
        lv_obj_clear_flag(App->PageSystemInfo.Handle, LV_OBJ_FLAG_HIDDEN);
        break;
    default:
        break;
    }
}

void Run(Application* App)
{
    ShowPage(App, SystemInfoPageNum);
    //ClockTimeUpState(&App->PageClock);
    //ClockDefaultState(&App->PageClock);
    //ClockStartState(&App->PageClock);
    while (1)
    {
        uint32_t time_till_next = lv_timer_handler();
        //lv_obj_send_event(tabview, LV_EVENT_VALUE_CHANGED, NULL);
        lv_delay_ms(time_till_next);
    }
}