/****************************************************************************
* Title                 :   MATRIX R
* Filename              :   matrix_r.c
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
 * @file matrix_r.c
 * @brief <h3> Matrix Click functions </h3>
 */
/******************************************************************************
* Includes
*******************************************************************************/
#include "matrix.h"
#include "matrix_font.h"
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
static uint8_t brightness;
/******************************************************************************
* Function Prototypes
*******************************************************************************/
static void _map_char( char input,
                       uint8_t *output );

static void _sub_scroll( uint8_t *buffer,
                         uint8_t *letter,
                         uint8_t line );
/******************************************************************************
* Private Function Definitions
*******************************************************************************/
static void _map_char( char input,
                       uint8_t *output )
{
    uint8_t i;
    uint8_t *ptr = output;

    if( input == 0 )
        input = ' ';

    for( i = 0; i < 8; i++ )
        *( ptr + i ) = matrix_r_font[ ( ( uint8_t )input - 32 ) * 8 + 7 - i ];
}

static void _sub_scroll( uint8_t *buffer,
                         uint8_t *letter,
                         uint8_t line )
{
    int i;
    uint8_t *ch = letter;
    uint8_t *buff = buffer;

    for( i = 0; i < 8; i++ )
    {
        *( buffer + i ) <<= 1;

        if( *( buffer + i + 8 ) & 0x80 )
            *( buffer + i ) |= 0x01;

        *( buffer + i + 8 ) <<= 1;

        if( *( ch + i ) & ( 1 << ( 7 - line ) ) )
            *( buff + i + 8 ) |= 0x01;
    }
}
/******************************************************************************
* Public Function Definitions
*******************************************************************************/
void matrix_init( void )
{
    brightness = MATRIX_BRIGHT_MAX;

    matrix_hw_init();
}

void matrix_power( bool state )
{
    if( state )
        matrix_hw_cmd( MATRIX_SHUTDOWN, 1 );
    else
        matrix_hw_cmd( MATRIX_SHUTDOWN, 0 );
}

void matrix_brightness( uint8_t value )
{
    if( value > MATRIX_BRIGHT_MAX )
        value = MATRIX_BRIGHT_MAX;

    brightness = value;

    matrix_hw_cmd( MATRIX_INTENSITY, brightness );
}

void matrix_blink( uint16_t cycles,
                     MATRIX_SPEED_t speed )
{
    bool dir = false;
    uint32_t c = cycles * 2;

    while( c-- )
    {
        matrix_power( dir );

        dir = ~dir;

        switch ( speed )
        {
            case MATRIX_SLOW :
                Delay_ms( 1000 );
            break;
            case MATRIX_MED_SLOW :
                Delay_ms( 500 );
            break;
            case MATRIX_MED :
                Delay_ms( 250 );
            break;
            case MATRIX_MED_FAST :
                Delay_ms( 100 );
            break;
            case MATRIX_FAST :
                Delay_ms( 50 );
            break;
        }
    }
}

void matrix_blink_smooth( uint16_t cycles,
                            MATRIX_SPEED_t speed )
{
    bool dir;
    uint8_t i   = brightness;
    uint32_t c  = cycles * 2 * MATRIX_BRIGHT_MAX ;

    while( c-- )
    {
        if( i == 0 )
            dir = true;

        if( i == MATRIX_BRIGHT_MAX )
            dir = false;

        if( dir )
            i++;
        else
            i--;

        matrix_brightness( i );

        switch ( speed )
        {
            case MATRIX_SLOW :
                Delay_ms( 200 );
            break;
            case MATRIX_MED_SLOW :
                Delay_ms( 100 );
            break;
            case MATRIX_MED :
                Delay_ms( 50 );
            break;
            case MATRIX_MED_FAST :
                Delay_ms( 20 );
            break;
            case MATRIX_FAST :
                Delay_ms( 10 );
            break;
        }
    }
}

void matrix_char_left( char input )
{
    uint8_t temp[ MATRIX_Y ] = { 0 };

    _map_char( input, temp );
    matrix_hw_clean( 0, 8 );
    matrix_hw_set( 0, 8, temp );
    matrix_hw_display();
}

void matrix_char_right( char input )
{
    uint8_t temp[ MATRIX_Y ] = { 0 };

    _map_char( input, temp );
    matrix_hw_clean( 8, 8 );
    matrix_hw_set( 8, 8, temp );
    matrix_hw_display();
}

