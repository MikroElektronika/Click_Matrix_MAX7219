#include "matrix.h"

sbit MATRIX_CSR at GPIOA_ODR.B4;
sbit MATRIX_CSL at GPIOD_ODR.B13;

void system_init( void );

void system_init()
{
    GPIO_Digital_Output( &GPIOA_BASE, _GPIO_PINMASK_4 );
    GPIO_Digital_Output( &GPIOD_BASE, _GPIO_PINMASK_13 );
    Delay_ms( 200 );

    SPI3_Init_Advanced( _SPI_FPCLK_DIV64, _SPI_MASTER | _SPI_8_BIT |
                        _SPI_CLK_IDLE_LOW | _SPI_FIRST_CLK_EDGE_TRANSITION |
                        _SPI_MSB_FIRST | _SPI_SS_DISABLE | _SPI_SSM_ENABLE |
                        _SPI_SSI_1, &_GPIO_MODULE_SPI3_PC10_11_12 );
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