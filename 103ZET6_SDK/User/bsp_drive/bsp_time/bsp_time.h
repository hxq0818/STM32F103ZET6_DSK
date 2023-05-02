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





// ��ʱ�����벶���û��Զ�������ṹ������
typedef struct
{   
	uint8_t   Capture_FinishFlag;   // ���������־λ
	uint8_t   Capture_StartFlag;    // ����ʼ��־λ
	uint16_t  Capture_CcrValue;     // ����Ĵ�����ֵ
	uint16_t  Capture_Period;       // �Զ���װ�ؼĴ������±�־ 
}TIM_ICUserValueTypeDef;

extern TIM_ICUserValueTypeDef TIM_ICUserValueStructure;




/**************************��������********************************/
extern volatile uint32_t time6; // ms ��ʱ���� 
extern volatile uint32_t time7; // ms ��ʱ���� 
void BASIC_TIM_Init(void);
void TIM6_Init(void);
void TIM7_Init(void);
void TIM5_Input_Capture(void);
void Enter_Standby_Mode(void);


#endif	/* __BSP_TIME_H */


