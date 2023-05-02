/*
 * @brief: 用户项目功能配置文件
 * @Author: xiaoqing.huang
 * @version: V1.0
 * @Date: 2023-04-04 21:42:21
 * @LastEditors: LAPTOP-4DIHEQ1Q
 * @LastEditTime: 2023-04-23 17:14:38
 */
#ifndef __USER_PROJECT_CONFIG_H
#define	__USER_PROJECT_CONFIG_H


#include "stm32f10x.h"
#include "misc.h"
#include "stm32f10x_gpio.h"

/* 使用log打印 */
#define DEBUG_SUPPORT 1

/* 板载LED0功能 */
#define LED0_FUNCTION_SUPPORT 1
/* 板载LED1功能 */
#define LED1_FUNCTION_SUPPROT 1
/* 板载BEEP功能 */
#define BEEP_FUNCTION_SUPPORT 1
/* 板载KEY_UP功能 */
#define KEY_UP_EXTI_FUNCTION_SUPPORT 0              /* 由于开启了定时器5的输入捕获，所以不开启KEY_UP按键的中断功能*/
/* 板载KEY0功能 */
#define KEY0_EXTI_FUNCTION_SUPPORT 1
/* 板载KEY1功能 */
#define KEY1_EXTI_FUNCTION_SUPPORT 1
/* 板载KEY2功能 */
#define KEY2_EXTI_FUNCTION_SUPPORT 1
/* USART串口功能 */
#define USART1_FUNCTION_SUPPORT 1
/* 定时器功能 */
#define TIME1_FUNCTION_SUPPORT 0
#define TIME2_FUNCTION_SUPPORT 0
#define TIME3_FUNCTION_SUPPORT 0
#define TIME4_FUNCTION_SUPPORT 0
#define TIME5_FUNCTION_SUPPORT 1        /* 当前开启定时器5的通道1的输入捕获功能，PA0管脚*/
#define TIME6_FUNCTION_SUPPORT 1
#define TIME7_FUNCTION_SUPPORT 1
#define TIME8_FUNCTION_SUPPORT 0

/* 高低电平 */
#define HIGH_LEVEL  	1			/* 高电平*/
#define HOW_LEVEL 		0			/* 抵电平*/

/******** 定义板载LED *********/
//LED0
#if LED0_FUNCTION_SUPPORT
#define LED0_GPIO_PORT    	GPIOB			            /* GPIO端口 */
#define LED0_GPIO_CLK 	    RCC_APB2Periph_GPIOE		/* GPIO端口时钟 */
#define LED0_GPIO_PIN		GPIO_Pin_5			        /* 连接到SCL时钟线的GPIO */
#endif

//LED1
#if LED1_FUNCTION_SUPPROT
#define LED1_GPIO_PORT    	GPIOE			            /* GPIO端口 */
#define LED1_GPIO_CLK 	    RCC_APB2Periph_GPIOB		/* GPIO端口时钟 */
#define LED1_GPIO_PIN		GPIO_Pin_5			        /* 连接到SCL时钟线的GPIO */
#endif
/******** 定义板载LED *********/

/******** 定义板载有源蜂鸣器 *********/
//BEEP
#if BEEP_FUNCTION_SUPPORT
#define BEEP_GPIO_PORT    	GPIOB			            /* GPIO端口 */
#define BEEP_GPIO_CLK 	    RCC_APB2Periph_GPIOB		/* GPIO端口时钟 */
#define BEEP_GPIO_PIN		GPIO_Pin_8			        /* 连接到蜂鸣器的GPIO */
#endif
/******** 定义板载有源蜂鸣器 *********/

/******** 定义板载按键中断 *********/
//KEY_UP
#if KEY_UP_EXTI_FUNCTION_SUPPORT
#define KEY_UP_EXTI_GPIO_PORT    				GPIOA			            /* GPIO端口 */
#define KEY_UP_EXTI_GPIO_CLK 	    			RCC_APB2Periph_GPIOA		/* GPIO端口时钟 */
#define KEY_UP_EXTI_GPIO_PIN		  			GPIO_Pin_0			        /* 连接KEY_UP管脚的GPIO */
#define KEY_UP_EXTI_GPIO_MODE					GPIO_Mode_IPD    			/* 下拉输入 */
#define KEY_UP_EXTI_IRQ  						EXTI0_IRQn					/* 中断源 EXTI0_IRQn*/
#define KEY_UP_EXTI_IRQ_PREEMPTION_PRIORITY		2							/* 配置抢占优先级 */
#define KEY_UP_EXTI_IRQ_SUB_PRIORITY			3							/* 配置子优先级 */
#define KEY_UP_EXTI_LINE         				EXTI_Line0					/* 中断线路 */
#define KEY_UP_EXTI_TRIGGER			 			EXTI_Trigger_Rising			/* 中断出发方式 */
#endif

