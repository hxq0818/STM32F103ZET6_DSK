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

// 局部变量，用于保存转换计算后的电压值 	 
float ADC_ConvertedValueLocal;  
/**
  * @brief  主函数
  * @param  无  
  * @retval 无
  */
int main(void)
{	

	
	
	
	// // TIM 计数器的驱动时钟
	// uint32_t TIM_PscCLK = 72000000 / (TIME5_GENERAL_TIM_PSC+1);

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
//	WWDG_Init();
	BASIC_TIM_Init();	
	/* 定时器初始化 */
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
		DEBUG_LOG(HXQ_DEBUG_MODULE_TEP_LVL,"DS18B20检测失败，请插好!\r\n");
		Delay_ms(500);
	}
	DEBUG_LOG(HXQ_DEBUG_MODULE_TEP_LVL,"DS18B20检测成功!\r\n");
	
	while (1)
	{

	}
}

/*********************************************END OF FILE**********************/
