#include "system.h"
#include "sysTick.h"
#include "hxq_drv_led.h"
#include "hxq_drv_beep.h"
#include "hxq_drv_key.h"
#include "hxq_drv_exti.h"
#include "hxq_drv_time.h"
#include "hxq_drv_pwm.h"
#include "hxq_drv_usart.h"

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
	
	HAL_Init();                     //初始化HAL库 
	SystemClock_Init(RCC_PLL_MUL9); //设置时钟,72M
	SysTick_Init(72);
	LED_Init();
	KEY_Init();
	EXTI_Init();
	TIM3_Init(1000-1,36000-1);  //定时500ms
	TIM3_CH2_PWM_Init(500-1,72-1); //频率是2Kh
	USART1_Init(115200);
	
	while(1)
	{
		if(fx==0)
		{
			i++;
			if(i==300)
			{
				fx=1;
			}
		}
		else
		{
			i--;
			if(i==0)
			{
				fx=0;
							printf("输出整型数data=%d\r\n",data);
			printf("输出浮点型数fdata=%0.2f\r\n",fdata);
			printf("输出十六进制数data=%X\r\n",data);
			printf("输出八进制数data=%o\r\n",data);
			printf("输出字符串str=%s\r\n",str);
			}
		}
		TIM3_SetCompare2(i);  //i值最大可以取499，因为ARR最大值是499.

		HAL_Delay(10);
	}
}
