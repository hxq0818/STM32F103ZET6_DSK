#ifndef _ds18b20_H
#define _ds18b20_H

#include "stm32f10x.h"

#include "user_project_config.h"


/*  DS18B20时钟端口、引脚定义 */
#define DS18B20_PORT 			GPIOG  
#define DS18B20_PIN 			(GPIO_Pin_11)
#define DS18B20_PORT_RCC		RCC_APB2Periph_GPIOG


////IO操作函数											   
//#define	DS18B20_DQ_OUT PGout(11) //数据端口	PG11
//#define	DS18B20_DQ_IN  PGin(11)  //数据端口	PG11 
//#define	DS18B20_DQ_IN	GPIO_ReadInputDataBit(DS18B20_PORT,DS18B20_PIN)
   	
u8 DS18B20_Init(void);			//初始化DS18B20
float DS18B20_GetTemperture(void);	//获取温度
void DS18B20_Start(void);		//开始温度转换
void DS18B20_Write_Byte(u8 dat);//写入一个字节
u8 DS18B20_Read_Byte(void);		//读出一个字节
u8 DS18B20_Read_Bit(void);		//读出一个位
u8 DS18B20_Check(void);			//检测是否存在DS18B20
void DS18B20_Reset(void);			//复位DS18B20   


///************************** DS18B20 连接引脚定义********************************/
//#define      DS18B20_DQ_SCK_APBxClock_FUN              RCC_APB2PeriphClockCmd
//#define      DS18B20_DQ_GPIO_CLK                       RCC_APB2Periph_GPIOG

//#define      DS18B20_DQ_GPIO_PORT                      GPIOG
//#define      DS18B20_DQ_GPIO_PIN                       GPIO_Pin_11

/************************** DS18B20 函数宏定义********************************/
#define      DS18B20_DQ_0	                            GPIO_ResetBits ( DS18B20_PORT, DS18B20_PIN ) 
#define      DS18B20_DQ_1	                            GPIO_SetBits ( DS18B20_PORT, DS18B20_PIN ) 

#define      DS18B20_DQ_IN()	                          GPIO_ReadInputDataBit ( DS18B20_PORT, DS18B20_PIN ) 



///************************** DS18B20 函数声明 ********************************/
//uint8_t                  DS18B20_Init                      ( void );
//void                     DS18B20_ReadId                    ( uint8_t * ds18b20_id );
//float                    DS18B20_GetTemp_SkipRom           ( void );
//float                    DS18B20_GetTemp_MatchRom          ( uint8_t * ds18b20_id );

#endif
