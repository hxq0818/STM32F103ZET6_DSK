/*
 * @brief: 蜂鸣器应用函数接口
 * @version: V1.0
 * @Author: xiaoqing.huang
 * @Date: 2023-04-05 20:52:52
 * @LastEditors: LAPTOP-4DIHEQ1Q
 * @LastEditTime: 2023-04-19 19:59:43
 */
  
#include "bsp_beep.h"   

#include "log.h"
 /**
  * @brief  初始化控制蜂鸣器的IO
  * @param  无
  * @retval 无
  */
void BEEP_GPIO_Config(void)
{		
		DEBUG_LOG(HXQ_DEBUG_MODULE_BEEP_LVL,"%s %d\r\n",__func__,__LINE__);
		/*定义一个GPIO_InitTypeDef类型的结构体*/
		GPIO_InitTypeDef GPIO_InitStructure;

		/*开启控制蜂鸣器的GPIO的端口时钟*/
		RCC_APB2PeriphClockCmd( BEEP_GPIO_CLK, ENABLE); 

		/*选择要控制蜂鸣器的GPIO*/															   
		GPIO_InitStructure.GPIO_Pin = BEEP_GPIO_PIN;	

		/*设置GPIO模式为通用推挽输出*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

		/*设置GPIO速率为50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

		/*调用库函数，初始化控制蜂鸣器的GPIO*/
		GPIO_Init(BEEP_GPIO_PORT, &GPIO_InitStructure);			 
    
    /* 关闭蜂鸣器*/
		GPIO_ResetBits(BEEP_GPIO_PORT, BEEP_GPIO_PIN);	 
}
/*********************************************END OF FILE**********************/
