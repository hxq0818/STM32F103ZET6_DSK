/**
  ******************************************************************************
  * @file    bsp_exti.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   I/O线中断应用bsp
  ******************************************************************************
  * @attention
  *
  * 实验平台:野火 F103-霸道 STM32 开发板 
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */
  
#include "bsp_exti.h"
#include "bsp_key.h"
#include "bsp_beep.h"
#include "bsp_led.h"

#include "log.h"
 /**
  * @brief  配置 IO为EXTI中断口，并设置中断优先级
  * @param  无
  * @retval 无
  */
void EXTI_Key_Config(void)
{
	DEBUG_LOG(HXQ_DEBUG_MODULE_KEY_LVL,"%s %d\r\n",__func__,__LINE__);
	GPIO_InitTypeDef GPIO_InitStructure; //定义结构体变量	
	NVIC_InitTypeDef NVIC_InitStructure;
	EXTI_InitTypeDef  EXTI_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOE,ENABLE);	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);

#if KEY_UP_EXTI_FUNCTION_SUPPORT
	GPIO_InitStructure.GPIO_Pin=KEY_UP_EXTI_GPIO_PIN;	   			/* 连接KEY_UP管脚的GPIO */
	GPIO_InitStructure.GPIO_Mode=KEY_UP_EXTI_GPIO_MODE;				/* 下拉输入 */
	GPIO_Init(KEY_UP_EXTI_GPIO_PORT,&GPIO_InitStructure);		  /* 初始化GPIO */
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource0);/* 选择EXTI的信号源 */
	
		//EXTI0 NVIC 配置
	NVIC_InitStructure.NVIC_IRQChannel = KEY_UP_EXTI_IRQ;/* 配置中断源 */
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=KEY_UP_EXTI_IRQ_PREEMPTION_PRIORITY;//抢占优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =KEY_UP_EXTI_IRQ_SUB_PRIORITY;		//子优先级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	//根据指定的参数初始化VIC寄存器	
	
	EXTI_InitStructure.EXTI_Line=KEY_UP_EXTI_LINE;						/* 中断线路 */
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;					/* 中断模式 */
	EXTI_InitStructure.EXTI_Trigger=KEY_UP_EXTI_TRIGGER;			/* 中断出发方式 */
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;
	EXTI_Init(&EXTI_InitStructure);
#endif

#if KEY0_EXTI_FUNCTION_SUPPORT
	GPIO_InitStructure.GPIO_Pin=KEY0_EXTI_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode=KEY0_EXTI_GPIO_MODE;	//上拉输入
	GPIO_Init(KEY0_EXTI_GPIO_PORT,&GPIO_InitStructure);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource4);//选择GPIO管脚用作外部中断线路

		//EXTI4 NVIC 配置
	NVIC_InitStructure.NVIC_IRQChannel = KEY0_EXTI_IRQ;//EXTI4中断通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=KEY0_EXTI_IRQ_PREEMPTION_PRIORITY;//抢占优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =KEY0_EXTI_IRQ_SUB_PRIORITY;		//子优先级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	//根据指定的参数初始化VIC寄存器
	
	EXTI_InitStructure.EXTI_Line=KEY0_EXTI_LINE; 
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger=KEY0_EXTI_TRIGGER;
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;
	EXTI_Init(&EXTI_InitStructure);
#endif

#if KEY1_EXTI_FUNCTION_SUPPORT
	GPIO_InitStructure.GPIO_Pin=KEY1_EXTI_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode=KEY1_EXTI_GPIO_MODE;	//上拉输入
	GPIO_Init(KEY1_EXTI_GPIO_PORT,&GPIO_InitStructure);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource3);//选择GPIO管脚用作外部中断线路

	//EXTI3 NVIC 配置
	NVIC_InitStructure.NVIC_IRQChannel = KEY1_EXTI_IRQ;//EXTI3中断通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=KEY1_EXTI_IRQ_PREEMPTION_PRIORITY;//抢占优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =KEY1_EXTI_IRQ_SUB_PRIORITY;		//子优先级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	//根据指定的参数初始化VIC寄存器
	
	EXTI_InitStructure.EXTI_Line=KEY1_EXTI_LINE; 
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger=KEY1_EXTI_TRIGGER;
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;
	EXTI_Init(&EXTI_InitStructure);
#endif
#if KEY2_EXTI_FUNCTION_SUPPORT
	GPIO_InitStructure.GPIO_Pin=KEY2_EXTI_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode=KEY2_EXTI_GPIO_MODE;	//上拉输入
	GPIO_Init(KEY2_EXTI_GPIO_PORT,&GPIO_InitStructure);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource2);//选择GPIO管脚用作外部中断线路
	
	//EXTI2 NVIC 配置
	NVIC_InitStructure.NVIC_IRQChannel = KEY2_EXTI_IRQ;//EXTI2中断通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=KEY2_EXTI_IRQ_PREEMPTION_PRIORITY;//抢占优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =KEY2_EXTI_IRQ_SUB_PRIORITY;		//子优先级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	//根据指定的参数初始化VIC寄存器
	
	EXTI_InitStructure.EXTI_Line=KEY2_EXTI_LINE; 
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger=KEY2_EXTI_TRIGGER;
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;
	EXTI_Init(&EXTI_InitStructure);
#endif
}

/*******************************************************************************
* 函 数 名         : EXTI0_IRQHandler
* 函数功能		   : 外部中断0函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void EXTI0_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line0)==1)
	{
		//delay_ms(10);
		if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0) == 1)
		{
			BEEP(0);
		}	
	}
	EXTI_ClearITPendingBit(EXTI_Line0);
}

/*******************************************************************************
* 函 数 名         : EXTI2_IRQHandler
* 函数功能		   : 外部中断2函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void EXTI2_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line2)==1)
	{
		//delay_ms(10);
		if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_2) == 0)
		{	
			LED1(1);
		}
		
	}
	EXTI_ClearITPendingBit(EXTI_Line2);
}

/*******************************************************************************
* 函 数 名         : EXTI3_IRQHandler
* 函数功能		   : 外部中断3函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void EXTI3_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line3)==1)
	{
		//delay_ms(10);
		if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3) == 0)
		{	
			BEEP(1);
		}
		
	}
	EXTI_ClearITPendingBit(EXTI_Line3);
}

/*******************************************************************************
* 函 数 名         : EXTI4_IRQHandler
* 函数功能		   : 外部中断4函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void EXTI4_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line4)==1)
	{
		//delay_ms(10);
		if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4) == 0)
		{
			LED1(0);
		}
		
	}
	EXTI_ClearITPendingBit(EXTI_Line4);
}



/*********************************************END OF FILE**********************/
