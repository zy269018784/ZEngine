#include "lvgl/lvgl.h"
#include "lvgl/src/drivers/lv_drivers.h"
#include "lvgl/src/drivers/windows/lv_windows_display.h"
#include <iostream>

void LVGLDemos()
{
    std::cout << "lvgl " << std::endl;

    lv_init();

    int32_t zoom_level = 100;
    bool allow_dpi_override = false;
    bool simulator_mode = true;
    lv_display_t* display = lv_windows_create_display(
        L"LVGL Windows Simulator Display 1",
        800,
        480,
        zoom_level,
        allow_dpi_override,
        simulator_mode);


    lv_obj_t* label1 = lv_label_create(lv_screen_active());
    lv_label_set_text_static(label1, "label1");
    lv_obj_set_style_text_color(label1, lv_color_hex(0xFF0000), 0);
    lv_obj_set_width(label1, 250);
    lv_obj_set_pos(label1, 300, 0);

    lv_obj_t* label2 = lv_label_create(lv_screen_active());
    lv_label_set_text_static(label2, "label2");
    lv_obj_set_width(label2, 250);

    while (1)
    {
        uint32_t time_till_next = lv_timer_handler();
        lv_delay_ms(time_till_next);
    }
}