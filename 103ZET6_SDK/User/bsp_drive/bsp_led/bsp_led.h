/*
 * @brief: led应用函数接口
 * @version: V1.0
 * @Author: xiaoqing.huang
 * @Date: 2023-04-04 21:42:21
 * @LastEditors: LAPTOP-4DIHEQ1Q
 * @LastEditTime: 2023-04-19 20:10:07
 */
  
#ifndef __LED_H
#define	__LED_H


#include "stm32f10x.h"

#include "user_project_config.h"

/* 定义LED连接的GPIO端口, 用户只需要修改下面的代码即可改变控制的蜂鸣器引脚 */
// LED1
#ifndef LED1_FUNCTION_SUPPROT
#define LED1_FUNCTION_SUPPORT 1
#define LED1_GPIO_PORT    	GPIOE			              /* GPIO端口 */
#define LED1_GPIO_CLK 	    RCC_APB2Periph_GPIOE		/* GPIO端口时钟 */
#define LED1_GPIO_PIN				GPIO_Pin_5			        /* 连接到SCL时钟线的GPIO */
#endif


// LED0
#ifndef LED0_FUNCTION_SUPPORT
#define LED0_FUNCTION_SUPPROT 1
#define LED0_GPIO_PORT    	GPIOB			             /* GPIO端口 */
#define LED0_GPIO_CLK 	    RCC_APB2Periph_GPIOB		/* GPIO端口时钟 */
#define LED0_GPIO_PIN				GPIO_Pin_5			        /* 连接到SCL时钟线的GPIO */
#endif




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
