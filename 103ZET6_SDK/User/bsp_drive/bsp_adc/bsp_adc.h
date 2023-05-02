#ifndef _adc_H
#define _adc_H

#include "stm32f10x.h"

#include "user_project_config.h"

void ADC2_Init(void);
u16 Get_ADC_Value(u8 ch,u8 times);


void ADC_Temp_Init(void);
u16 Get_ADC_Temp_Value(u8 ch,u8 times);
int Get_Temperture(void);



void Lsens_Init(void); 				//��ʼ������������
u8 Lsens_Get_Val(void);				//��ȡ������������ֵ


#endif
