/*
 * @brief: led应用函数接口
 * @version: V1.0
 * @Author: xiaoqing.huang
 * @Date: 2023-04-04 21:42:21
 * @LastEditors: LAPTOP-4DIHEQ1Q
 * @LastEditTime: 2023-04-21 10:44:49
 */
  
#ifndef __LED_H
#define	__LED_H


#include "stm32f10x.h"

#include "user_project_config.h"



/* 带参宏，可以像内联函数一样使用 */
#define LED0(a)	if (a)	\
					GPIO_SetBits(LED0_GPIO_PORT,LED0_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LED0_GPIO_PORT,LED0_GPIO_PIN)

#define LED1(a)	if (a)	\
					GPIO_SetBits(LED1_GPIO_PORT,LED1_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LED1_GPIO_PORT,LED1_GPIO_PIN)





void LED_GPIO_Config(void);

#endif /* __LED_H */
