#include "bsp_adc.h"
#include "bsp_SysTick.h"


__IO uint16_t ADC_ConvertedValue;

/*******************************************************************************
* 函 数 名         : ADCx_Init
* 函数功能		   : ADC初始化	
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void ADC2_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure; //定义结构体变量	
	ADC_InitTypeDef       ADC_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_ADC2,ENABLE);
	
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);//设置ADC分频因子6 72M/6=12,ADC最大时间不能超过14M
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_1;//ADC
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AIN;	//模拟输入
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;//非扫描模式	
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;//关闭连续转换
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;//禁止触发检测，使用软件触发
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;//右对齐	
	ADC_InitStructure.ADC_NbrOfChannel = 1;//1个转换在规则序列中 也就是只转换规则序列1 
	ADC_Init(ADC2, &ADC_InitStructure);//ADC初始化
	
	ADC_Cmd(ADC2, ENABLE);//开启AD转换器
	
	ADC_ResetCalibration(ADC2);//重置指定的ADC的校准寄存器
	while(ADC_GetResetCalibrationStatus(ADC2));//获取ADC重置校准寄存器的状态
	
	ADC_StartCalibration(ADC2);//开始指定ADC的校准状态
	while(ADC_GetCalibrationStatus(ADC2));//获取指定ADC的校准程序

	ADC_SoftwareStartConvCmd(ADC2, ENABLE);//使能或者失能指定的ADC的软件转换启动功能
}

/*******************************************************************************
* 函 数 名         : Get_ADC_Value
* 函数功能		   : 获取通道ch的转换值，取times次,然后平均 	
* 输    入         : ch:通道编号
					 times:获取次数
* 输    出         : 通道ch的times次转换结果平均值
*******************************************************************************/
u16 Get_ADC_Value(u8 ch,u8 times)
{
	u32 temp_val=0;
	u8 t;
	//设置指定ADC的规则组通道，一个序列，采样时间
	ADC_RegularChannelConfig(ADC2, ch, 1, ADC_SampleTime_239Cycles5);	//ADC1,ADC通道,239.5个周期,提高采样时间可以提高精确度			    
	
	for(t=0;t<times;t++)
	{
		ADC_SoftwareStartConvCmd(ADC2, ENABLE);//使能指定的ADC1的软件转换启动功能	
		while(!ADC_GetFlagStatus(ADC2, ADC_FLAG_EOC ));//等待转换结束
		temp_val+=ADC_GetConversionValue(ADC2);
//		Delay_ms(5);
	}
	return temp_val/times;
} 
uint16_t Get_ADC_Value_LVL()
{
		uint16_t voltage = 0;
		voltage=Get_ADC_Value(ADC_Channel_1,20);
		return voltage;
}

/*******************************************************************************
* 函 数 名         : ADC_Temp_Init
* 函数功能		   : ADC_Temp初始化函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void ADC_Temp_Init(void)
{	
	ADC_InitTypeDef       ADC_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1,ENABLE);
	
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);   //分频因子6时钟为72M/6=12MHz
	
	ADC_TempSensorVrefintCmd(ENABLE);//打开ADC内部温度传感器
	
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;	//ADC工作模式:ADC1和ADC2工作在独立模式
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;//非扫描模式	
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;//关闭连续转换
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;//禁止触发检测，使用软件触发
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;//右对齐	
	ADC_InitStructure.ADC_NbrOfChannel = 1;	//1个转换在规则序列中 也就是只转换规则序列1 
	ADC_Init(ADC1, &ADC_InitStructure);//ADC初始化
	
	ADC_Cmd(ADC1, ENABLE);//开启AD转换器
	
	ADC_ResetCalibration(ADC1);//重置指定的ADC的校准寄存器
	while(ADC_GetResetCalibrationStatus(ADC1));//获取ADC重置校准寄存器的状态
	
	ADC_StartCalibration(ADC1);//开始指定ADC的校准状态
	while(ADC_GetCalibrationStatus(ADC1));//获取指定ADC的校准程序

	ADC_SoftwareStartConvCmd(ADC1, ENABLE);//使能或者失能指定的ADC的软件转换启动功能
}
/*******************************************************************************
* 函 数 名         : Get_ADC_Temp_Value
* 函数功能		   : 获取通道ch的转换值，取times次,然后平均 	
* 输    入         : ch:通道编号
					 times:获取次数
* 输    出         : 通道ch的times次转换结果平均值
*******************************************************************************/
u16 Get_ADC_Temp_Value(u8 ch,u8 times)
{
	u32 temp_val=0;
	u8 t;
	//设置指定ADC的规则组通道，一个序列，采样时间
	ADC_RegularChannelConfig(ADC1, ch, 1, ADC_SampleTime_239Cycles5);	//ADC1,ADC通道,239.5个周期,提高采样时间可以提高精确度
	for(t=0;t<times;t++)
	{
		ADC_SoftwareStartConvCmd(ADC1, ENABLE);//使能指定的ADC1的软件转换启动功能	
		while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC ));//等待转换结束
		temp_val+=ADC_GetConversionValue(ADC1);
