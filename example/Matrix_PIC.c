#include "matrix.h"

sbit MATRIX_CSR at LATA0_bit;
sbit MATRIX_CSL at LATE0_bit;
sbit MATRIX_CSR_DIR at TRISA0_bit;
sbit MATRIX_CSL_DIR at TRISE0_bit;

void system_init( void );

void system_init()
{
    MATRIX_CSR_DIR = 0;
    MATRIX_CSL_DIR = 0;
    Delay_ms( 200 );

    SPI1_Init_Advanced( _SPI_MASTER_OSC_DIV4, _SPI_DATA_SAMPLE_MIDDLE,
                        _SPI_CLK_IDLE_LOW, _SPI_LOW_2_HIGH );
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