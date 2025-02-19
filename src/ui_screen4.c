// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: SquareLine_Project

#include "ui.h"

void ui_screen4_screen_init(void)
{
    ui_screen4 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_screen4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_image4 = lv_img_create(ui_screen4);
    lv_img_set_src(ui_image4, ui_img_background_png);
    lv_obj_set_width(ui_image4, LV_SIZE_CONTENT);   /// 480
    lv_obj_set_height(ui_image4, LV_SIZE_CONTENT);    /// 480
    lv_obj_set_align(ui_image4, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_image4, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_image4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_image5 = lv_img_create(ui_screen4);
    lv_img_set_src(ui_image5, ui_img_reisinger_r_png);
    lv_obj_set_width(ui_image5, LV_SIZE_CONTENT);   /// 160
    lv_obj_set_height(ui_image5, LV_SIZE_CONTENT);    /// 160
    lv_obj_set_x(ui_image5, 0);
    lv_obj_set_y(ui_image5, -1);
    lv_obj_set_align(ui_image5, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_image5, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_image5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_zoom(ui_image5, 30);

}