//		delay_ms(5);
	}
	return temp_val/times;
} 

/*******************************************************************************
* 函 数 名         : Get_Temperture
* 函数功能		   : 获取温度值 	
* 输    入         : 无
* 输    出         : 温度值(扩大了100倍,单位:℃)
*******************************************************************************/
int Get_Temperture(void)
{
	u32 adc_value;
	int temp;
 	double temperture;
	adc_value=Get_ADC_Temp_Value(ADC_Channel_16,1);	//读取通道16内部温度传感器通道,10次取平均
	temperture=(float)adc_value*(3.3/4096);		//电压值
	temperture=(1.43-temperture)/0.0043+25; //转换为温度值 
	temp=temperture*100;					//扩大100倍.
	return temp;
}
//初始化光敏传感器
void Lsens_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	ADC_InitTypeDef ADC_InitStructure; 
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF,ENABLE);//使能PORTF时钟	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC3	, ENABLE );	  //使能ADC3通道时钟
	RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC3,ENABLE);//ADC复位	
	RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC3,DISABLE);//复位结束
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;//PF8 anolog输入
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;		//模拟输入引脚
	GPIO_Init(GPIOF, &GPIO_InitStructure);	
	
	ADC_DeInit(ADC3);  //复位ADC3,将外设 ADC3的全部寄存器重设为缺省值

	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;	//ADC工作模式: 独立模式
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;	//模数转换工作在单通道模式
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;	//模数转换工作在单次转换模式
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;	//转换由软件而不是外部触发启动
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;	//ADC数据右对齐
	ADC_InitStructure.ADC_NbrOfChannel = 1;	//顺序进行规则转换的ADC通道的数目
	ADC_Init(ADC3, &ADC_InitStructure);	//根据ADC_InitStruct中指定的参数初始化外设ADCx的寄存器  

	ADC_Cmd(ADC3, ENABLE);	//使能指定的ADC3
	
	ADC_ResetCalibration(ADC3);	//使能复位校准  
	 
	while(ADC_GetResetCalibrationStatus(ADC3));	//等待复位校准结束
	
	ADC_StartCalibration(ADC3);	 //开启AD校准
 
	while(ADC_GetCalibrationStatus(ADC3));	 //等待校准结束
}

//获得ADC3某个通道的值
//ch:通道值 0~16
//返回值:转换结果
u16 Get_ADC3(u8 ch)   
{
	//设置指定ADC的规则组通道，一个序列，采样时间
	ADC_RegularChannelConfig(ADC3, ch, 1, ADC_SampleTime_239Cycles5 );	//ADC3,ADC通道,采样时间为239.5周期	  			    
  
	ADC_SoftwareStartConvCmd(ADC3, ENABLE);		//使能指定的ADC3的软件转换启动功能	
	 
	while(!ADC_GetFlagStatus(ADC3, ADC_FLAG_EOC ));//等待转换结束

	return ADC_GetConversionValue(ADC3);	//返回最近一次ADC3规则组的转换结果
} 

#define LSENS_READ_TIMES	10	//定义光敏传感器读取次数,读这么多次,然后取平均值

//读取Light Sens的值
//0~100:0,最暗;100,最亮 
u8 Lsens_Get_Val(void)
{
	u32 temp_val=0;
	u8 t;
	for(t=0;t<LSENS_READ_TIMES;t++)
	{
		temp_val+=Get_ADC3(ADC_Channel_6);	//读取ADC值
//		Delay_ms(5);
	}
	temp_val/=LSENS_READ_TIMES;//得到平均值 
	if(temp_val>4000)temp_val=4000;
	return (u8)(100-(temp_val/40));
}
