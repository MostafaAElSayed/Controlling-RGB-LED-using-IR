/*
 * main.c
 *
 *  Created on: 06/02/2023
 *      Author: Mostafa Ahmed
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "EXTI_interface.h"
#include "NVIC_interface.h"
#include "STK_interface.h"


volatile u8  u8_StartFlag 	 = 0;
volatile u32 u32FramData[50] = {0};
volatile u8  u8EdgeCounter 	 = 0;
volatile u8  u8Data  		 = {0};
volatile u8  u8DataRev  	 = {0};

void voidPlay()
{
	switch(u8Data)
	{
	case 21: GPIO_VoidSetPinValue(GPIOA,1,GPIO_HIGH); break;
	case 70: GPIO_VoidSetPinValue(GPIOA,2,GPIO_HIGH); break;
	case 71: GPIO_VoidSetPinValue(GPIOA,3,GPIO_HIGH); break;

	case 68: GPIO_VoidSetPinValue(GPIOA,1,GPIO_HIGH);
			 GPIO_VoidSetPinValue(GPIOA,2,GPIO_HIGH); break;

	case 64: GPIO_VoidSetPinValue(GPIOA,1,GPIO_HIGH);
		 	 GPIO_VoidSetPinValue(GPIOA,3,GPIO_HIGH); break;

	case 67: GPIO_VoidSetPinValue(GPIOA,3,GPIO_HIGH);
			 GPIO_VoidSetPinValue(GPIOA,2,GPIO_HIGH); break;

	case 7:  GPIO_VoidSetPinValue(GPIOA,1,GPIO_HIGH);
			 GPIO_VoidSetPinValue(GPIOA,2,GPIO_HIGH);
			 GPIO_VoidSetPinValue(GPIOA,3,GPIO_HIGH); break;
	case 69: GPIO_VoidSetPinValue(GPIOA,1,GPIO_LOW);
			 GPIO_VoidSetPinValue(GPIOA,2,GPIO_LOW);
			 GPIO_VoidSetPinValue(GPIOA,3,GPIO_LOW);  break;
	default: break;
	}
}
void voidTakeAction(void)
{
	u8 i;
	u8Data =0;

	if((u32FramData[0] >= 10000) && (u32FramData[0] <= 14000))				// Check for Start Bit 13500ms
	{
		for(i=0; i<8;i++)
		{
			if((u32FramData[17+i] >= 2000) && (u32FramData[17+i] < 2300))	// Read Data fram from bit[17:24]
			{
				SET_BIT(u8Data,i);
			}
			else
			{
				CLR_BIT(u8Data,i);
			}
		}

		for(i=0; i<8;i++)
			{
				if((u32FramData[25+i] >= 2000) && (u32FramData[25+i] < 2300))	// Read DataRev fram from bit[25:32]
				{
					SET_BIT(u8DataRev,i);
				}
				else
				{
					CLR_BIT(u8DataRev,i);
				}
			}
	}
	else
	{
		//
	}
	u8DataRev ^= 0xFF;

	voidPlay();

	u8_StartFlag 	 = 0;
	u32FramData[0]   = 0;
	u8EdgeCounter 	 = 0;
}

void voidGetFrame(void)
{
	if(u8_StartFlag == 0)
	{
		MSTK_voidSetIntervalSingle(1000000,voidTakeAction);
		u8_StartFlag = 1;
	}
	else
	{
		u32FramData[u8EdgeCounter]= MSTK_u32GetElapsedTime();
		MSTK_voidSetIntervalSingle(1000000,voidTakeAction);
		u8EdgeCounter++ ;
	}
}

int main(void)
{
	/* RCC Init */
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2); //Enable GPIOA

	/* GPIO Init */
	GPIO_VoidSetPinDirection(GPIOA,0,INPUT_FLOATING);

	GPIO_VoidSetPinDirection(GPIOA,1,OUTPUT_SPEED_2MHZ_PP);
	GPIO_VoidSetPinDirection(GPIOA,2,OUTPUT_SPEED_2MHZ_PP);
	GPIO_VoidSetPinDirection(GPIOA,3,OUTPUT_SPEED_2MHZ_PP);

	/* EXTI init */
	MEXTI_voidSetCallBack(voidGetFrame);
	MEXTI_voidInit(LINE0,FALLING_EDGE);
	MEXTI_voidEnableEXTI(LINE0);



	/* NVIC Init */
	MNVIC_voidInit();
	MNVIC_voidEnableInterrupt(EXTI0); //Enable EXTI0

	/* STK Init */
	MSTK_voidInit(); // Enable STK AHB/8 = 1 Mhz


	while(1)
	{

	}
	return 0;
}
