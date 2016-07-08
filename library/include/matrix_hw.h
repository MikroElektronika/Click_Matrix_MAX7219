/******************************************************************************
* Title                 :   MATRIX HW
* Filename              :   matrix_hw.h
* Author                :   MSV
* Origin Date           :   28/01/2016
* Notes                 :   None
*******************************************************************************/
/**************************CHANGE LIST ****************************************
*
*    Date    Software Version    Initials   Description
*  28/01/16    XXXXXXXXXXX         MSV      Interface Created.
*
*******************************************************************************/

/**
 * @file matrix_hw.h
 * @brief <h3> Hardware Layer </h3>
 *
 * @par
 * Low level functions for
 * <a href="http://www.mikroe.com">MikroElektronika's</a> matrix click
 * board.
 */

/**
 * @page LIB_INFO Library Info
 * @date 28 Jan 2016
 * @author Milos Vidojevic
 * @copyright GNU Public License
 * @version 1.0.0 - Initial testing and verification
 */

/**
 * @page TEST_CFG Test Configurations
 * <h3> Test configuration 1 : </h3>
 * @par
 * <ul>
 * <li><b>MCU</b> :             STM32F107VC</li>
 * <li><b>Dev. Board</b> :      EasyMx Pro v7</li>
 * <li><b>Oscillator</b> :      72 Mhz internal</li>
 * <li><b>Ext. Modules</b> :    Matrix R Click</li>
 * <li><b>SW</b> :              MikroC PRO for ARM 4.7.1</li>
 * </ul>
 *
 * <h3> Test configuration 2 : </h3>
 * @par
 * <ul>
 * <li><b>MCU</b> :             PIC32MX795F512L</li>
 * <li><b>Dev. Board</b> :      EasyPic Fusion v7</li>
 * <li><b>Oscillator</b> :      80 Mhz internal</li>
 * <li><b>Ext. Modules</b> :    Matrix R Click</li>
 * <li><b>SW</b> :              MikroC PRO for PIC 6.6.2</li>
 * </ul>
 *
 * <h3> Test configuration 3 : </h3>
 * @par
 * <ul>
 * <li><b>MCU</b> :             FT900Q</li>
 * <li><b>Dev. Board</b> :      EasyFT90x v7</li>
 * <li><b>Oscillator</b> :      100 Mhz internal</li>
 * <li><b>Ext. Modules</b> :    Matrix R Click</li>
 * <li><b>SW</b> :              MikroC PRO for FT90x 1.2.1</li>
 * </ul>
 */

/**
 * @mainpage
 *
 * <h2> Help documentation </h2>
 */

#ifndef MATRIX_HW_H
#define MATRIX_HW_H

/******************************************************************************
* Includes
*******************************************************************************/

#include <stdint.h>

/******************************************************************************
* Preprocessor Constants
*******************************************************************************/

#define MATRIX_DC                       2
#define MATRIX_X                        8
#define MATRIX_Y                        8
#define MATRIX_BRIGHT_MAX               15

/******************************************************************************
* Configuration Constants
*******************************************************************************/

/******************************************************************************
* Macros
*******************************************************************************/

/******************************************************************************
* Typedefs
*******************************************************************************/

/**
 * @enum MATRIX_CMD_t
 * @brief Matrix R Commands
 */
typedef enum {

    MATRIX_DECODE_MODE              = 0xF9,
    MATRIX_INTENSITY                = 0xFA,
    MATRIX_SCAN_LIMIT               = 0xFB,
    MATRIX_SHUTDOWN                 = 0xFC,
    MATRIX_DISPLAY_TEST             = 0xFF

}MATRIX_CMD_t;

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
 * @brief Matrix HW Initialization
 *
 * @par
 * Initializes the HW and HAL layer. This function must be executed first.
 */
void matrix_hw_init( void );

/**
 * @brief Matrix Command
 *
 * @par
 * Executes command on both matricies
 *
 * @param[in] cmd - cmd
 * @param[in] arg - argument
 */
void matrix_hw_cmd( MATRIX_CMD_t cmd,
                    uint8_t arg );

/**
 * @brief Matrix Display
 *
 * @par
 * Displays the content of frame buffer.
 */
void matrix_hw_display( void );

/**
 * @brief Matrix R Clean
 *
 * @par
 * Cleans the content of the frame buffer. Starts position is set by offset and
 * number of bytes that should be cleared is provided by count parameter.
 *
 * @note
 * If the 0 provided as count parameter the frame buffer contetn will be cleared
 * from offset to the end of buffer.
 *
 * @param[in] offset
 * @param[in] count
 */
void matrix_hw_clean( uint8_t offset,
                      uint8_t count );

/**
 * @brief Matrix R Set
 *
 * @par
 * Updates the content of the frame buffer with provided image. Starts position
 * is set by offset and number of bytes that should be cleared is provided by
 * count parameter.
 *
 * @note
 * If the 0 provided as count parameter the frame buffer contetn will be cleared
 * from offset to the end of buffer.
 *
 * @param[in] offset
 * @param[in] count
 * @param[in] image
 */
void matrix_hw_set( uint8_t offset,
                    uint8_t count,
                    uint8_t *image );

/**
 * @brief Matrix R Get
 *
 * @par
 * Returns the content of the frame buffer. Starts position is set by offset
 * and number of bytes that should be cleared is provided by count parameter.
 *
 * @note
 * If the 0 provided as count parameter the frame buffer contetn will be cleared
 * from offset to the end of buffer.
 *
 * @param[in] offset
 * @param[in] count
 * @param[out] buffer
 */
void matrix_hw_get( uint8_t offset,
                    uint8_t count,
                    uint8_t *buffer );

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* matrix_r_HW_H */

/***************************** End of File ************************************/
