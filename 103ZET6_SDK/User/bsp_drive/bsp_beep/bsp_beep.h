/*
 * @brief: ������Ӧ�ú����ӿ�
 * @version: V1.0
 * @Author: xiaoqing.huang
 * @Date: 2023-04-05 20:52:52
 * @LastEditors: LAPTOP-4DIHEQ1Q
 * @LastEditTime: 2023-04-19 20:10:00
 */
  
#ifndef __BEEP_H
#define	__BEEP_H


#include "stm32f10x.h"

#include "user_project_config.h"


/* ���κ꣬��������������һ��ʹ�� */
#define BEEP(a)	if (a)	\
					GPIO_SetBits(BEEP_GPIO_PORT,BEEP_GPIO_PIN);\
					else		\
					GPIO_ResetBits(BEEP_GPIO_PORT,BEEP_GPIO_PIN)

void BEEP_GPIO_Config(void);
					
#endif /* __BEEP_H */
