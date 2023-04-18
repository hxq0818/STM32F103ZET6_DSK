#ifndef __USER_PROJECT_CONFIG_H
#define	__USER_PROJECT_CONFIG_H


#include "stm32f10x.h"

/* 使用log打印 */
#define DEBUG_SUPPORT 1


/* 高低电平 */
#define HIGH_LEVEL  	1			/* 高电平*/
#define HOW_LEVEL 		0			/* 抵电平*/

/******** 定义板载LED *********/
//LED0
#ifndef LED0_FUNCTION_SUPPORT
#define LED0_FUNCTION_SUPPORT 1
#define LED0_GPIO_PORT    	GPIOB			              /* GPIO端口 */
#define LED0_GPIO_CLK 	    RCC_APB2Periph_GPIOE		/* GPIO端口时钟 */
#define LED0_GPIO_PIN				GPIO_Pin_5			        /* 连接到SCL时钟线的GPIO */
#else
#define LED0_FUNCTION_SUPPORT 0
#endif

//LED1
#ifndef LED1_FUNCTION_SUPPROT
#define LED1_FUNCTION_SUPPROT 1
#define LED1_GPIO_PORT    	GPIOE			              /* GPIO端口 */
#define LED1_GPIO_CLK 	    RCC_APB2Periph_GPIOB		/* GPIO端口时钟 */
#define LED1_GPIO_PIN				GPIO_Pin_5			        /* 连接到SCL时钟线的GPIO */
#else
#define LED1_FUNCTION_SUPPROT 0
#endif
/******** 定义板载LED *********/

/******** 定义板载有源蜂鸣器 *********/
//BEEP
#ifndef BEEP_FUNCTION_SUPPORT
#define BEEP_FUNCTION_SUPPORT 1
#define BEEP_GPIO_PORT    	GPIOB			              /* GPIO端口 */
#define BEEP_GPIO_CLK 	    RCC_APB2Periph_GPIOB		/* GPIO端口时钟 */
#define BEEP_GPIO_PIN		  	GPIO_Pin_8			        /* 连接到蜂鸣器的GPIO */
#else
#define BEEP_FUNCTION_SUPPORT 0
#endif


/******** 定义板载有源蜂鸣器 *********/

/******** 定义板载按键中断 *********/
//KEY_UP
#ifndef KEY_UP_EXTI_FUNCTION_SUPPORT
#define KEY_UP_EXTI_FUNCTION_SUPPORT 1
#define KEY_UP_EXTI_GPIO_PORT    							GPIOA			              /* GPIO端口 */
#define KEY_UP_EXTI_GPIO_CLK 	    						RCC_APB2Periph_GPIOA		/* GPIO端口时钟 */
#define KEY_UP_EXTI_GPIO_PIN		  						GPIO_Pin_0			        /* 连接KEY_UP管脚的GPIO */
#define KEY_UP_EXTI_GPIO_MODE									GPIO_Mode_IPD    				/* 下拉输入 */
#define KEY_UP_EXTI_IRQ  											EXTI0_IRQn							/* 中断源 EXTI0_IRQn*/
#define KEY_UP_EXTI_IRQ_PREEMPTION_PRIORITY		2												/* 配置抢占优先级 */
#define KEY_UP_EXTI_IRQ_SUB_PRIORITY					3												/* 配置子优先级 */
#define KEY_UP_EXTI_LINE         							EXTI_Line0							/* 中断线路 */
#define KEY_UP_EXTI_TRIGGER			 							EXTI_Trigger_Rising			/* 中断出发方式 */
#else
#define KEY_UP_EXTI_FUNCTION_SUPPORT 0
#endif

//KEY0
#ifndef KEY0_EXTI_FUNCTION_SUPPORT
#define KEY0_EXTI_FUNCTION_SUPPORT 1
#define KEY0_EXTI_GPIO_PORT    							GPIOE			              /* GPIO端口 */
#define KEY0_EXTI_GPIO_CLK 	    						RCC_APB2Periph_GPIOE		/* GPIO端口时钟 */
#define KEY0_EXTI_GPIO_PIN		  						GPIO_Pin_4			        /* 连接KEY0管脚的GPIO */
#define KEY0_EXTI_GPIO_MODE									GPIO_Mode_IPU 					/* 上拉输入 */
#define KEY0_EXTI_IRQ  											EXTI4_IRQn							/* 中断源 */
#define KEY0_EXTI_IRQ_PREEMPTION_PRIORITY		2												/* 配置抢占优先级 */
#define KEY0_EXTI_IRQ_SUB_PRIORITY					0												/* 配置子优先级 */
#define KEY0_EXTI_LINE         							EXTI_Line4							/* 中断线路 */
#define KEY0_EXTI_TRIGGER			 							EXTI_Trigger_Falling		/* 中断出发方式 */
#else
#define KEY0_FUNCTION_SUPPORT 0
#endif

//KEY1
#ifndef KEY1_EXTI_FUNCTION_SUPPORT
#define KEY1_EXTI_FUNCTION_SUPPORT 1
#define KEY1_EXTI_GPIO_PORT    							GPIOE			              /* GPIO端口 */
#define KEY1_EXTI_GPIO_CLK 	    						RCC_APB2Periph_GPIOE		/* GPIO端口时钟 */
#define KEY1_EXTI_GPIO_PIN		  						GPIO_Pin_3			        /* 连接KEY0管脚的GPIO */
#define KEY1_EXTI_GPIO_MODE									GPIO_Mode_IPU 					/* 上拉输入 */
#define KEY1_EXTI_IRQ  											EXTI3_IRQn							/* 中断源 */
#define KEY1_EXTI_IRQ_PREEMPTION_PRIORITY		2												/* 配置抢占优先级 */
#define KEY1_EXTI_IRQ_SUB_PRIORITY					1 											/* 配置子优先级 */
#define KEY1_EXTI_LINE         							EXTI_Line3							/* 中断线路 */
#define KEY1_EXTI_TRIGGER			 							EXTI_Trigger_Falling		/* 中断出发方式 */
#else
#define KEY1_FUNCTION_SUPPORT 0
#endif

//KEY2
#ifndef KEY2_EXTI_FUNCTION_SUPPORT
#define KEY2_EXTI_FUNCTION_SUPPORT 1
#define KEY2_EXTI_GPIO_PORT    	GPIOE			              /* GPIO端口 */
#define KEY2_EXTI_GPIO_CLK 	    RCC_APB2Periph_GPIOE		/* GPIO端口时钟 */
#define KEY2_EXTI_GPIO_PIN		  GPIO_Pin_2			        /* 连接KEY0管脚的GPIO */
#define KEY2_EXTI_GPIO_MODE									GPIO_Mode_IPU 					/* 上拉输入 */
#define KEY2_EXTI_IRQ  											EXTI2_IRQn							/* 中断源 */
#define KEY2_EXTI_IRQ_PREEMPTION_PRIORITY		2												/* 配置抢占优先级 */
#define KEY2_EXTI_IRQ_SUB_PRIORITY					2 											/* 配置子优先级 */
#define KEY2_EXTI_LINE         							EXTI_Line2							/* 中断线路 */
#define KEY2_EXTI_TRIGGER			 							EXTI_Trigger_Falling		/* 中断出发方式 */
#else
#define KEY1_FUNCTION_SUPPORT 0
#endif
/******** 定义板载按键中断 *********/


#endif /* __USER_PROJECT_CONFIG_H */
