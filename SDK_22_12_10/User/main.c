#include "system.h"
#include "sysTick.h"
#include "hxq_drv_led.h"
#include "hxq_drv_beep.h"
#include "hxq_drv_key.h"

/*******************************************************************************
* �� �� ��         : main
* ��������		   : ������
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
int main()
{
	u8 key,i=0;
	
	HAL_Init();                     //��ʼ��HAL�� 
	SystemClock_Init(RCC_PLL_MUL9); //����ʱ��,72M
	SysTick_Init(72);
	LED_Init();
	KEY_Init();
	
	while(1)
	{
		key=KEY_Scan(0);   //ɨ�谴��
		switch(key)
		{
			case KEY_UP_PRESS: HAL_GPIO_TogglePin(LED2_PORT,LED1_PIN);break;   //����DS1ָʾ��
			case KEY1_PRESS: HAL_GPIO_TogglePin(LED2_PORT,LED1_PIN);break;    //Ϩ��DS1ָʾ��
			case KEY2_PRESS: HAL_GPIO_TogglePin(BEEP_PORT,BEEP_PIN);break;    //��������
			case KEY0_PRESS: HAL_GPIO_TogglePin(BEEP_PORT,BEEP_PIN);break;    //��������
		}
		i++;
		if(i%20==0)
		{
			HAL_GPIO_TogglePin(LED1_PORT,LED1_PIN);     //LED1״̬ȡ��
		}
		HAL_Delay(10);
	}
}
