/****************************************************/
/*  Author      :   Mostafa Ahmed El-Sayed          */
/*  File Name   :   RCC_config.h                    */
/*  Version     :   V01                             */
/*  Date        :   03/02/2023                      */
/****************************************************/
#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_

/*  RCC_CLOCK_TYPE
    Options:        RCC_HSE_CRYSTAL
                    RCC_HSE_RC
                    RCC_HSI          "Default"
                    RCC_PLL
                                */
#define RCC_CLOCK_TYPE  RCC_HSE_CRYSTAL

/****************************************************/
/*                  PLL Options                     */
/****************************************************/
        #if RCC_CLOCK_TYPE == RCC_PLL
        /*  RCC_PLL_INPUT
            Options:        RCC_PLL_IN_HSI_DIV_2    "Default"
                            RCC_PLL_IN_HSE_DIV_2
                            RCC_PLL_IN_HSE
                                         */
        #define RCC_PLL_INPUT   RCC_PLL_IN_HSI_DIV_2

        /*  RCC_PLL_MUL_VAL
            Options:    ( 2 : 16 )
                        PLL/2   "Default"
                                        */
        #define RCC_PLL_MUL_VAL     2

        #endif
/****************************************************/

#endif /** RCC_CONFIG_H_ */