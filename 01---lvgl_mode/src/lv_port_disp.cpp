#include "lv_port_disp.h"
//static lv_color_t lv_full_disp_buf[DISP_BUF_SIZE];
lv_color_t* lv_disp_buf_p;

static lv_disp_draw_buf_t disp_buf;
static lv_disp_drv_t disp_drv;
/**
  * @brief  屏幕刷新回调函数
  * @param  disp:屏幕驱动地址
  * @param  area:刷新区域
  * @param  color_p:刷新缓冲区地址
  * @retval 无
  */
static void disp_flush_cb(lv_disp_drv_t* disp, const lv_area_t* area, lv_color_t* color_p)
{
    SCREEN_CLASS* screen = (SCREEN_CLASS*) disp->user_data;

    int32_t w = (area->x2 - area->x1 + 1);
    int32_t h = (area->y2 - area->y1 + 1);

    screen->startWrite();
    screen->setAddrWindow(area->x1, area->y1, w, h);
    screen->pushColors((uint16_t*) (&color_p->full), w * h, true);
    screen->endWrite();

    lv_disp_flush_ready(disp);
}

static void disp_wait_cb(lv_disp_drv_t* disp_drv)
{
}

/**
  * @brief  屏幕初始化
  * @param  无
  * @retval 无
  */
void lv_port_disp_init(SCREEN_CLASS* scr)
{
    lv_disp_buf_p = static_cast<lv_color_t*>(malloc((240 * 240 /2) * sizeof(lv_color_t)));
    if (lv_disp_buf_p == nullptr)
        LV_LOG_WARN("lv_port_disp_init malloc failed!\n");

    lv_disp_draw_buf_init(&disp_buf, lv_disp_buf_p, nullptr, (240 * 240 /2) );

    /*Initialize the display*/
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = 240;
    disp_drv.ver_res = 240;
    disp_drv.flush_cb = disp_flush_cb;
    disp_drv.wait_cb = disp_wait_cb;
    disp_drv.draw_buf = &disp_buf;
    disp_drv.user_data = scr;
    lv_disp_drv_register(&disp_drv);
}
