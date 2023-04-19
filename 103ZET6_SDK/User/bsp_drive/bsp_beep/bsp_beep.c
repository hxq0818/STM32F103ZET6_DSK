/*
 * @brief: ������Ӧ�ú����ӿ�
 * @version: V1.0
 * @Author: xiaoqing.huang
 * @Date: 2023-04-05 20:52:52
 * @LastEditors: LAPTOP-4DIHEQ1Q
 * @LastEditTime: 2023-04-19 19:59:43
 */
  
#include "bsp_beep.h"   

#include "log.h"
 /**
  * @brief  ��ʼ�����Ʒ�������IO
  * @param  ��
  * @retval ��
  */
void BEEP_GPIO_Config(void)
{		
		DEBUG_LOG(HXQ_DEBUG_MODULE_BEEP_LVL,"%s %d\r\n",__func__,__LINE__);
		/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
		GPIO_InitTypeDef GPIO_InitStructure;

		/*�������Ʒ�������GPIO�Ķ˿�ʱ��*/
		RCC_APB2PeriphClockCmd( BEEP_GPIO_CLK, ENABLE); 

		/*ѡ��Ҫ���Ʒ�������GPIO*/															   
		GPIO_InitStructure.GPIO_Pin = BEEP_GPIO_PIN;	

		/*����GPIOģʽΪͨ���������*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

		/*����GPIO����Ϊ50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

		/*���ÿ⺯������ʼ�����Ʒ�������GPIO*/
		GPIO_Init(BEEP_GPIO_PORT, &GPIO_InitStructure);			 
    
    /* �رշ�����*/
		GPIO_ResetBits(BEEP_GPIO_PORT, BEEP_GPIO_PIN);	 
}
/*********************************************END OF FILE**********************/
