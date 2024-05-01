# 2021-12-15

* done
  * 测试成功lvgl显示图片内容。
* todo
  * 显示自定义图片

# 2021-12-16

* done
  * 测试成功lvgl显示图片内容。
  * 显示自定义图片
  * lvgl 在线转换图片网站： https://lvgl.io/tools/imageconverter
* todo
  * 显示动态图片

# 2021-12-17

* done

  * 测试成功lvgl显示图片内容。
  * 显示自定义图片
  * lvgl 在线转换图片网站： https://lvgl.io/tools/imageconverter
  * 在循环里加lvgl 心跳

  ```cpp
  void loop() 
  {
      lv_tick_inc(5); 
      lv_task_handler();
  }
  ```

  * 显示动态图片(例程)
  * 显示动态图片（太空人）
* todo


//The custom code of screen.

externlv_indev_t*indev_encoder;

lv_group_t*group=lv_group_create();

lv_indev_set_group(indev_encoder,group);   //将组绑定到输入设备

lv_group_set_editing(group,false);   //导航模式

lv_group_add_obj(group,ui->screen_btn_1);
