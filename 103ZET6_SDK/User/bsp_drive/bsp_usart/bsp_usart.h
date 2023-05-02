/*
 * @brief: usart´®¿ÚÓ¦ÓÃ
 * @version: V1.0
 * @Author: xiaoqing.huang
 * @Date: 2023-04-11 20:26:09
 * @LastEditors: LAPTOP-4DIHEQ1Q
 * @LastEditTime: 2023-04-21 11:11:17
 */

#ifndef __USART_H
#define	__USART_H


#include "stm32f10x.h"
#include <stdio.h>


#include "user_project_config.h"


void USART_Config(void);
void Usart_SendByte( USART_TypeDef * pUSARTx, uint8_t ch);
void Usart_SendString( USART_TypeDef * pUSARTx, char *str);
void Usart_SendHalfWord( USART_TypeDef * pUSARTx, uint16_t ch);

#endif /* __USART_H */
