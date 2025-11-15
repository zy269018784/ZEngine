#include "LVGLWindow.h"
#include "lvgl/lvgl.h"
#include "lvgl/src/drivers/lv_drivers.h"
#ifdef SYSTEM_IS_WINDOWS
#include "lvgl/src/drivers/windows/lv_windows_display.h"
#endif
#ifdef SYSTEM_IS_LINUX
#include "lvgl/src/drivers/x11/lv_x11.h"
#endif
#include <iostream>
LVGLWindow::LVGLWindow(int Width, int Height, const char* Title, GraphicsAPI API)
{
    std::cout << "lvgl " << std::endl;

    lv_init();

    int32_t zoom_level = 100;
    bool allow_dpi_override = false;
    bool simulator_mode = true;
#ifdef SYSTEM_IS_WINDOWS
    lv_display_t* display = lv_windows_create_display(
        L"LVGL Windows Simulator Display 1",
        800,
        480,
        zoom_level,
        allow_dpi_override,
        simulator_mode);
#endif
#ifdef SYSTEM_IS_LINUX
    lv_display_t* display = lv_x11_window_create(L"LVGL Windows Simulator Display 1",
        800,
        480);
#endif

    lv_obj_t* label1 = lv_label_create(lv_screen_active());
    lv_label_set_text_static(label1, "Widgets demo");
    lv_obj_set_width(label1, 1250);

    while (1)
    {
        uint32_t time_till_next = lv_timer_handler();
        lv_delay_ms(time_till_next);
    }
}

LVGLWindow::~LVGLWindow()
{
	
}


void LVGLWindow::Resize(int Width, int Height)
{
	
}
