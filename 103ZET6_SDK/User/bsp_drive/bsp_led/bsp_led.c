/*
 * @brief: led应用函数接口
 * @version: V1.0
 * @Author: xiaoqing.huang
 * @Date: 2023-04-04 21:42:21
 * @LastEditors: LAPTOP-4DIHEQ1Q
 * @LastEditTime: 2023-04-19 19:59:18
 */
  
#include "bsp_led.h"   
#include "log.h"
 /**
  * @brief  初始化控制LED的IO
  * @param  无
  * @retval 无
  */
 
void LED_GPIO_Config(void)
{		
		DEBUG_LOG(HXQ_DEBUG_MODULE_LED_LVL,"%s %d\r\n",__func__,__LINE__);
		/*定义一个GPIO_InitTypeDef类型的结构体*/
		GPIO_InitTypeDef GPIO_InitStructure;

		/*开启LED相关的GPIO外设时钟*/
		RCC_APB2PeriphClockCmd( LED1_GPIO_CLK | LED0_GPIO_CLK , ENABLE);
		/*选择要控制的GPIO引脚*/
		GPIO_InitStructure.GPIO_Pin = LED1_GPIO_PIN;	

		/*设置引脚模式为通用推挽输出*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

		/*设置引脚速率为50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

		/*调用库函数，初始化GPIO*/
		GPIO_Init(LED1_GPIO_PORT, &GPIO_InitStructure);	
		
		/*选择要控制的GPIO引脚*/
		GPIO_InitStructure.GPIO_Pin = LED0_GPIO_PIN;

		/*调用库函数，初始化GPIO*/
		GPIO_Init(LED0_GPIO_PORT, &GPIO_InitStructure);

		/* 关闭所有led灯	*/
		GPIO_SetBits(LED1_GPIO_PORT, LED1_GPIO_PIN);
		
		/* 关闭所有led灯	*/
		GPIO_SetBits(LED0_GPIO_PORT, LED0_GPIO_PIN);	 
    
}

/*********************************************END OF FILE**********************/
