/*
 * @brief: 系统嘀嗒计时器功能
 * @version: V1.0
 * @Author: xiaoqing.huang
 * @Date: 2023-04-06 20:43:22
 * @LastEditors: LAPTOP-4DIHEQ1Q
 * @LastEditTime: 2023-04-19 20:09:44
 */

#ifndef __SYSTICK_H
#define __SYSTICK_H

#include "stm32f10x.h"

void SysTick_Init(void);
void Delay_us(__IO u32 nTime);
#define Delay_ms(x) Delay_us(1000*x)	 //单位ms

void SysTick_Delay_Us( __IO uint32_t us);
void SysTick_Delay_Ms( __IO uint32_t ms);


#endif /* __SYSTICK_H */
