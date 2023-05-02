/*
 * @brief: �û���Ŀ���������ļ�
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

/* ʹ��log��ӡ */
#define DEBUG_SUPPORT 1

/* ����LED0���� */
#define LED0_FUNCTION_SUPPORT 1
/* ����LED1���� */
#define LED1_FUNCTION_SUPPROT 1
/* ����BEEP���� */
#define BEEP_FUNCTION_SUPPORT 1
/* ����KEY_UP���� */
#define KEY_UP_EXTI_FUNCTION_SUPPORT 0              /* ���ڿ����˶�ʱ��5�����벶�����Բ�����KEY_UP�������жϹ���*/
/* ����KEY0���� */
#define KEY0_EXTI_FUNCTION_SUPPORT 1
/* ����KEY1���� */
#define KEY1_EXTI_FUNCTION_SUPPORT 1
/* ����KEY2���� */
#define KEY2_EXTI_FUNCTION_SUPPORT 1
/* USART���ڹ��� */
#define USART1_FUNCTION_SUPPORT 1
/* ��ʱ������ */
#define TIME1_FUNCTION_SUPPORT 0
#define TIME2_FUNCTION_SUPPORT 0
#define TIME3_FUNCTION_SUPPORT 0
#define TIME4_FUNCTION_SUPPORT 0
#define TIME5_FUNCTION_SUPPORT 1        /* ��ǰ������ʱ��5��ͨ��1�����벶���ܣ�PA0�ܽ�*/
#define TIME6_FUNCTION_SUPPORT 1
#define TIME7_FUNCTION_SUPPORT 1
#define TIME8_FUNCTION_SUPPORT 0

/* �ߵ͵�ƽ */
#define HIGH_LEVEL  	1			/* �ߵ�ƽ*/
#define HOW_LEVEL 		0			/* �ֵ�ƽ*/

/******** �������LED *********/
//LED0
#if LED0_FUNCTION_SUPPORT
#define LED0_GPIO_PORT    	GPIOB			            /* GPIO�˿� */
#define LED0_GPIO_CLK 	    RCC_APB2Periph_GPIOE		/* GPIO�˿�ʱ�� */
#define LED0_GPIO_PIN		GPIO_Pin_5			        /* ���ӵ�SCLʱ���ߵ�GPIO */
#endif

//LED1
#if LED1_FUNCTION_SUPPROT
#define LED1_GPIO_PORT    	GPIOE			            /* GPIO�˿� */
#define LED1_GPIO_CLK 	    RCC_APB2Periph_GPIOB		/* GPIO�˿�ʱ�� */
#define LED1_GPIO_PIN		GPIO_Pin_5			        /* ���ӵ�SCLʱ���ߵ�GPIO */
#endif
/******** �������LED *********/

/******** ���������Դ������ *********/
//BEEP
#if BEEP_FUNCTION_SUPPORT
#define BEEP_GPIO_PORT    	GPIOB			            /* GPIO�˿� */
#define BEEP_GPIO_CLK 	    RCC_APB2Periph_GPIOB		/* GPIO�˿�ʱ�� */
#define BEEP_GPIO_PIN		GPIO_Pin_8			        /* ���ӵ���������GPIO */
#endif
/******** ���������Դ������ *********/

/******** ������ذ����ж� *********/
//KEY_UP
#if KEY_UP_EXTI_FUNCTION_SUPPORT
#define KEY_UP_EXTI_GPIO_PORT    				GPIOA			            /* GPIO�˿� */
#define KEY_UP_EXTI_GPIO_CLK 	    			RCC_APB2Periph_GPIOA		/* GPIO�˿�ʱ�� */
#define KEY_UP_EXTI_GPIO_PIN		  			GPIO_Pin_0			        /* ����KEY_UP�ܽŵ�GPIO */
#define KEY_UP_EXTI_GPIO_MODE					GPIO_Mode_IPD    			/* �������� */
#define KEY_UP_EXTI_IRQ  						EXTI0_IRQn					/* �ж�Դ EXTI0_IRQn*/
#define KEY_UP_EXTI_IRQ_PREEMPTION_PRIORITY		2							/* ������ռ���ȼ� */
#define KEY_UP_EXTI_IRQ_SUB_PRIORITY			3							/* ���������ȼ� */
#define KEY_UP_EXTI_LINE         				EXTI_Line0					/* �ж���· */
#define KEY_UP_EXTI_TRIGGER			 			EXTI_Trigger_Rising			/* �жϳ�����ʽ */
#endif

