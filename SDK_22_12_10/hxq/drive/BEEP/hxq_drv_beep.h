#ifndef _HXQ_DRV_BEEP_H
#define _HXQ_DRV_BEEP_H

#include "system.h"

/*  ������ʱ�Ӷ˿ڡ����Ŷ��� */
#define BEEP_PORT 				GPIOB   
#define BEEP_PIN 				GPIO_PIN_8
#define BEEP_PORT_RCC_ENABLE	__HAL_RCC_GPIOB_CLK_ENABLE()

#define BEEP PBout(8)

void BEEP_Init(void);


#endif  /*! _HXQ_DRV_BEEP_H */
