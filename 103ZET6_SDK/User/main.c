/*
 * @brief: 
 * @version: V1.0
 * @Author: xiaoqing.huang
 * @Date: 2023-04-04 21:42:21
 * @LastEditors: LAPTOP-4DIHEQ1Q
 * @LastEditTime: 2023-04-25 19:44:56
 */

#include "stm32f10x.h"
#include "user_project_config.h"

#include "bsp_SysTick.h"
#include "bsp_led.h"
#include "bsp_beep.h"
#include "bsp_key.h"
#include "bsp_exti.h"
#include "bsp_usart.h"
#include "bsp_wwdg.h"
#include "bsp_time.h"
#include "bsp_adc.h"
#include "bsp_rtc.h"
#include "bsp_ds18b20.h"

#include "log.h"

extern __IO uint16_t ADC_ConvertedValue;

// �ֲ����������ڱ���ת�������ĵ�ѹֵ 	 
float ADC_ConvertedValueLocal;  
/**
  * @brief  ������
  * @param  ��  
  * @retval ��
  */
int main(void)
{	

	
	
	
	// // TIM ������������ʱ��
	// uint32_t TIM_PscCLK = 72000000 / (TIME5_GENERAL_TIM_PSC+1);

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	/* ����USART1 */
	USART_Config();
	/* ����LED0 LED1 */
	LED_GPIO_Config();
	/* ����BEEP */
	BEEP_GPIO_Config();
	/* ����KEY_UP KEY0 KEY1 KEY2 �ж� */
	EXTI_Key_Config();
	/* ����SysTick Ϊ10us�ж�һ�� */
	SysTick_Init();	
//		/* ����һ���ַ��� */
//	Usart_SendString( DEBUG_USARTx,"����һ�������жϽ��ջ���ʵ��\n");
//	printf("��ӭʹ��Ұ��STM32������\n\n\n\n");
//	WWDG_Init();
	BASIC_TIM_Init();	
	/* ��ʱ����ʼ�� */
	// GENERAL_TIM_Init();
	TIM5_Input_Capture();
	DEBUG_LOG(HXQ_DEBUG_MODULE_SYSTEM_LVL,"START!!!\r\n");
	
	ADC2_Init();
	ADC_Temp_Init();
	Lsens_Init();
	
	RTC_Init();
	
	RTC_Alarm_Set(2020,7,23,15,5,0);
	
	while(DS18B20_Init())
	{
		DEBUG_LOG(HXQ_DEBUG_MODULE_TEP_LVL,"DS18B20���ʧ�ܣ�����!\r\n");
		Delay_ms(500);
	}
	DEBUG_LOG(HXQ_DEBUG_MODULE_TEP_LVL,"DS18B20���ɹ�!\r\n");
	
	while (1)
	{

	}
}

/*********************************************END OF FILE**********************/
