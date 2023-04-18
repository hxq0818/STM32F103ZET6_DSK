/**
  ******************************************************************************
  * @file    bsp_exti.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   I/O���ж�Ӧ��bsp
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:Ұ�� F103-�Ե� STM32 ������ 
  * ��̳    :http://www.firebbs.cn
  * �Ա�    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */
  
#include "bsp_exti.h"
#include "bsp_key.h"
#include "bsp_beep.h"
#include "bsp_led.h"

#include "log.h"
 /**
  * @brief  ���� IOΪEXTI�жϿڣ��������ж����ȼ�
  * @param  ��
  * @retval ��
  */
void EXTI_Key_Config(void)
{
	DEBUG_LOG(HXQ_DEBUG_MODULE_KEY_LVL,"%s %d\r\n",__func__,__LINE__);
	GPIO_InitTypeDef GPIO_InitStructure; //����ṹ�����	
	NVIC_InitTypeDef NVIC_InitStructure;
	EXTI_InitTypeDef  EXTI_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOE,ENABLE);	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);

#if KEY_UP_EXTI_FUNCTION_SUPPORT
	GPIO_InitStructure.GPIO_Pin=KEY_UP_EXTI_GPIO_PIN;	   			/* ����KEY_UP�ܽŵ�GPIO */
	GPIO_InitStructure.GPIO_Mode=KEY_UP_EXTI_GPIO_MODE;				/* �������� */
	GPIO_Init(KEY_UP_EXTI_GPIO_PORT,&GPIO_InitStructure);		  /* ��ʼ��GPIO */
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource0);/* ѡ��EXTI���ź�Դ */
	
		//EXTI0 NVIC ����
	NVIC_InitStructure.NVIC_IRQChannel = KEY_UP_EXTI_IRQ;/* �����ж�Դ */
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=KEY_UP_EXTI_IRQ_PREEMPTION_PRIORITY;//��ռ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =KEY_UP_EXTI_IRQ_SUB_PRIORITY;		//�����ȼ�
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);	//����ָ���Ĳ�����ʼ��VIC�Ĵ���	
	
	EXTI_InitStructure.EXTI_Line=KEY_UP_EXTI_LINE;						/* �ж���· */
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;					/* �ж�ģʽ */
	EXTI_InitStructure.EXTI_Trigger=KEY_UP_EXTI_TRIGGER;			/* �жϳ�����ʽ */
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;
	EXTI_Init(&EXTI_InitStructure);
#endif

#if KEY0_EXTI_FUNCTION_SUPPORT
	GPIO_InitStructure.GPIO_Pin=KEY0_EXTI_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode=KEY0_EXTI_GPIO_MODE;	//��������
	GPIO_Init(KEY0_EXTI_GPIO_PORT,&GPIO_InitStructure);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource4);//ѡ��GPIO�ܽ������ⲿ�ж���·

		//EXTI4 NVIC ����
	NVIC_InitStructure.NVIC_IRQChannel = KEY0_EXTI_IRQ;//EXTI4�ж�ͨ��
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=KEY0_EXTI_IRQ_PREEMPTION_PRIORITY;//��ռ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =KEY0_EXTI_IRQ_SUB_PRIORITY;		//�����ȼ�
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);	//����ָ���Ĳ�����ʼ��VIC�Ĵ���
	
	EXTI_InitStructure.EXTI_Line=KEY0_EXTI_LINE; 
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger=KEY0_EXTI_TRIGGER;
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;
	EXTI_Init(&EXTI_InitStructure);
#endif

#if KEY1_EXTI_FUNCTION_SUPPORT
	GPIO_InitStructure.GPIO_Pin=KEY1_EXTI_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode=KEY1_EXTI_GPIO_MODE;	//��������
	GPIO_Init(KEY1_EXTI_GPIO_PORT,&GPIO_InitStructure);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource3);//ѡ��GPIO�ܽ������ⲿ�ж���·

	//EXTI3 NVIC ����
	NVIC_InitStructure.NVIC_IRQChannel = KEY1_EXTI_IRQ;//EXTI3�ж�ͨ��
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=KEY1_EXTI_IRQ_PREEMPTION_PRIORITY;//��ռ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =KEY1_EXTI_IRQ_SUB_PRIORITY;		//�����ȼ�
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);	//����ָ���Ĳ�����ʼ��VIC�Ĵ���
	
	EXTI_InitStructure.EXTI_Line=KEY1_EXTI_LINE; 
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger=KEY1_EXTI_TRIGGER;
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;
	EXTI_Init(&EXTI_InitStructure);
#endif
#if KEY2_EXTI_FUNCTION_SUPPORT
	GPIO_InitStructure.GPIO_Pin=KEY2_EXTI_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode=KEY2_EXTI_GPIO_MODE;	//��������
	GPIO_Init(KEY2_EXTI_GPIO_PORT,&GPIO_InitStructure);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource2);//ѡ��GPIO�ܽ������ⲿ�ж���·
	
	//EXTI2 NVIC ����
	NVIC_InitStructure.NVIC_IRQChannel = KEY2_EXTI_IRQ;//EXTI2�ж�ͨ��
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=KEY2_EXTI_IRQ_PREEMPTION_PRIORITY;//��ռ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =KEY2_EXTI_IRQ_SUB_PRIORITY;		//�����ȼ�
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);	//����ָ���Ĳ�����ʼ��VIC�Ĵ���
	
	EXTI_InitStructure.EXTI_Line=KEY2_EXTI_LINE; 
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger=KEY2_EXTI_TRIGGER;
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;
	EXTI_Init(&EXTI_InitStructure);
#endif
}

/*******************************************************************************
* �� �� ��         : EXTI0_IRQHandler
* ��������		   : �ⲿ�ж�0����
* ��    ��         : ��
* ��    ��         : ��
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
* �� �� ��         : EXTI2_IRQHandler
* ��������		   : �ⲿ�ж�2����
* ��    ��         : ��
* ��    ��         : ��
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
* �� �� ��         : EXTI3_IRQHandler
* ��������		   : �ⲿ�ж�3����
* ��    ��         : ��
* ��    ��         : ��
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
* �� �� ��         : EXTI4_IRQHandler
* ��������		   : �ⲿ�ж�4����
* ��    ��         : ��
* ��    ��         : ��
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
