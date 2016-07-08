/******************************************************************************
* Title                 :   MATRIX
* Filename              :   matrix.h
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
 * @file matrix.h
 * @brief <h3> Matrix Click Functions </h3>
 *
 * @par
 * This library can be used with Matrix R and Matrix G click boards.
 */

#ifndef MATRIX_H
#define MATRIX_H

/******************************************************************************
* Includes
*******************************************************************************/

#include <string.h>
#include <stdbool.h>
#include "matrix_hw.h"

/******************************************************************************
* Preprocessor Constants
*******************************************************************************/

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
 * @enum MATRIX_SPEED_t
 * @brief Matrix Speed
 *
 * @par
 * Enum used for animation. Actualy the delay between steps. Delay time depend
 * on animation type.
 */
typedef enum {

    MATRIX_SLOW,
    MATRIX_MED_SLOW,
    MATRIX_MED,
    MATRIX_MED_FAST,
    MATRIX_FAST

}MATRIX_SPEED_t;

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
 * @brief Matrix Library Intialization
 *
 * @par
 * Must be executed before any other function.
 */
void matrix_init( void );

/**
 * @brief Power Control
 *
 * @par
 * Turns on or off the matricies.
 *
 * @param[in] state ( true - ON / false - OFF )
 */
void matrix_power( bool state );

/**
 * @brief Brightness Control
 *
 * @par
 * Brightness control for both matricies
 *
 * @param[in] value ( 0 ~ 15 )
 */
void matrix_brightness( uint8_t value );

/**
 * @brief Blink effect
 *
 * @par
 * Bilnk letters on displayed on matricies.
 *
 * @param[in] cycles - number of repetitions
 * @param[in] speed - blink speed
 */
void matrix_blink( uint16_t cycles,
                   MATRIX_SPEED_t speed );

/**
 * @brief Smooth blink effect
 *
 * @par
 * Smooth blinking of letters.
 *
 * @param[in] cycles - number of repetitions
 * @param[in] speed - blink speed
 */
void matrix_blink_smooth( uint16_t cycles,
                          MATRIX_SPEED_t speed );

/**
 * @brief Display Character ( Left )
 *
 * @par
 * Displays provided character on the left matrix.
 *
 * @param[in] ch - character
 */
void matrix_char_left( char ch );

/**
 * @brief Display Character ( Right )
 *
 * @par
 * Displays provided character on the right matrix.
 *
 * @param[in] ch - character
 */
void matrix_char_right( char ch );

/**
 * @brief Blink Text
 *
 * @par
 * Blinks provided string, two by two letters in each repetition.
 *
 * @param[in] text
 * @param[in] speed
 */
void matrix_text_blink( char *text,
                        MATRIX_SPEED_t speed );

/**
 * @brief Scroll Text
 *
 * @par
 * Scrolls provided text until the end of the string.
 *
 * @param[in] text
 * @param[in] speed
 */
void matrix_text_scroll( char *text,
                         MATRIX_SPEED_t speed );

#ifdef __cplusplus
} // extern "C"
#endif

#endif // MATRIX_R_H

/***************************** End of File ************************************/
