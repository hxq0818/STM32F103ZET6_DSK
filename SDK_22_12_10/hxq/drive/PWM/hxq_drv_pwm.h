#ifndef _pwm_H
#define _pwm_H

#include "system.h"

void TIM3_CH2_PWM_Init(u16 per,u16 psc);
void TIM3_SetCompare2(u32 compare);

#endif
