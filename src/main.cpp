#include "lvgl.h"
#include "PanelLan.h"
#include "ui.h" // Stelle sicher, dass dieser Pfad korrekt ist

PanelLan tft(BOARD_BC02);

/*Change to your screen resolution*/
static const uint16_t screenWidth  = 480;
static const uint16_t screenHeight = 480;

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[2][ screenWidth * 10 ];

/* Display flushing */
void my_disp_flush( lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p )
{
    if (tft.getStartCount() == 0)
    {   // Processing if not yet started
        tft.startWrite();
    }
    tft.pushImageDMA( area->x1
                    , area->y1
                    , area->x2 - area->x1 + 1
                    , area->y2 - area->y1 + 1
                    , ( lgfx::swap565_t* )&color_p->full);
    lv_disp_flush_ready( disp );
}

void setup() {
    tft.begin();

    lv_init();
    lv_disp_draw_buf_init( &draw_buf, buf[0], buf[1], screenWidth * 10 );

    /*Initialize the display*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init( &disp_drv );
    /*Change the following line to your display resolution*/
    disp_drv.hor_res = screenWidth;
    disp_drv.ver_res = screenHeight;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register( &disp_drv );

    // Hier laden wir die UI aus SquareLine
    ui_init(); // Initialisiere die von SquareLine generierte UI

    // Hier laden wir den Hauptbildschirm (angepasst nach deinen spezifischen Funktionen in ui.c/ui.h)
    lv_scr_load(lv_scr_act()); // Lade den aktiven Screen, der in setup_ui vorbereitet wurde
}

void loop() {
    lv_timer_handler(); // call it every loop
    delay(5);
}
