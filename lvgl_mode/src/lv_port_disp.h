#ifndef __LV_PORT_DISP_H
#define __LV_PORT_DISP_H

#include "lvgl.h"
#include "TFT_eSPI.h"

typedef TFT_eSPI SCREEN_CLASS;

void lv_port_disp_init(SCREEN_CLASS* scr);

#endif 