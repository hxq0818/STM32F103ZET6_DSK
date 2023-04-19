/*
 * @brief: ����Ӧ��bsp��ɨ��ģʽ��(δʹ��)
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

//  ���Ŷ���
#ifndef KEY_UP_FUNCTION_SUPPORT
#define KEY_UP_FUNCTION_SUPPORT 1

#endif


 /** �������±��ú�
	*  ��������Ϊ�ߵ�ƽ������ KEY_ON=1�� KEY_OFF=0
	*  ����������Ϊ�͵�ƽ���Ѻ����ó�KEY_ON=0 ��KEY_OFF=1 ����
	*/
#define KEY_ON	0
#define KEY_OFF	1

void Key_GPIO_Config(void);
uint8_t Key_Scan(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin);


#endif /* __KEY_H */

