/*
 * @brief: 
 * @Author: xiaoqing.huang
 * @version: V1.0
 * @Date: 2023-04-19 20:54:33
 * @LastEditors: LAPTOP-4DIHEQ1Q
 * @LastEditTime: 2023-05-02 23:22:35
 */

// ������ʱ��TIMx,x[6,7]��ʱ��ʼ������

#include "bsp_time.h" 
#include "bsp_usart.h"
#include "bsp_led.h"
#include "bsp_adc.h"
#include "bsp_ds18b20.h"
#include "malloc.h"
#include "bsp_at24c02.h"
#include "bsp_en25q128.h"

#include "log.h"
volatile uint32_t time6 = 0; // ms ��ʱ���� 
volatile uint32_t time7 = 0; // ms ��ʱ���� 


// ��ʱ�����벶���û��Զ�������ṹ�嶨��
TIM_ICUserValueTypeDef TIM_ICUserValueStructure = {0,0,0,0};


/*
 * ע�⣺TIM_TimeBaseInitTypeDef�ṹ��������5����Ա��TIM6��TIM7�ļĴ�������ֻ��
 * TIM_Prescaler��TIM_Period������ʹ��TIM6��TIM7��ʱ��ֻ���ʼ����������Ա���ɣ�
 * ����������Ա��ͨ�ö�ʱ���͸߼���ʱ������.
 *-----------------------------------------------------------------------------
 *typedef struct
 *{ TIM_Prescaler            ����
 *	TIM_CounterMode			     TIMx,x[6,7]û�У���������
 *  TIM_Period               ����
 *  TIM_ClockDivision        TIMx,x[6,7]û�У���������
 *  TIM_RepetitionCounter    TIMx,x[1,8,15,16,17]����
 *}TIM_TimeBaseInitTypeDef; 
 *-----------------------------------------------------------------------------
 */

void BASIC_TIM_Init(void)
{
#if TIME6_FUNCTION_SUPPORT
	// ������ʱ��ʱ��,���ڲ�ʱ��CK_INT=72M
    RCC_APB1PeriphClockCmd(TIME6_BASIC_TIM_CLK, ENABLE);
	TIM6_Init();
#endif
#if TIME7_FUNCTION_SUPPORT
	// ������ʱ��ʱ��,���ڲ�ʱ��CK_INT=72M
	RCC_APB1PeriphClockCmd(TIME7_BASIC_TIM_CLK, ENABLE);
	TIM7_Init();
#endif
}



#if TIME6_FUNCTION_SUPPORT
void TIM6_Init(void)
{
	// �ж����ȼ�����
	NVIC_InitTypeDef NVIC_InitStructure; 
    // �����ж���Ϊ0
    // NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);		
	// �����ж���Դ
    NVIC_InitStructure.NVIC_IRQChannel = TIME6_BASIC_TIM_IRQ ;	
	// ���������ȼ�Ϊ 0
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	 
	// ������ռ���ȼ�Ϊ3
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;	
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
		

	
	// �Զ���װ�ؼĴ�����ֵ���ۼ�TIM_Period+1��Ƶ�ʺ����һ�����»����ж�
    TIM_TimeBaseStructure.TIM_Period = TIME6_BASIC_TIM_Period;	

	// ʱ��Ԥ��Ƶ��Ϊ
    TIM_TimeBaseStructure.TIM_Prescaler= TIME6_BASIC_TIM_Prescaler;
	
	// ʱ�ӷ�Ƶ���� ��������ʱ��û�У����ù�
    //TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;
		
	// ����������ģʽ��������ʱ��ֻ�����ϼ�����û�м���ģʽ������
    //TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; 
		
	// �ظ���������ֵ��������ʱ��û�У����ù�
	//TIM_TimeBaseStructure.TIM_RepetitionCounter=0;
	
	// ��ʼ����ʱ��
    TIM_TimeBaseInit(TIME6_BASIC_TIM, &TIM_TimeBaseStructure);
		
	// ����������жϱ�־λ
    TIM_ClearFlag(TIME6_BASIC_TIM, TIM_FLAG_Update);
	  
	// �����������ж�
    TIM_ITConfig(TIME6_BASIC_TIM,TIM_IT_Update,ENABLE);
		
	// ʹ�ܼ�����
    TIM_Cmd(TIME6_BASIC_TIM, ENABLE);
}

