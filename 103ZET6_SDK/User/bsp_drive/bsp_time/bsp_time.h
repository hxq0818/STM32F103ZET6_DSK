/*
 * @brief: 
 * @Author: xiaoqing.huang
 * @version: V1.0
 * @Date: 2023-04-19 20:54:40
 * @LastEditors: LAPTOP-4DIHEQ1Q
 * @LastEditTime: 2023-04-25 19:48:30
 */
#ifndef __BSP_TIME_H
#define __BSP_TIME_H


#include "stm32f10x.h"

#include "user_project_config.h"





// 定时器输入捕获用户自定义变量结构体声明
typedef struct
{   
	uint8_t   Capture_FinishFlag;   // 捕获结束标志位
	uint8_t   Capture_StartFlag;    // 捕获开始标志位
	uint16_t  Capture_CcrValue;     // 捕获寄存器的值
	uint16_t  Capture_Period;       // 自动重装载寄存器更新标志 
}TIM_ICUserValueTypeDef;

extern TIM_ICUserValueTypeDef TIM_ICUserValueStructure;




/**************************函数声明********************************/
extern volatile uint32_t time6; // ms 计时变量 
extern volatile uint32_t time7; // ms 计时变量 
void BASIC_TIM_Init(void);
void TIM6_Init(void);
void TIM7_Init(void);
void TIM5_Input_Capture(void);
void Enter_Standby_Mode(void);


#endif	/* __BSP_TIME_H */