//KEY0
#if KEY0_EXTI_FUNCTION_SUPPORT
#define KEY0_EXTI_GPIO_PORT    					GPIOE			            /* GPIO端口 */
#define KEY0_EXTI_GPIO_CLK 	    				RCC_APB2Periph_GPIOE		/* GPIO端口时钟 */
#define KEY0_EXTI_GPIO_PIN		  				GPIO_Pin_4			        /* 连接KEY0管脚的GPIO */
#define KEY0_EXTI_GPIO_MODE						GPIO_Mode_IPU 				/* 上拉输入 */
#define KEY0_EXTI_IRQ  							EXTI4_IRQn					/* 中断源 */
#define KEY0_EXTI_IRQ_PREEMPTION_PRIORITY		2							/* 配置抢占优先级 */
#define KEY0_EXTI_IRQ_SUB_PRIORITY				0							/* 配置子优先级 */
#define KEY0_EXTI_LINE         					EXTI_Line4					/* 中断线路 */
#define KEY0_EXTI_TRIGGER			 			EXTI_Trigger_Falling		/* 中断出发方式 */
#endif

//KEY1
#if KEY1_EXTI_FUNCTION_SUPPORT
#define KEY1_EXTI_GPIO_PORT    					GPIOE			            /* GPIO端口 */
#define KEY1_EXTI_GPIO_CLK 	    				RCC_APB2Periph_GPIOE		/* GPIO端口时钟 */
#define KEY1_EXTI_GPIO_PIN		  				GPIO_Pin_3			        /* 连接KEY0管脚的GPIO */
#define KEY1_EXTI_GPIO_MODE						GPIO_Mode_IPU 				/* 上拉输入 */
#define KEY1_EXTI_IRQ  							EXTI3_IRQn					/* 中断源 */
#define KEY1_EXTI_IRQ_PREEMPTION_PRIORITY		2							/* 配置抢占优先级 */
#define KEY1_EXTI_IRQ_SUB_PRIORITY				1 							/* 配置子优先级 */
#define KEY1_EXTI_LINE         					EXTI_Line3					/* 中断线路 */
#define KEY1_EXTI_TRIGGER			 			EXTI_Trigger_Falling		/* 中断出发方式 */
#endif

//KEY2
#if KEY2_EXTI_FUNCTION_SUPPORT
#define KEY2_EXTI_GPIO_PORT    	                GPIOE			            /* GPIO端口 */
#define KEY2_EXTI_GPIO_CLK 	                    RCC_APB2Periph_GPIOE		/* GPIO端口时钟 */
#define KEY2_EXTI_GPIO_PIN		                GPIO_Pin_2			        /* 连接KEY0管脚的GPIO */
#define KEY2_EXTI_GPIO_MODE						GPIO_Mode_IPU 				/* 上拉输入 */
#define KEY2_EXTI_IRQ  							EXTI2_IRQn					/* 中断源 */
#define KEY2_EXTI_IRQ_PREEMPTION_PRIORITY		2							/* 配置抢占优先级 */
#define KEY2_EXTI_IRQ_SUB_PRIORITY				2 							/* 配置子优先级 */
#define KEY2_EXTI_LINE         					EXTI_Line2					/* 中断线路 */
#define KEY2_EXTI_TRIGGER			 			EXTI_Trigger_Falling		/* 中断出发方式 */
#endif
/******** 定义板载按键中断 *********/

/* 定义板载USART中断 */
/** 
  * 串口宏定义，不同的串口挂载的总线和IO不一样，移植时需要修改这几个宏
	* 1-修改总线时钟的宏，uart1挂载到apb2总线，其他uart挂载到apb1总线
	* 2-修改GPIO的宏
  */
