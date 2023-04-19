/*
 * @brief: ledӦ�ú����ӿ�
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

/* ����LED���ӵ�GPIO�˿�, �û�ֻ��Ҫ�޸�����Ĵ��뼴�ɸı���Ƶķ��������� */
// LED1
#ifndef LED1_FUNCTION_SUPPROT
#define LED1_FUNCTION_SUPPORT 1
#define LED1_GPIO_PORT    	GPIOE			              /* GPIO�˿� */
#define LED1_GPIO_CLK 	    RCC_APB2Periph_GPIOE		/* GPIO�˿�ʱ�� */
#define LED1_GPIO_PIN				GPIO_Pin_5			        /* ���ӵ�SCLʱ���ߵ�GPIO */
#endif


// LED0
#ifndef LED0_FUNCTION_SUPPORT
#define LED0_FUNCTION_SUPPROT 1
#define LED0_GPIO_PORT    	GPIOB			             /* GPIO�˿� */
#define LED0_GPIO_CLK 	    RCC_APB2Periph_GPIOB		/* GPIO�˿�ʱ�� */
#define LED0_GPIO_PIN				GPIO_Pin_5			        /* ���ӵ�SCLʱ���ߵ�GPIO */
#endif




/* ���κ꣬��������������һ��ʹ�� */
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
