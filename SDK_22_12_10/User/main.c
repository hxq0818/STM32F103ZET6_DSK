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
	long long indata=0;
	
	HAL_Init();                     //��ʼ��HAL�� 
	SystemClock_Init(RCC_PLL_MUL9); //����ʱ��,72M
	SysTick_Init(72);
	LED_Init();
	KEY_Init();
	EXTI_Init();
	TIM3_Init(1000-1,36000-1);  //��ʱ500ms
	TIM3_CH2_PWM_Init(500-1,72-1); //Ƶ����2Kh
	TIM5_CH1_Input_Init(0XFFFF,72-1); //��1MHZ��Ƶ�ʼ���
	USART1_Init(115200);
	
	while(1)
	{
		if(TIM5_CH1_CAPTURE_STA&0x80) //�ɹ�����
		{
			indata=TIM5_CH1_CAPTURE_STA&0x3f;
			indata*=0xffff; //�����������һ�εļ�������ʱ�� us
			indata+=TIM5_CH1_CAPTURE_VAL;//���ϸߵ�ƽ�����ʱ��
			printf("�ߵ�ƽ����ʱ�䣺%lld us\r\n",indata); //�ܵĸߵ�ƽʱ��
			TIM5_CH1_CAPTURE_STA=0; //��ʼ��һ�β���
		}
		
		i++;
		if(i%20==0)
		{
			LED1=!LED1;
		}
		delay_ms(10);
	}
}
