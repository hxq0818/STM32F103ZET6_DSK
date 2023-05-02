/*
 * @brief: 按键应用bsp（扫描模式）(未使用)
 * @version: V1.0
 * @Author: xiaoqing.huang
 * @Date: 2023-04-06 19:46:17
 * @LastEditors: LAPTOP-4DIHEQ1Q
 * @LastEditTime: 2023-04-19 20:09:52
 */

#ifndef __KEY_H
#define	__KEY_H


#include "stm32f10x.h"

#include "user_project_config.h"

//  引脚定义
#ifndef KEY_UP_FUNCTION_SUPPORT
#define KEY_UP_FUNCTION_SUPPORT 1

#endif


void Key_GPIO_Config(void);
uint8_t Key_Scan(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin);


#endif /* __KEY_H */

