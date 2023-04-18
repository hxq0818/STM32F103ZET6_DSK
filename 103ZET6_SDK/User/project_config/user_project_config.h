#ifndef __USER_PROJECT_CONFIG_H
#define	__USER_PROJECT_CONFIG_H


#include "stm32f10x.h"

/* ʹ��log��ӡ */
#define DEBUG_SUPPORT 1


/* �ߵ͵�ƽ */
#define HIGH_LEVEL  	1			/* �ߵ�ƽ*/
#define HOW_LEVEL 		0			/* �ֵ�ƽ*/

/******** �������LED *********/
//LED0
#ifndef LED0_FUNCTION_SUPPORT
#define LED0_FUNCTION_SUPPORT 1
#define LED0_GPIO_PORT    	GPIOB			              /* GPIO�˿� */
#define LED0_GPIO_CLK 	    RCC_APB2Periph_GPIOE		/* GPIO�˿�ʱ�� */
#define LED0_GPIO_PIN				GPIO_Pin_5			        /* ���ӵ�SCLʱ���ߵ�GPIO */
#else
#define LED0_FUNCTION_SUPPORT 0
#endif

//LED1
#ifndef LED1_FUNCTION_SUPPROT
#define LED1_FUNCTION_SUPPROT 1
#define LED1_GPIO_PORT    	GPIOE			              /* GPIO�˿� */
#define LED1_GPIO_CLK 	    RCC_APB2Periph_GPIOB		/* GPIO�˿�ʱ�� */
#define LED1_GPIO_PIN				GPIO_Pin_5			        /* ���ӵ�SCLʱ���ߵ�GPIO */
#else
#define LED1_FUNCTION_SUPPROT 0
#endif
/******** �������LED *********/

/******** ���������Դ������ *********/
//BEEP
#ifndef BEEP_FUNCTION_SUPPORT
#define BEEP_FUNCTION_SUPPORT 1
#define BEEP_GPIO_PORT    	GPIOB			              /* GPIO�˿� */
#define BEEP_GPIO_CLK 	    RCC_APB2Periph_GPIOB		/* GPIO�˿�ʱ�� */
#define BEEP_GPIO_PIN		  	GPIO_Pin_8			        /* ���ӵ���������GPIO */
#else
#define BEEP_FUNCTION_SUPPORT 0
#endif


/******** ���������Դ������ *********/

/******** ������ذ����ж� *********/
//KEY_UP
#ifndef KEY_UP_EXTI_FUNCTION_SUPPORT
#define KEY_UP_EXTI_FUNCTION_SUPPORT 1
#define KEY_UP_EXTI_GPIO_PORT    							GPIOA			              /* GPIO�˿� */
#define KEY_UP_EXTI_GPIO_CLK 	    						RCC_APB2Periph_GPIOA		/* GPIO�˿�ʱ�� */
#define KEY_UP_EXTI_GPIO_PIN		  						GPIO_Pin_0			        /* ����KEY_UP�ܽŵ�GPIO */
#define KEY_UP_EXTI_GPIO_MODE									GPIO_Mode_IPD    				/* �������� */
#define KEY_UP_EXTI_IRQ  											EXTI0_IRQn							/* �ж�Դ EXTI0_IRQn*/
#define KEY_UP_EXTI_IRQ_PREEMPTION_PRIORITY		2												/* ������ռ���ȼ� */
#define KEY_UP_EXTI_IRQ_SUB_PRIORITY					3												/* ���������ȼ� */
#define KEY_UP_EXTI_LINE         							EXTI_Line0							/* �ж���· */
#define KEY_UP_EXTI_TRIGGER			 							EXTI_Trigger_Rising			/* �жϳ�����ʽ */
#else
#define KEY_UP_EXTI_FUNCTION_SUPPORT 0
#endif

//KEY0
#ifndef KEY0_EXTI_FUNCTION_SUPPORT
#define KEY0_EXTI_FUNCTION_SUPPORT 1
#define KEY0_EXTI_GPIO_PORT    							GPIOE			              /* GPIO�˿� */
#define KEY0_EXTI_GPIO_CLK 	    						RCC_APB2Periph_GPIOE		/* GPIO�˿�ʱ�� */
#define KEY0_EXTI_GPIO_PIN		  						GPIO_Pin_4			        /* ����KEY0�ܽŵ�GPIO */
#define KEY0_EXTI_GPIO_MODE									GPIO_Mode_IPU 					/* �������� */
#define KEY0_EXTI_IRQ  											EXTI4_IRQn							/* �ж�Դ */
#define KEY0_EXTI_IRQ_PREEMPTION_PRIORITY		2												/* ������ռ���ȼ� */
#define KEY0_EXTI_IRQ_SUB_PRIORITY					0												/* ���������ȼ� */
#define KEY0_EXTI_LINE         							EXTI_Line4							/* �ж���· */
#define KEY0_EXTI_TRIGGER			 							EXTI_Trigger_Falling		/* �жϳ�����ʽ */
#else
#define KEY0_FUNCTION_SUPPORT 0
#endif

//KEY1
#ifndef KEY1_EXTI_FUNCTION_SUPPORT
#define KEY1_EXTI_FUNCTION_SUPPORT 1
#define KEY1_EXTI_GPIO_PORT    							GPIOE			              /* GPIO�˿� */
#define KEY1_EXTI_GPIO_CLK 	    						RCC_APB2Periph_GPIOE		/* GPIO�˿�ʱ�� */
#define KEY1_EXTI_GPIO_PIN		  						GPIO_Pin_3			        /* ����KEY0�ܽŵ�GPIO */
#define KEY1_EXTI_GPIO_MODE									GPIO_Mode_IPU 					/* �������� */
#define KEY1_EXTI_IRQ  											EXTI3_IRQn							/* �ж�Դ */
#define KEY1_EXTI_IRQ_PREEMPTION_PRIORITY		2												/* ������ռ���ȼ� */
#define KEY1_EXTI_IRQ_SUB_PRIORITY					1 											/* ���������ȼ� */
#define KEY1_EXTI_LINE         							EXTI_Line3							/* �ж���· */
#define KEY1_EXTI_TRIGGER			 							EXTI_Trigger_Falling		/* �жϳ�����ʽ */
#else
#define KEY1_FUNCTION_SUPPORT 0
#endif

//KEY2
#ifndef KEY2_EXTI_FUNCTION_SUPPORT
#define KEY2_EXTI_FUNCTION_SUPPORT 1
#define KEY2_EXTI_GPIO_PORT    	GPIOE			              /* GPIO�˿� */
#define KEY2_EXTI_GPIO_CLK 	    RCC_APB2Periph_GPIOE		/* GPIO�˿�ʱ�� */
#define KEY2_EXTI_GPIO_PIN		  GPIO_Pin_2			        /* ����KEY0�ܽŵ�GPIO */
#define KEY2_EXTI_GPIO_MODE									GPIO_Mode_IPU 					/* �������� */
#define KEY2_EXTI_IRQ  											EXTI2_IRQn							/* �ж�Դ */
#define KEY2_EXTI_IRQ_PREEMPTION_PRIORITY		2												/* ������ռ���ȼ� */
#define KEY2_EXTI_IRQ_SUB_PRIORITY					2 											/* ���������ȼ� */
#define KEY2_EXTI_LINE         							EXTI_Line2							/* �ж���· */
#define KEY2_EXTI_TRIGGER			 							EXTI_Trigger_Falling		/* �жϳ�����ʽ */
#else
#define KEY1_FUNCTION_SUPPORT 0
#endif
/******** ������ذ����ж� *********/


#endif /* __USER_PROJECT_CONFIG_H */