void  TIME6_BASIC_TIM_IRQHandler (void)
{
	if ( TIM_GetITStatus( TIME6_BASIC_TIM, TIM_IT_Update) != RESET ) 
	{	
		time6++;
		TIM_ClearITPendingBit(TIME6_BASIC_TIM , TIM_FLAG_Update);  		 
	}
	if ( time6 == 1000 ) /* 1000 * 1 ms = 1s ʱ�䵽 */
		{
				time6 = 0;     
//			DEBUG_LOG(HXQ_DEBUG_MODULE_TIM_LVL,"time6����\r\n");
//				LED0(0); 
		}
		if(time6 == 500)
		{
//				LED0(1); 
		}	
}
#endif

#if TIME7_FUNCTION_SUPPORT
void TIM7_Init(void)
{
	NVIC_InitTypeDef NVIC_InitStructure; 

	// �����ж���Դ
    NVIC_InitStructure.NVIC_IRQChannel = TIME7_BASIC_TIM_IRQ ;	
	// ���������ȼ�Ϊ 0
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	 
	// ������ռ���ȼ�Ϊ3
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 4;	
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	// �Զ���װ�ؼĴ�����ֵ���ۼ�TIM_Period+1��Ƶ�ʺ����һ�����»����ж�
    TIM_TimeBaseStructure.TIM_Period = TIME7_BASIC_TIM_Period;	

	// ʱ��Ԥ��Ƶ��Ϊ
    TIM_TimeBaseStructure.TIM_Prescaler= TIME7_BASIC_TIM_Prescaler;
	
	// ʱ�ӷ�Ƶ���� ��������ʱ��û�У����ù�
    //TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;
		
	// ����������ģʽ��������ʱ��ֻ�����ϼ�����û�м���ģʽ������
    //TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; 
		
	// �ظ���������ֵ��������ʱ��û�У����ù�
	//TIM_TimeBaseStructure.TIM_RepetitionCounter=0;
	
	// ��ʼ����ʱ��
    TIM_TimeBaseInit(TIME7_BASIC_TIM, &TIM_TimeBaseStructure);
		
	// ����������жϱ�־λ
    TIM_ClearFlag(TIME7_BASIC_TIM, TIM_FLAG_Update);
	  
	// �����������ж�
    TIM_ITConfig(TIME7_BASIC_TIM,TIM_IT_Update,ENABLE);
		
	// ʹ�ܼ�����
    TIM_Cmd(TIME7_BASIC_TIM, ENABLE);	
}


void  TIME7_BASIC_TIM_IRQHandler (void)
{
	if ( TIM_GetITStatus( TIME7_BASIC_TIM, TIM_IT_Update) != RESET ) 
	{	
		time7++;
		TIM_ClearITPendingBit(TIME7_BASIC_TIM , TIM_FLAG_Update);  		 
	}	
	
		if ( time7 == 1000 ) /* 1000 * 1 ms = 1s ʱ�䵽 */
		{
				time7 = 0;   
				DEBUG_LOG(HXQ_DEBUG_MODULE_TIM_LVL,"time7����\r\n");			
			DEBUG_LOG(HXQ_DEBUG_MODULE_ADC_LVL,"voltage:%d\r\n",Get_ADC_Value(ADC_Channel_1,1));
			DEBUG_LOG(HXQ_DEBUG_MODULE_ADC_LVL,"tep:%d\r\n",Get_Temperture());
			DEBUG_LOG(HXQ_DEBUG_MODULE_ADC_LVL,"lsens_value:%d\r\n",Lsens_Get_Val());
			DEBUG_LOG(HXQ_DEBUG_MODULE_TEP_LVL,"temper:%.2f��C\r\n",DS18B20_GetTemperture());
			
			
			//				LED1(0); 
			
		}
		if(time7 == 500)
		{
			
//				LED1(1); 
		}
}

