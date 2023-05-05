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

// 局部变量，用于保存转换计算后的电压值 	 
float ADC_ConvertedValueLocal;  
/**
  * @brief  主函数
  * @param  无  
  * @retval 无
  */
int main(void)
{	
	
	u8 res=0;
	u32 total,free;
	u32 flash_total,flash_free;
	
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
	
	AT24CXX_Init();
	while(AT24CXX_Check())  //检测AT24C02是否正常
	{
		DEBUG_LOG(HXQ_DEBUG_MODULE_AT24C02_LVL,"AT24C02检测不正常!\r\n");
		SysTick_Delay_Ms(500);
	}
	DEBUG_LOG(HXQ_DEBUG_MODULE_AT24C02_LVL,"AT24C02检测正常!\r\n");
	
	EN25QXX_Init();
	while(EN25QXX_ReadID()!=EN25Q128)			//检测不到EN25QXX
	{
		DEBUG_LOG(HXQ_DEBUG_MODULE_EN25Q128_LVL,"EN25Q128 Check Failed!\r\n");
		SysTick_Delay_Ms(500);
	}
	DEBUG_LOG(HXQ_DEBUG_MODULE_EN25Q128_LVL,"EN25Q128 Check Success!\r\n");
	
	FSMC_SRAM_Init();
	
	while(SD_Init())//检测不到SD卡
	{
		DEBUG_LOG(HXQ_DEBUG_MODULE_SD_LVL,"SD Card Error!\r\n");
		SysTick_Delay_Ms(500);					
	}
	
	//检测SD卡成功 			
	DEBUG_LOG(HXQ_DEBUG_MODULE_SD_LVL,"SD Card OK!\r\n");	
	
	//SD卡类型
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
	
	my_mem_init(SRAMIN);		//初始化内部内存池
	
	FATFS_Init();				//为fatfs相关变量申请内存				 
  	f_mount(fs[0],"0:",1); 		//挂载SD卡
	res=f_mount(fs[1],"1:",1); 	//挂载FLASH.
	if(res==0X0D)//FLASH磁盘,FAT文件系统错误,重新格式化FLASH
	{
		res=f_mkfs("1:",1,4096);//格式化FLASH,1,盘符;1,不需要引导区,8个扇区为1个簇
		if(res==0)
		{
			f_setlabel((const TCHAR *)"1:PRECHIN");	//设置Flash磁盘的名字为：PRECHIN
			DEBUG_LOG(HXQ_DEBUG_MODULE_FATFS_LVL,"格式化完成\r\n");
		}
		else 
			DEBUG_LOG(HXQ_DEBUG_MODULE_FATFS_LVL,"格式化失败\r\n");	//格式化失败
		SysTick_Delay_Ms(1000);
	}	
	
	while(fatfs_getfree("0:",&total,&free))	//得到SD卡的总容量和剩余容量
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
