/*
 * @brief: 
 * @version: V1.0
 * @Author: xiaoqing.huang
 * @Date: 2023-04-04 21:42:21
 * @LastEditors: LAPTOP-4DIHEQ1Q
 * @LastEditTime: 2023-05-05 21:11:47
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
#include "bsp_sram.h"
#include "malloc.h" 
#include "bsp_iic.h"
#include "bsp_at24c02.h"
#include "bsp_spi.h"
#include "bsp_en25q128.h"
#include "bsp_sd.h"
#include "ff.h" 
#include "fatfs_app.h"

#include "log.h"

extern __IO uint16_t ADC_ConvertedValue;

// �ֲ����������ڱ���ת�������ĵ�ѹֵ 	 
float ADC_ConvertedValueLocal;  
/**
  * @brief  ������
  * @param  ��  
  * @retval ��
  */
int main(void)
{	
	
	u8 res=0;
	u32 total,free;
	u32 flash_total,flash_free;
	
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
	
//	WWDG_Init();
	
	BASIC_TIM_Init();	
	/* ��ʱ����ʼ�� */
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
		DEBUG_LOG(HXQ_DEBUG_MODULE_TEP_LVL,"DS18B20���ʧ�ܣ�����!\r\n");
		Delay_ms(500);
	}
	DEBUG_LOG(HXQ_DEBUG_MODULE_TEP_LVL,"DS18B20���ɹ�!\r\n");
	
	AT24CXX_Init();
	while(AT24CXX_Check())  //���AT24C02�Ƿ�����
	{
		DEBUG_LOG(HXQ_DEBUG_MODULE_AT24C02_LVL,"AT24C02��ⲻ����!\r\n");
		SysTick_Delay_Ms(500);
	}
	DEBUG_LOG(HXQ_DEBUG_MODULE_AT24C02_LVL,"AT24C02�������!\r\n");
	
	EN25QXX_Init();
	while(EN25QXX_ReadID()!=EN25Q128)			//��ⲻ��EN25QXX
	{
		DEBUG_LOG(HXQ_DEBUG_MODULE_EN25Q128_LVL,"EN25Q128 Check Failed!\r\n");
		SysTick_Delay_Ms(500);
	}
	DEBUG_LOG(HXQ_DEBUG_MODULE_EN25Q128_LVL,"EN25Q128 Check Success!\r\n");
	
	FSMC_SRAM_Init();
	
	while(SD_Init())//��ⲻ��SD��
	{
		DEBUG_LOG(HXQ_DEBUG_MODULE_SD_LVL,"SD Card Error!\r\n");
		SysTick_Delay_Ms(500);					
	}
	
	//���SD���ɹ� 			
	DEBUG_LOG(HXQ_DEBUG_MODULE_SD_LVL,"SD Card OK!\r\n");	
	
	//SD������
	switch(SDCardInfo.CardType)
	{
		case SDIO_STD_CAPACITY_SD_CARD_V1_1:
			DEBUG_LOG(HXQ_DEBUG_MODULE_SD_LVL,"Card Type:SDSC V1.1\r\n");
			break;
		case SDIO_STD_CAPACITY_SD_CARD_V2_0:
			DEBUG_LOG(HXQ_DEBUG_MODULE_SD_LVL,"Card Type:SDSC V2.0\r\n");
			break;
		case SDIO_HIGH_CAPACITY_SD_CARD:
			DEBUG_LOG(HXQ_DEBUG_MODULE_SD_LVL,"Card Type:SDHC V2.0\r\n");
			break;
		case SDIO_MULTIMEDIA_CARD:
			DEBUG_LOG(HXQ_DEBUG_MODULE_SD_LVL,"Card Type:MMC Card\r\n");
			break;
	}	
	
	DEBUG_LOG(HXQ_DEBUG_MODULE_SD_LVL,"SD Card Size: %lldMB\r\n",SDCardInfo.CardCapacity>>20);
	
	my_mem_init(SRAMIN);		//��ʼ���ڲ��ڴ��
	
	FATFS_Init();				//Ϊfatfs��ر��������ڴ�				 
  	f_mount(fs[0],"0:",1); 		//����SD��
	res=f_mount(fs[1],"1:",1); 	//����FLASH.
	if(res==0X0D)//FLASH����,FAT�ļ�ϵͳ����,���¸�ʽ��FLASH
	{
		res=f_mkfs("1:",1,4096);//��ʽ��FLASH,1,�̷�;1,����Ҫ������,8������Ϊ1����
		if(res==0)
		{
			f_setlabel((const TCHAR *)"1:PRECHIN");	//����Flash���̵�����Ϊ��PRECHIN
			DEBUG_LOG(HXQ_DEBUG_MODULE_FATFS_LVL,"��ʽ�����\r\n");
		}
		else 
			DEBUG_LOG(HXQ_DEBUG_MODULE_FATFS_LVL,"��ʽ��ʧ��\r\n");	//��ʽ��ʧ��
		SysTick_Delay_Ms(1000);
	}	
	
	while(fatfs_getfree("0:",&total,&free))	//�õ�SD������������ʣ������
	{
		SysTick_Delay_Ms(200);
	}			
	while(fatfs_getfree("1:",&flash_total,&flash_free))
	{
		SysTick_Delay_Ms(200);
	}
	DEBUG_LOG(HXQ_DEBUG_MODULE_FATFS_LVL,"flash_total:%d flash_free:%d\r\n",flash_total,flash_free);
	
	while (1)
	{
	}
}

/*********************************************END OF FILE**********************/
