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
  * @brief   ����Ӧ��bsp��ɨ��ģʽ��
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:Ұ�� F103-�Ե� STM32 ������ 
  * ��̳    :http://www.firebbs.cn
  * �Ա�    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */ 
  
#include "bsp_key.h"  

#include "bsp_SysTick.h"
/**
  * @brief  ���ð����õ���I/O��
  * @param  ��
  * @retval ��
  */
void Key_GPIO_Config(void)
{
//	GPIO_InitTypeDef GPIO_InitStructure;
//	
//	/*���������˿ڵ�ʱ��*/
//	RCC_APB2PeriphClockCmd(KEY_UP_GPIO_CLK|KEY0_GPIO_CLK|KEY1_GPIO_CLK|KEY2_GPIO_CLK,ENABLE);
//	
//	//ѡ�񰴼�������
//	GPIO_InitStructure.GPIO_Pin = KEY_UP_GPIO_PIN; 
//	// ���ð���������Ϊ��������//�������� 
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
//	//ʹ�ýṹ���ʼ������
//	GPIO_Init(KEY1_GPIO_PORT, &GPIO_InitStructure);
//	
//	//ѡ�񰴼�������
//	GPIO_InitStructure.GPIO_Pin = KEY0_GPIO_PIN|KEY1_GPIO_PIN|KEY2_GPIO_PIN;
//	//���ð���������Ϊ��������//��������
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 
//	//ʹ�ýṹ���ʼ������
//	GPIO_Init(KEY2_GPIO_PORT, &GPIO_InitStructure);	
}

 /*
 * ��������Key_Scan
 * ����  ������Ƿ��а�������
 * ����  ��GPIOx��x ������ A��B��C��D���� E
 *		     GPIO_Pin������ȡ�Ķ˿�λ 	
 * ���  ��KEY_OFF(û���°���)��KEY_ON�����°�����
 */
uint8_t Key_Scan(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin)
{			
	/*����Ƿ��а������� */
	if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_ON )  
	{	 
		/*�ȴ������ͷ� */
		while(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_ON);   
		return 	KEY_ON;	 
	}
	else
		return KEY_OFF;
}

///*******************************************************************************
//* �� �� ��         : KEY_Scan
//* ��������		   : ����ɨ����
//* ��    ��         : mode=0:���ΰ��°���
//					 mode=1���������°���
//* ��    ��         : 0��δ�а�������
//					 KEY_UP_PRESS��KEY_UP������
//					 KEY0_PRESS��KEY0������
//					 KEY1_PRESS��KEY1������
//					 KEY2_PRESS��KEY2������
//*******************************************************************************/
//u8 KEY_Scan(u8 mode)
//{
//	static u8 key=1;
//	
//	if(mode==1) //������������
//		key=1;
//	if(key==1&&(KEY_UP==1||KEY0==0||KEY1==0||KEY2==0)) //����һ����������
//	{
////		delay_ms(10);  //����
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
//	else if(KEY_UP==0&&KEY0==1&&KEY1==1&&KEY2==1)    //�ް�������
//		key=1;
//	return 0;
//}

/*********************************************END OF FILE**********************/
