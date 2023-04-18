/*
 * @Descripttion: 
 * @version: 
 * @Author: xiaoqing.huang
 * @Date: 2023-04-06 19:46:17
 * @LastEditors: 
 * @LastEditTime: 2023-04-18 21:05:47
 */
/**
  ******************************************************************************
  * @file    bsp_key.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   按键应用bsp（扫描模式）
  ******************************************************************************
  * @attention
  *
  * 实验平台:野火 F103-霸道 STM32 开发板 
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */ 
  
#include "bsp_key.h"  

#include "bsp_SysTick.h"
/**
  * @brief  配置按键用到的I/O口
  * @param  无
  * @retval 无
  */
void Key_GPIO_Config(void)
{
//	GPIO_InitTypeDef GPIO_InitStructure;
//	
//	/*开启按键端口的时钟*/
//	RCC_APB2PeriphClockCmd(KEY_UP_GPIO_CLK|KEY0_GPIO_CLK|KEY1_GPIO_CLK|KEY2_GPIO_CLK,ENABLE);
//	
//	//选择按键的引脚
//	GPIO_InitStructure.GPIO_Pin = KEY_UP_GPIO_PIN; 
//	// 设置按键的引脚为浮空输入//下拉输入 
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
//	//使用结构体初始化按键
//	GPIO_Init(KEY1_GPIO_PORT, &GPIO_InitStructure);
//	
//	//选择按键的引脚
//	GPIO_InitStructure.GPIO_Pin = KEY0_GPIO_PIN|KEY1_GPIO_PIN|KEY2_GPIO_PIN;
//	//设置按键的引脚为浮空输入//上拉输入
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 
//	//使用结构体初始化按键
//	GPIO_Init(KEY2_GPIO_PORT, &GPIO_InitStructure);	
}

 /*
 * 函数名：Key_Scan
 * 描述  ：检测是否有按键按下
 * 输入  ：GPIOx：x 可以是 A，B，C，D或者 E
 *		     GPIO_Pin：待读取的端口位 	
 * 输出  ：KEY_OFF(没按下按键)、KEY_ON（按下按键）
 */
uint8_t Key_Scan(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin)
{			
	/*检测是否有按键按下 */
	if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_ON )  
	{	 
		/*等待按键释放 */
		while(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_ON);   
		return 	KEY_ON;	 
	}
	else
		return KEY_OFF;
}

///*******************************************************************************
//* 函 数 名         : KEY_Scan
//* 函数功能		   : 按键扫描检测
//* 输    入         : mode=0:单次按下按键
//					 mode=1：连续按下按键
//* 输    出         : 0：未有按键按下
//					 KEY_UP_PRESS：KEY_UP键按下
//					 KEY0_PRESS：KEY0键按下
//					 KEY1_PRESS：KEY1键按下
//					 KEY2_PRESS：KEY2键按下
//*******************************************************************************/
//u8 KEY_Scan(u8 mode)
//{
//	static u8 key=1;
//	
//	if(mode==1) //连续按键按下
//		key=1;
//	if(key==1&&(KEY_UP==1||KEY0==0||KEY1==0||KEY2==0)) //任意一个按键按下
//	{
////		delay_ms(10);  //消抖
//		key=0;
//		if(KEY_UP==1)
//			return KEY_UP_PRESS; 
//		else if(KEY0==0)
//			return KEY0_PRESS; 
//		else if(KEY1==0)
//			return KEY1_PRESS; 
//		else if(KEY2==0)
//			return KEY2_PRESS; 
//	}
//	else if(KEY_UP==0&&KEY0==1&&KEY1==1&&KEY2==1)    //无按键按下
//		key=1;
//	return 0;
//}

/*********************************************END OF FILE**********************/
