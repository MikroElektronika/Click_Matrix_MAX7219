#include "matrix.h"

sbit MATRIX_CSR         at LATB8_bit;
sbit MATRIX_CSR_DIR     at TRISB8_bit;
sbit MATRIX_CSL         at LATC2_bit;
sbit MATRIX_CSL_DIR     at TRISC2_bit;

void system_init( void );

void system_init()
{
    MATRIX_CSR_DIR = 0;
    MATRIX_CSL_DIR = 0;
    Delay_ms( 200 );

    SPI3_Init_Advanced( _SPI_MASTER, _SPI_8_BIT, 1, _SPI_SS_DISABLE,
                        _SPI_DATA_SAMPLE_MIDDLE, _SPI_CLK_IDLE_LOW,
                        _SPI_IDLE_2_ACTIVE );
    Delay_ms( 200 );
}

void main() 
{
    system_init();
    matrix_init();

    matrix_char_left( 'm' );
    matrix_char_right( 'E' );
    Delay_ms( 1000 );

    matrix_blink_smooth( 3, MATRIX_MED_FAST );
    Delay_ms( 1000 );

    matrix_text_blink( "MIKROELEKTRONIKA", MATRIX_MED_FAST );
    Delay_ms( 1000 );

    matrix_text_scroll( "This is the demonstration of the Matrix Click board",
                        MATRIX_MED );
    Delay_ms( 1000 );
}