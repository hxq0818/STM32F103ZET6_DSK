/*
 * @brief: 
 * @Author: xiaoqing.huang
 * @version: V1.0
 * @Date: 2023-04-19 20:54:33
 * @LastEditors: LAPTOP-4DIHEQ1Q
 * @LastEditTime: 2023-05-02 23:22:35
 */

// 基本定时器TIMx,x[6,7]定时初始化函数

#include "bsp_time.h" 
#include "bsp_usart.h"
#include "bsp_led.h"
#include "bsp_adc.h"
#include "bsp_ds18b20.h"
#include "malloc.h"
#include "bsp_at24c02.h"
#include "bsp_en25q128.h"

#include "log.h"
volatile uint32_t time6 = 0; // ms 计时变量 
volatile uint32_t time7 = 0; // ms 计时变量 


// 定时器输入捕获用户自定义变量结构体定义
TIM_ICUserValueTypeDef TIM_ICUserValueStructure = {0,0,0,0};


/*
 * 注意：TIM_TimeBaseInitTypeDef结构体里面有5个成员，TIM6和TIM7的寄存器里面只有
 * TIM_Prescaler和TIM_Period，所以使用TIM6和TIM7的时候只需初始化这两个成员即可，
 * 另外三个成员是通用定时器和高级定时器才有.
 *-----------------------------------------------------------------------------
 *typedef struct
 *{ TIM_Prescaler            都有
 *	TIM_CounterMode			     TIMx,x[6,7]没有，其他都有
 *  TIM_Period               都有
 *  TIM_ClockDivision        TIMx,x[6,7]没有，其他都有
 *  TIM_RepetitionCounter    TIMx,x[1,8,15,16,17]才有
 *}TIM_TimeBaseInitTypeDef; 
 *-----------------------------------------------------------------------------
 */

void BASIC_TIM_Init(void)
{
#if TIME6_FUNCTION_SUPPORT
	// 开启定时器时钟,即内部时钟CK_INT=72M
    RCC_APB1PeriphClockCmd(TIME6_BASIC_TIM_CLK, ENABLE);
	TIM6_Init();
#endif
#if TIME7_FUNCTION_SUPPORT
	// 开启定时器时钟,即内部时钟CK_INT=72M
	RCC_APB1PeriphClockCmd(TIME7_BASIC_TIM_CLK, ENABLE);
	TIM7_Init();
#endif
}



#if TIME6_FUNCTION_SUPPORT
void TIM6_Init(void)
{
	// 中断优先级配置
	NVIC_InitTypeDef NVIC_InitStructure; 
    // 设置中断组为0
    // NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);		
	// 设置中断来源
    NVIC_InitStructure.NVIC_IRQChannel = TIME6_BASIC_TIM_IRQ ;	
	// 设置主优先级为 0
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	 
	// 设置抢占优先级为3
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;	
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
		

	
	// 自动重装载寄存器的值，累计TIM_Period+1个频率后产生一个更新或者中断
    TIM_TimeBaseStructure.TIM_Period = TIME6_BASIC_TIM_Period;	

	// 时钟预分频数为
    TIM_TimeBaseStructure.TIM_Prescaler= TIME6_BASIC_TIM_Prescaler;
	
	// 时钟分频因子 ，基本定时器没有，不用管
    //TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;
		
	// 计数器计数模式，基本定时器只能向上计数，没有计数模式的设置
    //TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; 
		
	// 重复计数器的值，基本定时器没有，不用管
	//TIM_TimeBaseStructure.TIM_RepetitionCounter=0;
	
	// 初始化定时器
    TIM_TimeBaseInit(TIME6_BASIC_TIM, &TIM_TimeBaseStructure);
		
	// 清除计数器中断标志位
    TIM_ClearFlag(TIME6_BASIC_TIM, TIM_FLAG_Update);
	  
	// 开启计数器中断
    TIM_ITConfig(TIME6_BASIC_TIM,TIM_IT_Update,ENABLE);
		
	// 使能计数器
    TIM_Cmd(TIME6_BASIC_TIM, ENABLE);
}

