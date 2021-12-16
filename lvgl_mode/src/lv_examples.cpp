#include "lv_examples.h"

void lv_example_img_1(void)
{
    LV_IMG_DECLARE(img_cogwheel_argb);
    lv_obj_t * img1 = lv_img_create(lv_scr_act());
    lv_img_set_src(img1, &img_cogwheel_argb);
    lv_obj_align(img1, LV_ALIGN_CENTER, 0, -20);
    lv_obj_set_size(img1, 200, 200);
}

void lv_example_img_2(void)
{
    LV_IMG_DECLARE(img_src_arm);
    lv_obj_t * img1 = lv_img_create(lv_scr_act());
    lv_img_set_src(img1, &img_src_arm);
    lv_obj_set_size(img1, 240, 240);
}

void lv_example_img_3(void)
{
    LV_IMG_DECLARE(img_qq);
    lv_obj_t * img1 = lv_img_create(lv_scr_act());
    lv_img_set_src(img1, &img_qq);
    lv_obj_set_size(img1, 234, 240);
}