/****************************************************************************
* Title                 :   MATRIX R CLICK
* Filename              :   matrix_r_hw.c
* Author                :   MSV
* Origin Date           :   30/01/2016
* Notes                 :   Hardware layer
*****************************************************************************/
/**************************CHANGE LIST **************************************
*
*    Date    Software Version    Initials   Description
*  30/01/16     .1                  MSV     Interface Created.
*
*****************************************************************************/
/**
 * @file matrix_r_hw.c
 * @brief <h3> Hardware Layer </h3>
 */
/******************************************************************************
* Includes
*******************************************************************************/
#include "matrix_hw.h"
#include "matrix_hal.h"
/******************************************************************************
* Module Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Module Preprocessor Macros
*******************************************************************************/

/******************************************************************************
* Module Typedefs
*******************************************************************************/

/******************************************************************************
* Module Variable Definitions
*******************************************************************************/
static uint8_t frame_buffer[ MATRIX_DC * MATRIX_Y ];
/******************************************************************************
* Function Prototypes
*******************************************************************************/

/******************************************************************************
* Private Function Definitions
*******************************************************************************/

/******************************************************************************
* Public Function Definitions
*******************************************************************************/
void matrix_hw_init()
{
    matrix_hal_init();

    matrix_hw_cmd( MATRIX_DECODE_MODE, 0 );
    matrix_hw_cmd( MATRIX_SCAN_LIMIT, 7 );
    matrix_hw_cmd( MATRIX_DISPLAY_TEST, 0 );
    matrix_hw_cmd( MATRIX_INTENSITY, MATRIX_BRIGHT_MAX );
    matrix_hw_cmd( MATRIX_SHUTDOWN, 1 );

    matrix_hw_clean( 0, 0 );
}

void matrix_hw_cmd( MATRIX_CMD_t cmd,
                      uint8_t arg )
{
    matrix_hal_write_left( cmd, arg );
    matrix_hal_write_right( cmd, arg );
}

void matrix_hw_display( void )
{
    uint8_t i;

    for( i = 0; i < MATRIX_Y; i++ )
        matrix_hal_write_left( i, frame_buffer[ i ] );

    for( i = 0; i < MATRIX_Y; i++ )
        matrix_hal_write_right( i, frame_buffer[ MATRIX_Y + i ] );
}

void matrix_hw_clean( uint8_t offset,
                        uint8_t count )
{
    uint8_t i;

    if( ( offset + count ) > MATRIX_DC * MATRIX_Y )
        return;

    if( !count )
        for( i = offset; i < ( MATRIX_DC * MATRIX_Y ); i++ )
            frame_buffer[ i ] = 0;
    else
        for( i = offset; i < ( offset + count ); i++ )
            frame_buffer[ i ] = 0;
}

void matrix_hw_set( uint8_t offset,
                      uint8_t count,
                      uint8_t *image )
{
    uint8_t i;
    uint8_t *img = image;

    if( ( offset + count ) > MATRIX_DC * MATRIX_Y )
        return;

    if( !count )
        for( i = offset; i < ( MATRIX_DC * MATRIX_Y ); i++ )
            frame_buffer[ i ] = *img++;
    else
        for( i = offset; i < ( offset + count ); i++ )
            frame_buffer[ i ] = *img++;
}

void matrix_hw_get( uint8_t offset,
                      uint8_t count,
                      uint8_t *buffer )
{
    uint8_t i;
    uint8_t *img = buffer;

    if( ( offset + count ) > MATRIX_DC * MATRIX_Y )
        return;

    if( !count )
        for( i = offset; i < ( MATRIX_DC * MATRIX_Y ); i++ )
            *img++ = frame_buffer[ i ];
    else
        for( i = offset; i < ( offset + count ); i++ )
            *img++ = frame_buffer[ i ];
}

/*************** END OF FUNCTIONS *********************************************/
