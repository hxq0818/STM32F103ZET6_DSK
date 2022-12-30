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
* �� �� ��         : main
* ��������		   : ������
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
int main()
{
	u16 i=0;
	u8 fx=0;
	u16 data=1234;
	float fdata=12.34;
	char str[]="Hello World!";
	
	HAL_Init();                     //��ʼ��HAL�� 
	SystemClock_Init(RCC_PLL_MUL9); //����ʱ��,72M
	SysTick_Init(72);
	LED_Init();
	KEY_Init();
	EXTI_Init();
	TIM3_Init(1000-1,36000-1);  //��ʱ500ms
	TIM3_CH2_PWM_Init(500-1,72-1); //Ƶ����2Kh
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
							printf("���������data=%d\r\n",data);
			printf("�����������fdata=%0.2f\r\n",fdata);
			printf("���ʮ��������data=%X\r\n",data);
			printf("����˽�����data=%o\r\n",data);
			printf("����ַ���str=%s\r\n",str);
			}
		}
		TIM3_SetCompare2(i);  //iֵ������ȡ499����ΪARR���ֵ��499.

		HAL_Delay(10);
	}
}
