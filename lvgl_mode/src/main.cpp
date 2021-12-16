/*
 * @Author: your name
 * @Date: 2021-12-09 15:06:00
 * @LastEditTime: 2021-12-09 15:31:48
 * @LastEditors: your name
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /TFT_eSPI_mode/src/main.cpp
 */
#include <Arduino.h>
#include "TFT_eSPI.h"
#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_examples.h"
typedef TFT_eSPI SCREEN_CLASS;

#define CONFIG_SCREEN_BLK_PIN       12

void setup() {

  pinMode(CONFIG_SCREEN_BLK_PIN, OUTPUT);
  digitalWrite(CONFIG_SCREEN_BLK_PIN, HIGH);

  static SCREEN_CLASS screen;

  /* 屏幕初始化 */
  screen.begin();
  screen.setRotation(0);   
  screen.fillScreen(TFT_BLACK);  

  /* lvgl初始化 */
  lv_init();
  lv_port_disp_init(&screen);

  lv_example_img_2();

}

void loop() {
 	lv_task_handler();
}
