# 开发环境
## 1.硬件
* 开发板：ESP32_PICO_KIT_V4.1 (主控芯片：esp32-pico-d4)
* 屏幕：中景园1.54寸TFT屏（12pin - st7789）
* 接线：
    * 屏幕 ------ 开发板
    * GND ------ GND
    * VCC ------ VCC(3.3V)
    * SCL ------ GPIO18
    * SDA ------ GPIO23
    * RES ------ GPIO4
    * DC ------ GPIO2
    * CS ------ GND
    * BLK ------ GPIO12
## 2.软件
* ubuntu(20.04.3.LTS)
* vscode(v1.63)
* platformio(v2.4.0)
* TFT_eSPI(v2.3.84) 地址:https://github.com/Bodmer/TFT_eSPI 
* lgvl(v8.1) 地址：https://github.com/lvgl/lvgl/tree/release/v8.1
# 开发过程
## 添加lvgl到工程的lib.
> 将lvgl/lv_conf_template.h复制到lvgl目录旁边，并将其重命名为lv_conf.h。打开文件并将开头的更改为以启用其内容。#if 0#if 1
> 新建lv_port_disp.cpp和lv_port_disp.h文件 新建测试文件修改mian.cpp文件如下图所示
