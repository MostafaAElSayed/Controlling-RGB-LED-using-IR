/****************************************************/
/*  Author      :   Mostafa Ahmed El-Sayed          */
/*  File Name   :   RCC_interface.h                 */
/*  Version     :   V01                             */
/*  Date        :   03/02/2023                      */
/****************************************************/
#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

#define RCC_AHB     0
#define RCC_APB1    1
#define RCC_APB2    2


void RCC_voidInitSysClock(void);
void RCC_voidEnableClock(u8 Copy_u8BusId,u8 Copy_u8PerId);
void RCC_voidDisableClock(u8 Copy_u8BusId,u8 Copy_u8PerId);
u8   RCC_u8GetSystemClockStatus(void);


#endif /** RCC_INTERFACE_H_ */