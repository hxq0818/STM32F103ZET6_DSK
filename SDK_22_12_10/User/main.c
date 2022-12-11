#include "system.h"
#include "hxq_drv_led.h"
#include "sysTick.h"
#include "hxq_drv_beep.h"

/*******************************************************************************
* �� �� ��         : main
* ��������		   : ������
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
int main()
{
	
	HAL_Init();                     //��ʼ��HAL�� 
	SystemClock_Init(RCC_PLL_MUL9); //����ʱ��,72M
	SysTick_Init(72);
	LED_Init();
	
	while(1)
	{
		HAL_GPIO_TogglePin(LED1_PORT,LED1_PIN);
		HAL_GPIO_TogglePin(LED2_PORT,LED1_PIN);
		HAL_GPIO_TogglePin(BEEP_PORT,BEEP_PIN);
		HAL_Delay(1000);
	}
}
