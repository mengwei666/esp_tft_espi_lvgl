#include "lv_examples.h"

void lv_example_img_1(void)
{
    LV_IMG_DECLARE(qq);
    lv_obj_t * img1 = lv_img_create(lv_scr_act());
    lv_img_set_src(img1, &qq);
    lv_obj_align(img1, LV_ALIGN_CENTER, 0, -20);
    lv_obj_set_size(img1, 40, 40);
}

void lv_example_img_2(void)
{
    LV_IMG_DECLARE(logo);
    lv_obj_t * img1 = lv_img_create(lv_scr_act());
    lv_img_set_src(img1, &logo);
    lv_obj_set_size(img1, 240, 240);
}

void lv_example_img_3(void)
{
    LV_IMG_DECLARE(wangxia);
    lv_obj_t * img1 = lv_img_create(lv_scr_act());
    lv_img_set_src(img1, &wangxia);
    lv_obj_set_size(img1, 240, 240);
}

void lv_example_img_4(void)
{
    LV_IMG_DECLARE(xueshu);
    lv_obj_t * img1 = lv_img_create(lv_scr_act());
    lv_img_set_src(img1, &xueshu);
    lv_obj_set_size(img1, 240, 240);
}

void lv_example_img_5(void)
{
    LV_IMG_DECLARE(dog);
    lv_obj_t * img1 = lv_img_create(lv_scr_act());
    lv_img_set_src(img1, &dog);
    lv_obj_set_size(img1, 240, 240);
}

void lv_example_img_6(void)
{
    LV_IMG_DECLARE(baby);
    lv_obj_t * img1 = lv_img_create(lv_scr_act());
    lv_img_set_src(img1, &baby);
    lv_obj_set_size(img1, 240, 240);
}