/*
 * @Descripttion: 
 * @version: 
 * @Author: xiaoqing.huang
 * @Date: 2023-04-07 11:50:52
 * @LastEditors: 
 * @LastEditTime: 2023-04-18 21:03:27
 */
#ifndef __EXTI_H
#define	__EXTI_H


#include "stm32f10x.h"


//Òý½Å¶¨Òå
//#define KEY_UP_INT_GPIO_PORT         GPIOA
#define KEY_UP_INT_GPIO_CLK          (RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO)
//#define KEY_UP_INT_GPIO_PIN          GPIO_Pin_0
#define KEY_UP_INT_EXTI_PORTSOURCE   GPIO_PortSourceGPIOA
#define KEY_UP_INT_EXTI_PINSOURCE    GPIO_PinSource0
#define KEY_UP_INT_EXTI_LINE         EXTI_Line0
#define KEY_UP_INT_EXTI_IRQ          EXTI0_IRQn

//#define KEY_UP_IRQHandler            EXTI0_IRQHandler


#define KEY1_INT_GPIO_CLK          (RCC_APB2Periph_GPIOE|RCC_APB2Periph_AFIO)
#define KEY1_INT_EXTI_PORTSOURCE   GPIO_PortSourceGPIOE
#define KEY1_INT_EXTI_PINSOURCE    GPIO_PinSource3
#define KEY1_INT_EXTI_LINE         EXTI_Line3
#define KEY1_INT_EXTI_IRQ          EXTI3_IRQn

//#define KEY1_IRQHandler            EXTI15_10_IRQHandler

#define KEY2_INT_GPIO_CLK          (RCC_APB2Periph_GPIOE|RCC_APB2Periph_AFIO)
#define KEY2_INT_EXTI_PORTSOURCE   GPIO_PortSourceGPIOE
#define KEY2_INT_EXTI_PINSOURCE    GPIO_PinSource2
#define KEY2_INT_EXTI_LINE         EXTI_Line2
#define KEY2_INT_EXTI_IRQ          EXTI2_IRQn

//#define KEY2_IRQHandler            EXTI15_10_IRQHandler


#define KEY0_INT_GPIO_CLK          (RCC_APB2Periph_GPIOE|RCC_APB2Periph_AFIO)
#define KEY0_INT_EXTI_PORTSOURCE   GPIO_PortSourceGPIOE
#define KEY0_INT_EXTI_PINSOURCE    GPIO_PinSource4
#define KEY0_INT_EXTI_LINE         EXTI_Line4
#define KEY0_INT_EXTI_IRQ          EXTI4_IRQn
					 
//#define KEY0_IRQHandler            EXTI15_10_IRQHandler


void EXTI_Key_Config(void);


#endif /* __EXTI_H */
