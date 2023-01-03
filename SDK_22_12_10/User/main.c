#include "system.h"
#include "sysTick.h"
#include "hxq_drv_led.h"
#include "hxq_drv_beep.h"
#include "hxq_drv_key.h"
#include "hxq_drv_exti.h"
#include "hxq_drv_time.h"
#include "hxq_drv_pwm.h"
#include "hxq_drv_usart.h"
#include "hxq_drv_input.h"

/*******************************************************************************
* 函 数 名         : main
* 函数功能		   : 主函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
int main()
{
	u16 i=0;
	u8 fx=0;
	u16 data=1234;
	float fdata=12.34;
	char str[]="Hello World!";
	long long indata=0;
	
	HAL_Init();                     //初始化HAL库 
	SystemClock_Init(RCC_PLL_MUL9); //设置时钟,72M
	SysTick_Init(72);
	LED_Init();
	KEY_Init();
	EXTI_Init();
	TIM3_Init(1000-1,36000-1);  //定时500ms
	TIM3_CH2_PWM_Init(500-1,72-1); //频率是2Kh
	TIM5_CH1_Input_Init(0XFFFF,72-1); //以1MHZ的频率计数
	USART1_Init(115200);
	
	while(1)
	{
		if(TIM5_CH1_CAPTURE_STA&0x80) //成功捕获
		{
			indata=TIM5_CH1_CAPTURE_STA&0x3f;
			indata*=0xffff; //溢出次数乘以一次的计数次数时间 us
			indata+=TIM5_CH1_CAPTURE_VAL;//加上高电平捕获的时间
			printf("高电平持续时间：%lld us\r\n",indata); //总的高电平时间
			TIM5_CH1_CAPTURE_STA=0; //开始下一次捕获
		}
		
		i++;
		if(i%20==0)
		{
			LED1=!LED1;
		}
		delay_ms(10);
	}
}
