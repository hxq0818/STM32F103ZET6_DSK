/*
 * @Descripttion: 
 * @version: 
 * @Author: xiaoqing.huang
 * @Date: 2023-04-06 20:43:29
 * @LastEditors: 
 * @LastEditTime: 2023-04-18 21:03:06
 */
#ifndef __SYSTICK_H
#define __SYSTICK_H

#include "stm32f10x.h"

void SysTick_Init(void);
void Delay_us(__IO u32 nTime);
#define Delay_ms(x) Delay_us(100*x)	 //µ¥Î»ms

void SysTick_Delay_Us( __IO uint32_t us);
void SysTick_Delay_Ms( __IO uint32_t ms);


#endif /* __SYSTICK_H */
