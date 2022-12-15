#include "hxq_drv_pwm.h"


/*******************************************************************************
* �� �� ��         : TIM3_CH2_PWM_Init
* ��������		   : TIM3ͨ��2 PWM��ʼ������
* ��    ��         : per:��װ��ֵ
					 psc:��Ƶϵ��
* ��    ��         : ��
*******************************************************************************/
void TIM3_CH2_PWM_Init(u16 per,u16 psc)
{
	TIM_HandleTypeDef TIM3_Handler;      	//��ʱ����� 
	TIM_OC_InitTypeDef TIM3_CH2Handler;	//��ʱ��3ͨ��2���
	
	TIM3_Handler.Instance=TIM3;          	//��ʱ��3
    TIM3_Handler.Init.Prescaler=psc;       //��ʱ����Ƶ
    TIM3_Handler.Init.CounterMode=TIM_COUNTERMODE_UP;//���ϼ���ģʽ
    TIM3_Handler.Init.Period=per;          //�Զ���װ��ֵ
    TIM3_Handler.Init.ClockDivision=TIM_CLOCKDIVISION_DIV1;
    HAL_TIM_PWM_Init(&TIM3_Handler);       //��ʼ��PWM
    
    TIM3_CH2Handler.OCMode=TIM_OCMODE_PWM1; //ģʽѡ��PWM1
    TIM3_CH2Handler.Pulse=per/2;            //���ñȽ�ֵ,��ֵ����ȷ��ռ�ձȣ�Ĭ�ϱȽ�ֵΪ�Զ���װ��ֵ��һ��,��ռ�ձ�Ϊ50%
    TIM3_CH2Handler.OCPolarity=TIM_OCPOLARITY_LOW; //����Ƚϼ���Ϊ�� 
    HAL_TIM_PWM_ConfigChannel(&TIM3_Handler,&TIM3_CH2Handler,TIM_CHANNEL_2);//����TIM3ͨ��2
	
    HAL_TIM_PWM_Start(&TIM3_Handler,TIM_CHANNEL_2);//����PWMͨ��2	
}

//��ʱ���ײ�������ʱ��ʹ�ܣ���������
//�˺����ᱻHAL_TIM_PWM_Init()����
//htim:��ʱ�����
void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef *htim)
{
	GPIO_InitTypeDef GPIO_Initure;
	
	__HAL_RCC_TIM3_CLK_ENABLE();			//ʹ�ܶ�ʱ��3
	__HAL_RCC_AFIO_CLK_ENABLE();			//ʹ��AFIOʱ�ӣ�Ҫ����TIMӳ��ʱ��ǰʹ��
	__HAL_AFIO_REMAP_TIM3_PARTIAL();		//TIM3ͨ�����Ų�����ӳ��ʹ��
	__HAL_RCC_GPIOB_CLK_ENABLE();			//����GPIOBʱ��
	
	GPIO_Initure.Pin=GPIO_PIN_5;           	//PB5
	GPIO_Initure.Mode=GPIO_MODE_AF_PP;  	//�����������
	GPIO_Initure.Pull=GPIO_PULLUP;          //����
	GPIO_Initure.Speed=GPIO_SPEED_FREQ_HIGH;//����
	HAL_GPIO_Init(GPIOB,&GPIO_Initure);
}

//����TIMͨ��2��ռ�ձ�
//compare:�Ƚ�ֵ
void TIM3_SetCompare2(u32 compare)
{
	TIM3->CCR2=compare; 
}