void matrix_text_blink( char *text,
                          MATRIX_SPEED_t speed )
{
    uint8_t c;
    uint8_t *ptr = ( uint8_t* )text;
    uint8_t len = strlen( ptr );

    matrix_hw_clean( 0, 0 );
    matrix_hw_display();

    for( c = 0; c <= len - 1; c += 2 )
    {
        matrix_power( false );

        switch ( speed )
        {
            case MATRIX_SLOW :
                Delay_ms( 1500 );
            break;
            case MATRIX_MED_SLOW :
                Delay_ms( 750 );
            break;
            case MATRIX_MED :
                Delay_ms( 500 );
            break;
            case MATRIX_MED_FAST :
                Delay_ms( 250 );
            break;
            case MATRIX_FAST :
                Delay_ms( 150 );
            break;
        }

        matrix_char_left( *ptr++ );
        matrix_char_right( *ptr++ );
        matrix_power( true );

        switch ( speed )
        {
            case MATRIX_SLOW :
                Delay_ms( 1500 );
            break;
            case MATRIX_MED_SLOW :
                Delay_ms( 750 );
            break;
            case MATRIX_MED :
                Delay_ms( 500 );
            break;
            case MATRIX_MED_FAST :
                Delay_ms( 250 );
            break;
            case MATRIX_FAST :
                Delay_ms( 150 );
            break;
        }

    }

    matrix_hw_clean( 0, 0 );
    matrix_hw_display();
}

void matrix_text_scroll( char *text,
                           MATRIX_SPEED_t speed )
{
    uint8_t c;
    uint8_t *ptr = ( uint8_t* )text;
    uint8_t work_letter[ 8 ] = { 0 };
    uint8_t work_buffer[ MATRIX_Y * 2 ] = { 0 };
    uint16_t len = strlen( ptr );

    matrix_hw_clean( 0, 0 );
    matrix_hw_display();
    matrix_hw_get( 0, 0, work_buffer );

    while( len-- )
    {
        _map_char( *ptr++, work_letter );

        for( c = 0; c < 8; c++ )
        {
            _sub_scroll( work_buffer, work_letter, c );
            matrix_hw_set( 0, 0, work_buffer );
            matrix_hw_display();

            switch ( speed )
            {
                case MATRIX_SLOW :
                    Delay_ms( 240 );
                break;
                case MATRIX_MED_SLOW :
                    Delay_ms( 120 );
                break;
                case MATRIX_MED :
                    Delay_ms( 60 );
                break;
                case MATRIX_MED_FAST :
                    Delay_ms( 30 );
                break;
                case MATRIX_FAST :
                    Delay_ms( 15 );
                break;
            }
        }
    }

    _map_char( 0, work_letter );

    for( c = 0; c < 8; c++ )
    {
        _sub_scroll( work_buffer, work_letter, c );
        matrix_hw_set( 0, 0, work_buffer );
        matrix_hw_display();

        switch ( speed )
        {
            case MATRIX_SLOW :
                Delay_ms( 240 );
            break;
            case MATRIX_MED_SLOW :
                Delay_ms( 120 );
            break;
            case MATRIX_MED :
                Delay_ms( 60 );
            break;
            case MATRIX_MED_FAST :
                Delay_ms( 30 );
            break;
            case MATRIX_FAST :
                Delay_ms( 15 );
            break;
        }
    }

    _map_char( 0, work_letter );

    for( c = 0; c < 8; c++ )
    {
        _sub_scroll( work_buffer, work_letter, c );
        matrix_hw_set( 0, 0, work_buffer );
        matrix_hw_display();

        switch ( speed )
        {
            case MATRIX_SLOW :
                Delay_ms( 240 );
            break;
            case MATRIX_MED_SLOW :
                Delay_ms( 120 );
            break;
            case MATRIX_MED :
                Delay_ms( 60 );
            break;
            case MATRIX_MED_FAST :
                Delay_ms( 30 );
            break;
            case MATRIX_FAST :
                Delay_ms( 15 );
            break;
        }
    }

    matrix_hw_clean( 0, 0 );
    matrix_hw_display();
}

/*************** END OF FUNCTIONS *********************************************/
