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
#include "lv_port_indev.h"
#include "lv_examples.h"

#include "custom/gui_guider.h"
#include "custom/custom.h"

typedef TFT_eSPI SCREEN_CLASS;
#define CONFIG_SCREEN_BLK_PIN       12

lv_ui guider_ui;




/* Power */
#define CONFIG_POWER_EN_PIN         21
/* Battery */
#define CONFIG_BAT_DET_PIN          37
#define CONFIG_BAT_CHG_DET_PIN      38

void Encoder_Init(void)
{
    pinMode(CONFIG_ENCODER_A_PIN, INPUT_PULLUP);
    pinMode(CONFIG_ENCODER_B_PIN, INPUT_PULLUP);
    pinMode(CONFIG_ENCODER_PUSH_PIN, INPUT_PULLUP);
}

void Encoder_Update(void)
{
  // Serial.print("PUSH_PIN: ");
  // Serial.println( digitalRead(CONFIG_ENCODER_PUSH_PIN));


}



void Power_Init()
{
    pinMode(CONFIG_BAT_CHG_DET_PIN, INPUT); // 电源充电管理引脚

    /*电源使能保持*/
    Serial.println("Power: Waiting...");
    pinMode(CONFIG_POWER_EN_PIN, OUTPUT); 
    digitalWrite(CONFIG_POWER_EN_PIN, LOW);

    digitalWrite(CONFIG_POWER_EN_PIN, HIGH);
    Serial.println("Power: ON");

}


void setup() {


  Serial.begin(115200);
  Serial.println("Begin");

  Power_Init();

  Encoder_Init();


  /* 屏幕背光打开设置 */
  pinMode(CONFIG_SCREEN_BLK_PIN, OUTPUT);
  digitalWrite(CONFIG_SCREEN_BLK_PIN, HIGH);

  /* 屏幕初始化 */
  static SCREEN_CLASS screen;
  screen.begin();
  screen.setRotation(0);   
  screen.fillScreen(TFT_BLACK);  



  /* lvgl初始化 */
  lv_init();
  lv_port_disp_init(&screen);
  lv_port_indev_init();  //输入设备初始化
  // lv_example_img_7();
  // setup_ui(&guider_ui);

  setup_ui(&guider_ui);
  // events_init(&guider_ui);



}

void loop() {
  Encoder_Update();
  lv_tick_inc(5); 
 	lv_task_handler();
}
