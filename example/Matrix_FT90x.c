#include "matrix.h"

sbit MATRIX_CSR at GPIO_PIN9_bit;
sbit MATRIX_CSL at GPIO_PIN28_bit;

void system_init( void );

void system_init()
{
    GPIO_Digital_Output( &GPIO_PORT_08_15, _GPIO_PINMASK_1 );
    GPIO_Digital_Output( &GPIO_PORT_24_31, _GPIO_PINMASK_4 );
    Delay_ms( 200 );

    SPIM1_Init_Advanced( _SPI_MASTER_CLK_RATIO_64, _SPI_CFG_PHASE_CAPTURE_FALLING |
		         _SPI_CFG_POLARITY_IDLE_LOW | _SPI_CFG_SS_AUTO_DISABLE |
		         _SPI_CFG_FIFO_DISABLE, _SPI_SS_LINE_NONE );

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