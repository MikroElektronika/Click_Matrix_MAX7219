/****************************************************************************
* Title                 :   MATRIX HAL
* Filename              :   matrix_hal.h
* Author                :   MSV
* Origin Date           :   01/05/2016
* Notes                 :   None
*****************************************************************************/
/**************************CHANGE LIST **************************************
*
*    Date    Software Version    Initials       Description
*  01/05/16       1.0.0             MSV        Module Created.
*
*****************************************************************************/

/**
 * @file matrix_hal.h
 * @brief <h2> HAL layer for Matrix Click </h2>
 *
 * @par
 * HAL layer for Matrix click board.
 */

#ifndef MATRIX_HAL_H_
#define MATRIX_HAL_H_

/******************************************************************************
* Includes
*******************************************************************************/

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/******************************************************************************
* Preprocessor Constants
*******************************************************************************/

#define DUMMY_BYTE                                                  0x00

/******************************************************************************
* Configuration Constants
*******************************************************************************/

/******************************************************************************
* Macros
*******************************************************************************/
        
/******************************************************************************
* Typedefs
*******************************************************************************/

/******************************************************************************
* Variables
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @brief <h3> HAL Initialization </h3>
 *
 * Hal layer initialization. Must be called before any other function.
 */
void matrix_hal_init( void );

/**
 * @brief <h3> HAL Write Left </h3>
 *
 * @par
 * Writes data through SPI bus on left matrix
 *
 * @param[in] row_no
 * @param[in] row_data
 */
void matrix_hal_write_left( uint8_t row_no,
                            uint8_t row_data );

/**
 * @brief <h3> HAL Write Right </h3>
 *
 * @par
 * Writes data through SPI bus on right matrix
 *
 * @param[in] row_no
 * @param[in] row_data
 */
void matrix_hal_write_right( uint8_t row_no,
                             uint8_t row_data );

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* MATRIX_R_HAL_H_ */

/*** End of File **************************************************************/