void  TIME6_BASIC_TIM_IRQHandler (void)
{
	if ( TIM_GetITStatus( TIME6_BASIC_TIM, TIM_IT_Update) != RESET ) 
	{	
		time6++;
		TIM_ClearITPendingBit(TIME6_BASIC_TIM , TIM_FLAG_Update);  		 
	}
	if ( time6 == 1000 ) /* 1000 * 1 ms = 1s 时间到 */
		{
				time6 = 0;     
//			DEBUG_LOG(HXQ_DEBUG_MODULE_TIM_LVL,"time6运行\r\n");
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

	// 设置中断来源
    NVIC_InitStructure.NVIC_IRQChannel = TIME7_BASIC_TIM_IRQ ;	
	// 设置主优先级为 0
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	 
	// 设置抢占优先级为3
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 4;	
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	// 自动重装载寄存器的值，累计TIM_Period+1个频率后产生一个更新或者中断
    TIM_TimeBaseStructure.TIM_Period = TIME7_BASIC_TIM_Period;	

	// 时钟预分频数为
    TIM_TimeBaseStructure.TIM_Prescaler= TIME7_BASIC_TIM_Prescaler;
	
	// 时钟分频因子 ，基本定时器没有，不用管
    //TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;
		
	// 计数器计数模式，基本定时器只能向上计数，没有计数模式的设置
    //TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; 
		
	// 重复计数器的值，基本定时器没有，不用管
	//TIM_TimeBaseStructure.TIM_RepetitionCounter=0;
	
	// 初始化定时器
    TIM_TimeBaseInit(TIME7_BASIC_TIM, &TIM_TimeBaseStructure);
		
	// 清除计数器中断标志位
    TIM_ClearFlag(TIME7_BASIC_TIM, TIM_FLAG_Update);
	  
	// 开启计数器中断
    TIM_ITConfig(TIME7_BASIC_TIM,TIM_IT_Update,ENABLE);
		
	// 使能计数器
    TIM_Cmd(TIME7_BASIC_TIM, ENABLE);	
}


void  TIME7_BASIC_TIM_IRQHandler (void)
{
	if ( TIM_GetITStatus( TIME7_BASIC_TIM, TIM_IT_Update) != RESET ) 
	{	
		time7++;
		TIM_ClearITPendingBit(TIME7_BASIC_TIM , TIM_FLAG_Update);  		 
	}	
	
		if ( time7 == 1000 ) /* 1000 * 1 ms = 1s 时间到 */
		{
				time7 = 0;   
				DEBUG_LOG(HXQ_DEBUG_MODULE_TIM_LVL,"time7运行\r\n");			
			DEBUG_LOG(HXQ_DEBUG_MODULE_ADC_LVL,"voltage:%d\r\n",Get_ADC_Value(ADC_Channel_1,1));
			DEBUG_LOG(HXQ_DEBUG_MODULE_ADC_LVL,"tep:%d\r\n",Get_Temperture());
			DEBUG_LOG(HXQ_DEBUG_MODULE_ADC_LVL,"lsens_value:%d\r\n",Lsens_Get_Val());
			DEBUG_LOG(HXQ_DEBUG_MODULE_TEP_LVL,"temper:%.2f°C\r\n",DS18B20_GetTemperture());
			
			
			//				LED1(0); 
			
		}
		if(time7 == 500)
		{
			
//				LED1(1); 
		}
}

#endif




/* ----------------   PWM信号 周期和占空比的计算--------------- */
// ARR ：自动重装载寄存器的值
// CLK_cnt：计数器的时钟，等于 Fck_int / (psc+1) = 72M/(psc+1)
// PWM 信号的周期 T = ARR * (1/CLK_cnt) = ARR*(PSC+1) / 72M
// 占空比P=CCR/(ARR+1)

void TIM5_Input_Capture(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;

  // 输入捕获通道 GPIO 初始化
	RCC_APB2PeriphClockCmd(TIME5_GENERAL_TIM_CH1_GPIO_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  TIME5_GENERAL_TIM_CH1_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
  GPIO_Init(TIME5_GENERAL_TIM_CH1_PORT, &GPIO_InitStructure);	

      NVIC_InitTypeDef NVIC_InitStructure; 
    // 设置中断组为0
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);		
		// 设置中断来源
    NVIC_InitStructure.NVIC_IRQChannel = TIME5_GENERAL_TIM_IRQ ;	
		// 设置主优先级为 0
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	 
	  // 设置抢占优先级为3
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;	
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

	  // 开启定时器时钟,即内部时钟CK_INT=72M
	RCC_APB1PeriphClockCmd(TIME5_GENERAL_TIM_CLK,ENABLE);

/*--------------------时基结构体初始化-------------------------*/	
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	// 自动重装载寄存器的值，累计TIM_Period+1个频率后产生一个更新或者中断
	TIM_TimeBaseStructure.TIM_Period=TIME5_GENERAL_TIM_PERIOD;	
	// 驱动CNT计数器的时钟 = Fck_int/(psc+1)
	TIM_TimeBaseStructure.TIM_Prescaler= TIME5_GENERAL_TIM_PSC;	
	// 时钟分频因子 ，配置死区时间时需要用到
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;		
	// 计数器计数模式，设置为向上计数
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;		
	// 重复计数器的值，没用到不用管
	TIM_TimeBaseStructure.TIM_RepetitionCounter=0;	
	// 初始化定时器
	TIM_TimeBaseInit(TIME5_GENERAL_TIM, &TIM_TimeBaseStructure);

	/*--------------------输入捕获结构体初始化-------------------*/	
	TIM_ICInitTypeDef TIM_ICInitStructure;
	// 配置输入捕获的通道，需要根据具体的GPIO来配置
	TIM_ICInitStructure.TIM_Channel = TIME5_GENERAL_TIM_CHANNEL_x;
	// 输入捕获信号的极性配置
	TIM_ICInitStructure.TIM_ICPolarity = GENERAL_TIM_STRAT_ICPolarity;
	// 输入通道和捕获通道的映射关系，有直连和非直连两种
	TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;
	// 输入的需要被捕获的信号的分频系数
	TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;
	// 输入的需要被捕获的信号的滤波系数
	TIM_ICInitStructure.TIM_ICFilter = 0;
	// 定时器输入捕获初始化
	TIM_ICInit(TIME5_GENERAL_TIM, &TIM_ICInitStructure);
	
	// 清除更新和捕获中断标志位
  TIM_ClearFlag(TIME5_GENERAL_TIM, TIM_FLAG_Update|TIME5_GENERAL_TIM_IT_CCx);	
  // 开启更新和捕获中断  
	TIM_ITConfig (TIME5_GENERAL_TIM, TIM_IT_Update | TIME5_GENERAL_TIM_IT_CCx, ENABLE );
	
	// 使能计数器
	TIM_Cmd(TIME5_GENERAL_TIM, ENABLE);
}


void TIME5_GENERAL_TIM_INT_FUN(void)
{
	// 当要被捕获的信号的周期大于定时器的最长定时时，定时器就会溢出，产生更新中断
	// 这个时候我们需要把这个最长的定时周期加到捕获信号的时间里面去
	// TIM 计数器的驱动时钟
	uint32_t time;
	uint32_t TIM_PscCLK = 72000000 / (TIME5_GENERAL_TIM_PSC+1);
	if ( TIM_GetITStatus ( TIME5_GENERAL_TIM, TIM_IT_Update) != RESET )               
	{	
		TIM_ICUserValueStructure.Capture_Period ++;		
		TIM_ClearITPendingBit ( TIME5_GENERAL_TIM, TIM_FLAG_Update ); 		
	}

	// 上升沿捕获中断
	if ( TIM_GetITStatus (TIME5_GENERAL_TIM, TIME5_GENERAL_TIM_IT_CCx ) != RESET)
	{
		// 第一次捕获
		if ( TIM_ICUserValueStructure.Capture_StartFlag == 0 )
		{
			// 计数器清0
			TIM_SetCounter ( TIME5_GENERAL_TIM, 0 );
			// 自动重装载寄存器更新标志清0
			TIM_ICUserValueStructure.Capture_Period = 0;
      // 存捕获比较寄存器的值的变量的值清0			
			TIM_ICUserValueStructure.Capture_CcrValue = 0;

			// 当第一次捕获到上升沿之后，就把捕获边沿配置为下降沿
			TIM_OC1PolarityConfig(TIME5_GENERAL_TIM, TIM_ICPolarity_Falling);
      // 开始捕获标准置1			
			TIM_ICUserValueStructure.Capture_StartFlag = 1;			
		}
		// 下降沿捕获中断
		else // 第二次捕获
		{
			// 获取捕获比较寄存器的值，这个值就是捕获到的高电平的时间的值
			TIM_ICUserValueStructure.Capture_CcrValue = 
			TIM_GetCapture1(TIME5_GENERAL_TIM);

			// 当第二次捕获到下降沿之后，就把捕获边沿配置为上升沿，好开启新的一轮捕获
			TIM_OC1PolarityConfig(TIME5_GENERAL_TIM, TIM_ICPolarity_Rising);
      // 开始捕获标志清0		
			TIM_ICUserValueStructure.Capture_StartFlag = 0;
      // 捕获完成标志置1			
			TIM_ICUserValueStructure.Capture_FinishFlag = 1;		
		}

		TIM_ClearITPendingBit (TIME5_GENERAL_TIM,TIME5_GENERAL_TIM_IT_CCx);	    
		if(TIM_ICUserValueStructure.Capture_FinishFlag == 1)
		{
			// 计算高电平时间的计数器的值
			time = TIM_ICUserValueStructure.Capture_Period * (TIME5_GENERAL_TIM_PERIOD+1) + 
			       (TIM_ICUserValueStructure.Capture_CcrValue+1);
			
			// 打印高电平脉宽时间
			printf("Capture_Period:%d Capture_CcrValue:%d\r\n",TIM_ICUserValueStructure.Capture_Period,TIM_ICUserValueStructure.Capture_CcrValue);
			printf ( "\r\n测得高电平脉宽时间：%d.%d s\r\n",time/TIM_PscCLK,time%TIM_PscCLK );
			AT24CXX_WriteOneByte(0,time/TIM_PscCLK);
			printf("读取的数据是：%d\r\n",AT24CXX_ReadOneByte(0));
			TIM_ICUserValueStructure.Capture_FinishFlag = 0;			
		}	
	}		
}

/*********************************************END OF FILE**********************/
