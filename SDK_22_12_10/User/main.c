#include "system.h"
#include "hxq_drv_led.h"
#include "sysTick.h"


/*******************************************************************************
* 函 数 名         : main
* 函数功能		   : 主函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
int main()
{
	
	HAL_Init();                     //初始化HAL库 
	SystemClock_Init(RCC_PLL_MUL9); //设置时钟,72M
	SysTick_Init(72);
	LED_Init();
	
	while(1)
	{
		HAL_GPIO_TogglePin(LED1_PORT,LED1_PIN);
		HAL_Delay(1000);
	}
}