//KEY0
#if KEY0_EXTI_FUNCTION_SUPPORT
#define KEY0_EXTI_GPIO_PORT    					GPIOE			            /* GPIO�˿� */
#define KEY0_EXTI_GPIO_CLK 	    				RCC_APB2Periph_GPIOE		/* GPIO�˿�ʱ�� */
#define KEY0_EXTI_GPIO_PIN		  				GPIO_Pin_4			        /* ����KEY0�ܽŵ�GPIO */
#define KEY0_EXTI_GPIO_MODE						GPIO_Mode_IPU 				/* �������� */
#define KEY0_EXTI_IRQ  							EXTI4_IRQn					/* �ж�Դ */
#define KEY0_EXTI_IRQ_PREEMPTION_PRIORITY		2							/* ������ռ���ȼ� */
#define KEY0_EXTI_IRQ_SUB_PRIORITY				0							/* ���������ȼ� */
#define KEY0_EXTI_LINE         					EXTI_Line4					/* �ж���· */
#define KEY0_EXTI_TRIGGER			 			EXTI_Trigger_Falling		/* �жϳ�����ʽ */
#endif

//KEY1
#if KEY1_EXTI_FUNCTION_SUPPORT
#define KEY1_EXTI_GPIO_PORT    					GPIOE			            /* GPIO�˿� */
#define KEY1_EXTI_GPIO_CLK 	    				RCC_APB2Periph_GPIOE		/* GPIO�˿�ʱ�� */
#define KEY1_EXTI_GPIO_PIN		  				GPIO_Pin_3			        /* ����KEY0�ܽŵ�GPIO */
#define KEY1_EXTI_GPIO_MODE						GPIO_Mode_IPU 				/* �������� */
#define KEY1_EXTI_IRQ  							EXTI3_IRQn					/* �ж�Դ */
#define KEY1_EXTI_IRQ_PREEMPTION_PRIORITY		2							/* ������ռ���ȼ� */
#define KEY1_EXTI_IRQ_SUB_PRIORITY				1 							/* ���������ȼ� */
#define KEY1_EXTI_LINE         					EXTI_Line3					/* �ж���· */
#define KEY1_EXTI_TRIGGER			 			EXTI_Trigger_Falling		/* �жϳ�����ʽ */
#endif

//KEY2
#if KEY2_EXTI_FUNCTION_SUPPORT
#define KEY2_EXTI_GPIO_PORT    	                GPIOE			            /* GPIO�˿� */
#define KEY2_EXTI_GPIO_CLK 	                    RCC_APB2Periph_GPIOE		/* GPIO�˿�ʱ�� */
#define KEY2_EXTI_GPIO_PIN		                GPIO_Pin_2			        /* ����KEY0�ܽŵ�GPIO */
#define KEY2_EXTI_GPIO_MODE						GPIO_Mode_IPU 				/* �������� */
#define KEY2_EXTI_IRQ  							EXTI2_IRQn					/* �ж�Դ */
#define KEY2_EXTI_IRQ_PREEMPTION_PRIORITY		2							/* ������ռ���ȼ� */
#define KEY2_EXTI_IRQ_SUB_PRIORITY				2 							/* ���������ȼ� */
#define KEY2_EXTI_LINE         					EXTI_Line2					/* �ж���· */
#define KEY2_EXTI_TRIGGER			 			EXTI_Trigger_Falling		/* �жϳ�����ʽ */
#endif
/******** ������ذ����ж� *********/

