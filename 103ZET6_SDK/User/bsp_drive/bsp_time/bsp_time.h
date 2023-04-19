/*
 * @brief: 
 * @Author: xiaoqing.huang
 * @version: V1.0
 * @Date: 2023-04-19 20:54:40
 * @LastEditors: LAPTOP-4DIHEQ1Q
 * @LastEditTime: 2023-04-19 21:23:13
 */
#ifndef __BSP_TIME_H
#define __BSP_TIME_H


#include "stm32f10x.h"

#include "user_project_config.h"

/********************基本定时器TIM参数定义，只限TIM6、7************/
// //#define BASIC_TIM6 // 如果使用TIM7，注释掉这个宏即可

// #ifdef  BASIC_TIM6 // 使用基本定时器TIM6
// #define            BASIC_TIM                   TIM6
// #define            BASIC_TIM_APBxClock_FUN     RCC_APB1PeriphClockCmd
// #define            BASIC_TIM_CLK               RCC_APB1Periph_TIM6
// #define            BASIC_TIM_Period            (1000-1)
// #define            BASIC_TIM_Prescaler         71
// #define            BASIC_TIM_IRQ               TIM6_IRQn
// #define            BASIC_TIM_IRQHandler        TIM6_IRQHandler

// #else  // 使用基本定时器TIM7
// #define            BASIC_TIM                   TIM7
// #define            BASIC_TIM_APBxClock_FUN     RCC_APB1PeriphClockCmd
// #define            BASIC_TIM_CLK               RCC_APB1Periph_TIM7
// #define            BASIC_TIM_Period            1000-1
// #define            BASIC_TIM_Prescaler         71
// #define            BASIC_TIM_IRQ               TIM7_IRQn
// #define            BASIC_TIM_IRQHandler        TIM7_IRQHandler

// #endif
/**************************函数声明********************************/
extern volatile uint32_t time; // ms 计时变量 
extern volatile uint32_t time7; // ms 计时变量 
void BASIC_TIM_Init(void);


#endif	/* __BSP_TIME_H */


