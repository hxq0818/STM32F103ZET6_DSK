/*
 * @Descripttion: 
 * @version: 
 * @Author: xiaoqing.huang
 * @Date: 2023-04-06 19:46:24
 * @LastEditors: 
 * @LastEditTime: 2023-04-18 21:02:39
 */
#ifndef __KEY_H
#define	__KEY_H


#include "stm32f10x.h"

#include "user_project_config.h"

//  引脚定义
#ifndef KEY_UP_FUNCTION_SUPPORT
#define KEY_UP_FUNCTION_SUPPORT 1

#endif


 /** 按键按下标置宏
	*  按键按下为高电平，设置 KEY_ON=1， KEY_OFF=0
	*  若按键按下为低电平，把宏设置成KEY_ON=0 ，KEY_OFF=1 即可
	*/
#define KEY_ON	0
#define KEY_OFF	1

void Key_GPIO_Config(void);
uint8_t Key_Scan(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin);


#endif /* __KEY_H */