/* �������USART�ж� */
/** 
  * ���ں궨�壬��ͬ�Ĵ��ڹ��ص����ߺ�IO��һ������ֲʱ��Ҫ�޸��⼸����
	* 1-�޸�����ʱ�ӵĺ꣬uart1���ص�apb2���ߣ�����uart���ص�apb1����
	* 2-�޸�GPIO�ĺ�
  */
#if USART1_FUNCTION_SUPPORT
#define  DEBUG_USARTx                   USART1                      /* ����1-USART1 */
#define  DEBUG_USART_CLK                RCC_APB2Periph_USART1       /* usartʱ�� */
#define  DEBUG_USART_APBxClkCmd         RCC_APB2PeriphClockCmd
#define  DEBUG_USART_BAUDRATE           115200                      /* ���ò����� */
// USART GPIO ���ź궨��
#define  DEBUG_USART_GPIO_CLK           (RCC_APB2Periph_GPIOA)      /* GPIO�˿�ʱ�� */
#define  DEBUG_USART_GPIO_APBxClkCmd    RCC_APB2PeriphClockCmd
    
#define  DEBUG_USART_TX_GPIO_PORT       GPIOA                       /* ���͹ܽ�GPIO�˿� */
#define  DEBUG_USART_TX_GPIO_PIN        GPIO_Pin_9                  /* ���͹ܽŵ�GPIO */
#define  DEBUG_USART_RX_GPIO_PORT       GPIOA                       /* ���չܽ�GPIO�˿� */
#define  DEBUG_USART_RX_GPIO_PIN        GPIO_Pin_10                 /* ���չܽŵ�GPIO */

#define  DEBUG_USART_IRQ                USART1_IRQn                 /* �ж�Դ */
#define  DEBUG_USART_IRQHandler         USART1_IRQHandler           /* �жϺ��� */
#endif
/* �������USART�ж� */

/* ������ض�ʱ��*/
#if TIME1_FUNCTION_SUPPORT

#endif

#if TIME2_FUNCTION_SUPPORT

#endif

#if TIME3_FUNCTION_SUPPORT

#endif

#if TIME4_FUNCTION_SUPPORT

#endif

#if TIME5_FUNCTION_SUPPORT/************ͨ�ö�ʱ��TIM�������壬ֻ��TIM2��3��4��5************/
// ��ʹ�ò�ͬ�Ķ�ʱ����ʱ�򣬶�Ӧ��GPIO�ǲ�һ���ģ����Ҫע��
// ��������Ĭ��ʹ��TIM5
#define            TIME5_GENERAL_TIM                   TIM5
#define            TIME5_GENERAL_TIM_CLK               RCC_APB1Periph_TIM5
#define            TIME5_GENERAL_TIM_PERIOD            0XFFFF
#define            TIME5_GENERAL_TIM_PSC              (72-1)

// TIM ���벶��ͨ��GPIO��غ궨��
#define            TIME5_GENERAL_TIM_CH1_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            TIME5_GENERAL_TIM_CH1_PORT          GPIOA
#define            TIME5_GENERAL_TIM_CH1_PIN           GPIO_Pin_0
#define            TIME5_GENERAL_TIM_CHANNEL_x         TIM_Channel_1

// �ж���غ궨��
#define            TIME5_GENERAL_TIM_IT_CCx            TIM_IT_CC1
#define            TIME5_GENERAL_TIM_IRQ               TIM5_IRQn
#define            TIME5_GENERAL_TIM_INT_FUN           TIM5_IRQHandler

// ��������ʼ����
#define            GENERAL_TIM_STRAT_ICPolarity                TIM_ICPolarity_Rising
// �����Ľ�������
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
/* ������ض�ʱ��*/

#endif /* __USER_PROJECT_CONFIG_H */
