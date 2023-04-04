#ifndef __USER_PROJECT_CONFIG_H
#define	__USER_PROJECT_CONFIG_H


#include "stm32f10x.h"


/******** �������LED *********/
//LED0
#ifndef LED0_FUNCTION_SUPPORT
#define LED0_FUNCTION_SUPPORT 1
#define LED1_GPIO_PORT    	GPIOE			              /* GPIO�˿� */
#define LED1_GPIO_CLK 	    RCC_APB2Periph_GPIOE		/* GPIO�˿�ʱ�� */
#define LED1_GPIO_PIN				GPIO_Pin_5			        /* ���ӵ�SCLʱ���ߵ�GPIO */
#else
#define LED0_FUNCTION_SUPPORT 0
#endif

//LED1
#ifndef LED1_FUNCTION_SUPPROT
#define LED1_FUNCTION_SUPPROT 1
#define LED0_GPIO_PORT    	GPIOB			              /* GPIO�˿� */
#define LED0_GPIO_CLK 	    RCC_APB2Periph_GPIOB		/* GPIO�˿�ʱ�� */
#define LED0_GPIO_PIN				GPIO_Pin_5			        /* ���ӵ�SCLʱ���ߵ�GPIO */
#else
#define LED1_FUNCTION_SUPPROT 0
#endif
/******** �������LED *********/

#endif /* __USER_PROJECT_CONFIG_H */
