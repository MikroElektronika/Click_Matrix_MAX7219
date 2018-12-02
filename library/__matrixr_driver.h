/*
    __matrixr_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __matrixr_driver.h
@brief    Matrix_R Driver
@mainpage Matrix_R Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   MATRIXR
@brief      Matrix_R Click Driver
@{

| Global Library Prefix | **MATRIXR** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Jul 2018.**      |
| Developer             | **Nenad Filipovic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _MATRIXR_H_
#define _MATRIXR_H_

/** 
 * @macro T_MATRIXR_P
 * @brief Driver Abstract type 
 */
#define T_MATRIXR_P    const uint8_t*

/** @defgroup MATRIXR_COMPILE Compilation Config */              /** @{ */

   #define   __MATRIXR_DRV_SPI__                            /**<     @macro __MATRIXR_DRV_SPI__  @brief SPI driver selector */
//  #define   __MATRIXR_DRV_I2C__                            /**<     @macro __MATRIXR_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __MATRIXR_DRV_UART__                           /**<     @macro __MATRIXR_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup MATRIXR_VAR Variables */                           /** @{ */

                                                                       /** @} */
/** @defgroup ADDRESS REG Register format */                           /** @{ */
extern const uint8_t _MATRIXR_DECODE_MODE_REG;
extern const uint8_t _MATRIXR_INTENSITY_REG;
extern const uint8_t _MATRIXR_SCAN_LIMIT_REG;
extern const uint8_t _MATRIXR_SHUTDOWN_REG;
extern const uint8_t _MATRIXR_DISPLAY_TEST_REG;
                                                                       /** @} */
/** @defgroup DECODE MODE Register format */                           /** @{ */
extern const uint8_t _MATRIXR_NO_DECODE;
extern const uint8_t __MATRIXR_DECODE_DIGIT_0;
extern const uint8_t _MATRIXR_DECODE_DIGIT_3_0;
extern const uint8_t _MATRIXR_DECODE_DIGIT_7;

                                                                     /** @} */
/** @defgroup INTENSITY Register format */                           /** @{ */
const uint8_t _MATRIXR_INTEN_LVL_0;
const uint8_t _MATRIXR_INTEN_LVL_1;
const uint8_t _MATRIXR_INTEN_LVL_2;
const uint8_t _MATRIXR_INTEN_LVL_3;
const uint8_t _MATRIXR_INTEN_LVL_4;
const uint8_t _MATRIXR_INTEN_LVL_5;

                                                                   /** @} */
/** @defgroup DISPLAY Register format */                           /** @{ */
extern const uint8_t _MATRIXR_DISPLAY_DIGIT_0;
extern const uint8_t _MATRIXR_DISPLAY_DIGIT_0_1;
extern const uint8_t _MATRIXR_DISPLAY_DIGIT_0_2;
extern const uint8_t _MATRIXR_DISPLAY_DIGIT_0_3;
extern const uint8_t _MATRIXR_DISPLAY_DIGIT_0_4;
extern const uint8_t _MATRIXR_DISPLAY_DIGIT_0_5;
extern const uint8_t _MATRIXR_DISPLAY_DIGIT_0_6;
extern const uint8_t _MATRIXR_DISPLAY_DIGIT_0_7;

                                                                   /** @} */
/** @defgroup MODE Register format */                              /** @{ */
extern const uint8_t _MATRIXR_SHUTDOWN_MODE;
extern const uint8_t _MATRIXR_NORMAL_OPERATION;

                                                                    /** @} */
/** @defgroup DISPLAY TEST Register format */                       /** @{ */
extern const uint8_t _MATRIXR_DISPLAY_NORMAL_OPERATION;
extern const uint8_t _MATRIXR_DISPLAY_TEST_MODE;


                                                                       /** @} */
/** @defgroup MATRIXR_TYPES Types */                             /** @{ */




                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup MATRIXR_INIT Driver Initialization */              /** @{ */

#ifdef   __MATRIXR_DRV_SPI__
void matrixr_spiDriverInit(T_MATRIXR_P gpioObj, T_MATRIXR_P spiObj);
#endif
#ifdef   __MATRIXR_DRV_I2C__
void matrixr_i2cDriverInit(T_MATRIXR_P gpioObj, T_MATRIXR_P i2cObj, uint8_t slave);
#endif
#ifdef   __MATRIXR_DRV_UART__
void matrixr_uartDriverInit(T_MATRIXR_P gpioObj, T_MATRIXR_P uartObj);
#endif

                                                                       /** @} */
/** @defgroup MATRIXR_FUNC Driver Functions */                   /** @{ */

/**
 * @brief This function write data in register
 *
 * @param[in] registerAdress    register
 * @param[in] dataValue         data
 *
 */
void matrixr_writeDataReg( uint8_t registerAdress, uint8_t dataValue );

/**
 * @brief  Display left and right character on matrix display
 *
 * @param[in] characterLeft    Left character for display
 * @param[in] characterRight   Right character for display
 *
 */
void matrixr_displayCharacter( uint8_t characterLeft, uint8_t characterRight );



                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_Matrix_R_STM.c
    @example Click_Matrix_R_TIVA.c
    @example Click_Matrix_R_CEC.c
    @example Click_Matrix_R_KINETIS.c
    @example Click_Matrix_R_MSP.c
    @example Click_Matrix_R_PIC.c
    @example Click_Matrix_R_PIC32.c
    @example Click_Matrix_R_DSPIC.c
    @example Click_Matrix_R_AVR.c
    @example Click_Matrix_R_FT90x.c
    @example Click_Matrix_R_STM.mbas
    @example Click_Matrix_R_TIVA.mbas
    @example Click_Matrix_R_CEC.mbas
    @example Click_Matrix_R_KINETIS.mbas
    @example Click_Matrix_R_MSP.mbas
    @example Click_Matrix_R_PIC.mbas
    @example Click_Matrix_R_PIC32.mbas
    @example Click_Matrix_R_DSPIC.mbas
    @example Click_Matrix_R_AVR.mbas
    @example Click_Matrix_R_FT90x.mbas
    @example Click_Matrix_R_STM.mpas
    @example Click_Matrix_R_TIVA.mpas
    @example Click_Matrix_R_CEC.mpas
    @example Click_Matrix_R_KINETIS.mpas
    @example Click_Matrix_R_MSP.mpas
    @example Click_Matrix_R_PIC.mpas
    @example Click_Matrix_R_PIC32.mpas
    @example Click_Matrix_R_DSPIC.mpas
    @example Click_Matrix_R_AVR.mpas
    @example Click_Matrix_R_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __matrixr_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */