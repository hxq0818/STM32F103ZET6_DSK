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

/* ������������ӵ�GPIO�˿�, �û�ֻ��Ҫ�޸�����Ĵ��뼴�ɸı���Ƶķ��������� */
#ifndef BEEP_FUNCTION_SUPPORT
#define BEEP_FUNCTION_SUPPORT 1
#define BEEP_GPIO_PORT    	GPIOB			              /* GPIO�˿� */
#define BEEP_GPIO_CLK 	    RCC_APB2Periph_GPIOB		/* GPIO�˿�ʱ�� */
#define BEEP_GPIO_PIN		  GPIO_Pin_8			        /* ���ӵ���������GPIO */
#endif

///* �ߵ�ƽʱ���������� */
//#define ON  1
//#define OFF 0

/* ���κ꣬��������������һ��ʹ�� */
#define BEEP(a)	if (a)	\
					GPIO_SetBits(BEEP_GPIO_PORT,BEEP_GPIO_PIN);\
					else		\
					GPIO_ResetBits(BEEP_GPIO_PORT,BEEP_GPIO_PIN)

void BEEP_GPIO_Config(void);
					
#endif /* __BEEP_H */
