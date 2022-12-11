#include "system.h"
#include "sysTick.h"
#include "hxq_drv_led.h"
#include "hxq_drv_beep.h"
#include "hxq_drv_key.h"

/*******************************************************************************
* 函 数 名         : main
* 函数功能		   : 主函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
int main()
{
	u8 key,i=0;
	
	HAL_Init();                     //初始化HAL库 
	SystemClock_Init(RCC_PLL_MUL9); //设置时钟,72M
	SysTick_Init(72);
	LED_Init();
	KEY_Init();
	
	while(1)
	{
		key=KEY_Scan(0);   //扫描按键
		switch(key)
		{
			case KEY_UP_PRESS: HAL_GPIO_TogglePin(LED2_PORT,LED1_PIN);break;   //点亮DS1指示灯
			case KEY1_PRESS: HAL_GPIO_TogglePin(LED2_PORT,LED1_PIN);break;    //熄灭DS1指示灯
			case KEY2_PRESS: HAL_GPIO_TogglePin(BEEP_PORT,BEEP_PIN);break;    //蜂鸣器开
			case KEY0_PRESS: HAL_GPIO_TogglePin(BEEP_PORT,BEEP_PIN);break;    //蜂鸣器关
		}
		i++;
		if(i%20==0)
		{
			HAL_GPIO_TogglePin(LED1_PORT,LED1_PIN);     //LED1状态取反
		}
		HAL_Delay(10);
	}
}