#if USART1_FUNCTION_SUPPORT
#define  DEBUG_USARTx                   USART1                      /* 串口1-USART1 */
#define  DEBUG_USART_CLK                RCC_APB2Periph_USART1       /* usart时钟 */
#define  DEBUG_USART_APBxClkCmd         RCC_APB2PeriphClockCmd
#define  DEBUG_USART_BAUDRATE           115200                      /* 设置波特率 */
// USART GPIO 引脚宏定义
#define  DEBUG_USART_GPIO_CLK           (RCC_APB2Periph_GPIOA)      /* GPIO端口时钟 */
#define  DEBUG_USART_GPIO_APBxClkCmd    RCC_APB2PeriphClockCmd
    
#define  DEBUG_USART_TX_GPIO_PORT       GPIOA                       /* 发送管脚GPIO端口 */
#define  DEBUG_USART_TX_GPIO_PIN        GPIO_Pin_9                  /* 发送管脚的GPIO */
#define  DEBUG_USART_RX_GPIO_PORT       GPIOA                       /* 接收管脚GPIO端口 */
#define  DEBUG_USART_RX_GPIO_PIN        GPIO_Pin_10                 /* 接收管脚的GPIO */

#define  DEBUG_USART_IRQ                USART1_IRQn                 /* 中断源 */
#define  DEBUG_USART_IRQHandler         USART1_IRQHandler           /* 中断函数 */
#endif
/* 定义板载USART中断 */

/* 定义板载定时器*/
#if TIME1_FUNCTION_SUPPORT

#endif

#if TIME2_FUNCTION_SUPPORT

#endif

#if TIME3_FUNCTION_SUPPORT

#endif

#if TIME4_FUNCTION_SUPPORT

#endif

#if TIME5_FUNCTION_SUPPORT/************通用定时器TIM参数定义，只限TIM2、3、4、5************/
// 当使用不同的定时器的时候，对应的GPIO是不一样的，这点要注意
// 我们这里默认使用TIM5
#define            TIME5_GENERAL_TIM                   TIM5
#define            TIME5_GENERAL_TIM_CLK               RCC_APB1Periph_TIM5
#define            TIME5_GENERAL_TIM_PERIOD            0XFFFF
#define            TIME5_GENERAL_TIM_PSC              (72-1)

// TIM 输入捕获通道GPIO相关宏定义
#define            TIME5_GENERAL_TIM_CH1_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            TIME5_GENERAL_TIM_CH1_PORT          GPIOA
#define            TIME5_GENERAL_TIM_CH1_PIN           GPIO_Pin_0
#define            TIME5_GENERAL_TIM_CHANNEL_x         TIM_Channel_1

// 中断相关宏定义
#define            TIME5_GENERAL_TIM_IT_CCx            TIM_IT_CC1
#define            TIME5_GENERAL_TIM_IRQ               TIM5_IRQn
#define            TIME5_GENERAL_TIM_INT_FUN           TIM5_IRQHandler

// 测量的起始边沿
#define            GENERAL_TIM_STRAT_ICPolarity                TIM_ICPolarity_Rising
// 测量的结束边沿
#define            GENERAL_TIM_END_ICPolarity                  TIM_ICPolarity_Falling
#endif

#if TIME6_FUNCTION_SUPPORT
#define  TIME6_BASIC_TIM                   TIM6
#define  TIME6_BASIC_TIM_APBxClock_FUN     RCC_APB1PeriphClockCmd
#define  TIME6_BASIC_TIM_CLK               RCC_APB1Periph_TIM6
#define  TIME6_BASIC_TIM_Period            (1000-1)
#define  TIME6_BASIC_TIM_Prescaler         71
#define  TIME6_BASIC_TIM_IRQ               TIM6_IRQn
#define  TIME6_BASIC_TIM_IRQHandler        TIM6_IRQHandler
#endif

#if TIME7_FUNCTION_SUPPORT
#define  TIME7_BASIC_TIM                   TIM7
#define  TIME7_BASIC_TIM_APBxClock_FUN     RCC_APB1PeriphClockCmd
#define  TIME7_BASIC_TIM_CLK               RCC_APB1Periph_TIM7
#define  TIME7_BASIC_TIM_Period            1000-1
#define  TIME7_BASIC_TIM_Prescaler         71
#define  TIME7_BASIC_TIM_IRQ               TIM7_IRQn
#define  TIME7_BASIC_TIM_IRQHandler        TIM7_IRQHandler
#endif

#if TIME8_FUNCTION_SUPPORT

#endif
/* 定义板载定时器*/

#endif /* __USER_PROJECT_CONFIG_H */