#endif




/* ----------------   PWM�ź� ���ں�ռ�ձȵļ���--------------- */
// ARR ���Զ���װ�ؼĴ�����ֵ
// CLK_cnt����������ʱ�ӣ����� Fck_int / (psc+1) = 72M/(psc+1)
// PWM �źŵ����� T = ARR * (1/CLK_cnt) = ARR*(PSC+1) / 72M
// ռ�ձ�P=CCR/(ARR+1)

void TIM5_Input_Capture(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;

  // ���벶��ͨ�� GPIO ��ʼ��
	RCC_APB2PeriphClockCmd(TIME5_GENERAL_TIM_CH1_GPIO_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  TIME5_GENERAL_TIM_CH1_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
  GPIO_Init(TIME5_GENERAL_TIM_CH1_PORT, &GPIO_InitStructure);	

      NVIC_InitTypeDef NVIC_InitStructure; 
    // �����ж���Ϊ0
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);		
		// �����ж���Դ
    NVIC_InitStructure.NVIC_IRQChannel = TIME5_GENERAL_TIM_IRQ ;	
		// ���������ȼ�Ϊ 0
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	 
	  // ������ռ���ȼ�Ϊ3
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;	
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

	  // ������ʱ��ʱ��,���ڲ�ʱ��CK_INT=72M
	RCC_APB1PeriphClockCmd(TIME5_GENERAL_TIM_CLK,ENABLE);

/*--------------------ʱ���ṹ���ʼ��-------------------------*/	
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	// �Զ���װ�ؼĴ�����ֵ���ۼ�TIM_Period+1��Ƶ�ʺ����һ�����»����ж�
	TIM_TimeBaseStructure.TIM_Period=TIME5_GENERAL_TIM_PERIOD;	
	// ����CNT��������ʱ�� = Fck_int/(psc+1)
	TIM_TimeBaseStructure.TIM_Prescaler= TIME5_GENERAL_TIM_PSC;	
	// ʱ�ӷ�Ƶ���� ����������ʱ��ʱ��Ҫ�õ�
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;		
	// ����������ģʽ������Ϊ���ϼ���
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;		
	// �ظ���������ֵ��û�õ����ù�
	TIM_TimeBaseStructure.TIM_RepetitionCounter=0;	
	// ��ʼ����ʱ��
	TIM_TimeBaseInit(TIME5_GENERAL_TIM, &TIM_TimeBaseStructure);

	/*--------------------���벶��ṹ���ʼ��-------------------*/	
	TIM_ICInitTypeDef TIM_ICInitStructure;
	// �������벶���ͨ������Ҫ���ݾ����GPIO������
	TIM_ICInitStructure.TIM_Channel = TIME5_GENERAL_TIM_CHANNEL_x;
	// ���벶���źŵļ�������
	TIM_ICInitStructure.TIM_ICPolarity = GENERAL_TIM_STRAT_ICPolarity;
	// ����ͨ���Ͳ���ͨ����ӳ���ϵ����ֱ���ͷ�ֱ������
	TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;
	// �������Ҫ��������źŵķ�Ƶϵ��
	TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;
	// �������Ҫ��������źŵ��˲�ϵ��
	TIM_ICInitStructure.TIM_ICFilter = 0;
	// ��ʱ�����벶���ʼ��
	TIM_ICInit(TIME5_GENERAL_TIM, &TIM_ICInitStructure);
	
	// ������ºͲ����жϱ�־λ
  TIM_ClearFlag(TIME5_GENERAL_TIM, TIM_FLAG_Update|TIME5_GENERAL_TIM_IT_CCx);	
  // �������ºͲ����ж�  
	TIM_ITConfig (TIME5_GENERAL_TIM, TIM_IT_Update | TIME5_GENERAL_TIM_IT_CCx, ENABLE );
	
	// ʹ�ܼ�����
	TIM_Cmd(TIME5_GENERAL_TIM, ENABLE);
}


