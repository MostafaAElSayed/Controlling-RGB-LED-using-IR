/****************************************************/
/*  Author      :   Mostafa Ahmed El-Sayed          */
/*  File Name   :   GPIO_private.h                  */
/*  Version     :   V01                             */
/*  Date        :   06/02/2023                      */
/****************************************************/
#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

/*  BASE ADDRESSES FOR PORTS
    GPOA A      0x4001 0800
    GPIO B      0x4001 0C00
    GPIO C      0x4001 1000
*/
#define GPOIA_BASE_ADDRESS      0x40010800
#define GPOIB_BASE_ADDRESS      0x40010C00
#define GPOIC_BASE_ADDRESS      0x40011000


    /*  REGISTER ADDRESSES FOR PORT A   */
#define GPIOA_CRL      *((u32*)(GPOIA_BASE_ADDRESS + 0x00))
#define GPIOA_CRH      *((u32*)(GPOIA_BASE_ADDRESS + 0x04))
#define GPIOA_IDR      *((u32*)(GPOIA_BASE_ADDRESS + 0x08))
#define GPIOA_ODR      *((u32*)(GPOIA_BASE_ADDRESS + 0x0C))
#define GPIOA_BSR      *((u32*)(GPOIA_BASE_ADDRESS + 0x10))
#define GPIOA_BRR      *((u32*)(GPOIA_BASE_ADDRESS + 0x14))
#define GPIOA_LCK      *((u32*)(GPOIA_BASE_ADDRESS + 0x18))


    /*  REGISTER ADDRESSES FOR PORT B   */
#define GPIOB_CRL      *((u32*)(GPOIB_BASE_ADDRESS + 0x00))
#define GPIOB_CRH      *((u32*)(GPOIB_BASE_ADDRESS + 0x04))
#define GPIOB_IDR      *((u32*)(GPOIB_BASE_ADDRESS + 0x08))
#define GPIOB_ODR      *((u32*)(GPOIB_BASE_ADDRESS + 0x0C))
#define GPIOB_BSR      *((u32*)(GPOIB_BASE_ADDRESS + 0x10))
#define GPIOB_BRR      *((u32*)(GPOIB_BASE_ADDRESS + 0x14))
#define GPIOB_LCK      *((u32*)(GPOIB_BASE_ADDRESS + 0x18))


    /*  REGISTER ADDRESSES FOR PORT C   */
#define GPIOC_CRL      *((u32*)(GPOIC_BASE_ADDRESS + 0x00))
#define GPIOC_CRH      *((u32*)(GPOIC_BASE_ADDRESS + 0x04))
#define GPIOC_IDR      *((u32*)(GPOIC_BASE_ADDRESS + 0x08))
#define GPIOC_ODR      *((u32*)(GPOIC_BASE_ADDRESS + 0x0C))
#define GPIOC_BSR      *((u32*)(GPOIC_BASE_ADDRESS + 0x10))
#define GPIOC_BRR      *((u32*)(GPOIC_BASE_ADDRESS + 0x14))
#define GPIOC_LCK      *((u32*)(GPOIC_BASE_ADDRESS + 0x18))

#endif /*   GPIO_PRIVATE_H_ */