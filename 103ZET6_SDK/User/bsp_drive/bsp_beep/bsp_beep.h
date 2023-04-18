/*
 * @Descripttion: 
 * @version: 
 * @Author: xiaoqing.huang
 * @Date: 2023-04-05 20:53:00
 * @LastEditors: 
 * @LastEditTime: 2023-04-18 21:02:15
 */
#ifndef __BEEP_H
#define	__BEEP_H


#include "stm32f10x.h"

#include "user_project_config.h"

/* 定义蜂鸣器连接的GPIO端口, 用户只需要修改下面的代码即可改变控制的蜂鸣器引脚 */
#ifndef BEEP_FUNCTION_SUPPORT
#define BEEP_FUNCTION_SUPPORT 1
#define BEEP_GPIO_PORT    	GPIOB			              /* GPIO端口 */
#define BEEP_GPIO_CLK 	    RCC_APB2Periph_GPIOB		/* GPIO端口时钟 */
#define BEEP_GPIO_PIN		  GPIO_Pin_8			        /* 连接到蜂鸣器的GPIO */
#endif

///* 高电平时，蜂鸣器响 */
//#define ON  1
//#define OFF 0

/* 带参宏，可以像内联函数一样使用 */
#define BEEP(a)	if (a)	\
					GPIO_SetBits(BEEP_GPIO_PORT,BEEP_GPIO_PIN);\
					else		\
					GPIO_ResetBits(BEEP_GPIO_PORT,BEEP_GPIO_PIN)

void BEEP_GPIO_Config(void);
					
#endif /* __BEEP_H */
