#include "matrix.h"

sbit MATRIX_CSR         at PORTA7_bit;
sbit MATRIX_CSR_DIR 	at DDA7_bit;
sbit MATRIX_CSL         at PORTA5_bit;
sbit MATRIX_CSL_DIR 	at DDA5_bit;

void system_init( void );

void system_init()
{
    MATRIX_CSR_DIR = 1;
    MATRIX_CSL_DIR = 1;
    Delay_ms( 200 );

    SPI1_Init_Advanced( _SPI_MASTER, _SPI_FCY_DIV8, _SPI_CLK_LO_LEADING );
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