void TIME5_GENERAL_TIM_INT_FUN(void)
{
	// ��Ҫ��������źŵ����ڴ��ڶ�ʱ�������ʱʱ����ʱ���ͻ���������������ж�
	// ���ʱ��������Ҫ�������Ķ�ʱ���ڼӵ������źŵ�ʱ������ȥ
	// TIM ������������ʱ��
	uint32_t time;
	uint32_t TIM_PscCLK = 72000000 / (TIME5_GENERAL_TIM_PSC+1);
	if ( TIM_GetITStatus ( TIME5_GENERAL_TIM, TIM_IT_Update) != RESET )               
	{	
		TIM_ICUserValueStructure.Capture_Period ++;		
		TIM_ClearITPendingBit ( TIME5_GENERAL_TIM, TIM_FLAG_Update ); 		
	}

	// �����ز����ж�
	if ( TIM_GetITStatus (TIME5_GENERAL_TIM, TIME5_GENERAL_TIM_IT_CCx ) != RESET)
	{
		// ��һ�β���
		if ( TIM_ICUserValueStructure.Capture_StartFlag == 0 )
		{
			// ��������0
			TIM_SetCounter ( TIME5_GENERAL_TIM, 0 );
			// �Զ���װ�ؼĴ������±�־��0
			TIM_ICUserValueStructure.Capture_Period = 0;
      // �沶��ȽϼĴ�����ֵ�ı�����ֵ��0			
			TIM_ICUserValueStructure.Capture_CcrValue = 0;

			// ����һ�β���������֮�󣬾ͰѲ����������Ϊ�½���
			TIM_OC1PolarityConfig(TIME5_GENERAL_TIM, TIM_ICPolarity_Falling);
      // ��ʼ�����׼��1			
			TIM_ICUserValueStructure.Capture_StartFlag = 1;			
		}
		// �½��ز����ж�
		else // �ڶ��β���
		{
			// ��ȡ����ȽϼĴ�����ֵ�����ֵ���ǲ��񵽵ĸߵ�ƽ��ʱ���ֵ
			TIM_ICUserValueStructure.Capture_CcrValue = 
			TIM_GetCapture1(TIME5_GENERAL_TIM);

			// ���ڶ��β����½���֮�󣬾ͰѲ����������Ϊ�����أ��ÿ����µ�һ�ֲ���
			TIM_OC1PolarityConfig(TIME5_GENERAL_TIM, TIM_ICPolarity_Rising);
      // ��ʼ�����־��0		
			TIM_ICUserValueStructure.Capture_StartFlag = 0;
      // ������ɱ�־��1			
			TIM_ICUserValueStructure.Capture_FinishFlag = 1;		
		}

		TIM_ClearITPendingBit (TIME5_GENERAL_TIM,TIME5_GENERAL_TIM_IT_CCx);	    
		if(TIM_ICUserValueStructure.Capture_FinishFlag == 1)
		{
			// ����ߵ�ƽʱ��ļ�������ֵ
			time = TIM_ICUserValueStructure.Capture_Period * (TIME5_GENERAL_TIM_PERIOD+1) + 
			       (TIM_ICUserValueStructure.Capture_CcrValue+1);
			
			// ��ӡ�ߵ�ƽ����ʱ��
			printf("Capture_Period:%d Capture_CcrValue:%d\r\n",TIM_ICUserValueStructure.Capture_Period,TIM_ICUserValueStructure.Capture_CcrValue);
			printf ( "\r\n��øߵ�ƽ����ʱ�䣺%d.%d s\r\n",time/TIM_PscCLK,time%TIM_PscCLK );
			AT24CXX_WriteOneByte(0,time/TIM_PscCLK);
			printf("��ȡ�������ǣ�%d\r\n",AT24CXX_ReadOneByte(0));
			TIM_ICUserValueStructure.Capture_FinishFlag = 0;			
		}	
	}		
}

/*********************************************END OF FILE**********************/
