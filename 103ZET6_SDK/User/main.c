/*
 * @Descripttion: 
 * @version: 
 * @Author: xiaoqing.huang
 * @Date: 2023-04-04 21:42:21
 * @LastEditors: LAPTOP-4DIHEQ1Q
 * @LastEditTime: 2023-04-18 21:05:27
 */
/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   ����led
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:Ұ�� F103-ָ���� STM32 ������ 
  * ��̳    :http://www.firebbs.cn
  * �Ա�    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
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
#include "log.h"



/**
  * @brief  ������
  * @param  ��  
  * @retval ��
  */
int main(void)
{	
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
	WWDG_Init();
	DEBUG_LOG(HXQ_DEBUG_MODULE_SYSTEM_LVL,"START!!!\r\n");
	while(1)
	{

		LED0( 1 ); 
	    Delay_us(100000);    	// 100000 * 10us = 1000ms
		LED0( 0 );
	    Delay_us(100000);		// 100000 * 10us = 1000ms
	
	}  

}

/*********************************************END OF FILE**********************/
