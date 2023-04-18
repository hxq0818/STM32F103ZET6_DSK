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
  * @brief   测试led
  ******************************************************************************
  * @attention
  *
  * 实验平台:野火 F103-指南者 STM32 开发板 
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :https://fire-stm32.taobao.com
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
  * @brief  主函数
  * @param  无  
  * @retval 无
  */
int main(void)
{	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	/* 配置USART1 */
	USART_Config();
	/* 配置LED0 LED1 */
	LED_GPIO_Config();
	/* 配置BEEP */
	BEEP_GPIO_Config();
	/* 配置KEY_UP KEY0 KEY1 KEY2 中断 */
	EXTI_Key_Config();
	/* 配置SysTick 为10us中断一次 */
	SysTick_Init();	
//		/* 发送一个字符串 */
//	Usart_SendString( DEBUG_USARTx,"这是一个串口中断接收回显实验\n");
//	printf("欢迎使用野火STM32开发板\n\n\n\n");
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
