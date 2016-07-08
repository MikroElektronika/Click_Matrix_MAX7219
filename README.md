![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

![matrix_click](http://cdn.mikroe.com/img/click/matrix-r/matrix-r-click.png)

---
[Product Page ( R ) ](http://www.mikroe.com/click/matrix-r/)

[Product Page ( G ) ](http://www.mikroe.com/click/matrix-g/)

[Manual Page](http://docs.mikroe.com/)

---

### General Description

Matrix click is a mikroBUS add-on board with two red 5x7 matrices driven by two MAX7219 8-bit LED Display Drivers. The active area of each matrix is 7.62mm high and 5.08 mm wide. 7x5 is a standard resolution for displaying ASCII characters, so the click is essentially a dual-character display capable of showing letters in more readable typefaces compared to a 14-segment display. The click communicates with the target MCU through the mikroBUS SPI interface with two separate Chip Select lines for each matrix (CSL for the left, CSR for the right). This board is designed to use a 5V power supply.

---

### Features

- A pair of 7x5 LED matrices
- 2x MAX7219 8-digit LED Display drivers
- SPI interface
- 5V power supply

---

### Example

#### Configuration
* MCU:             ATMEGA32
* Dev.Board:       EasyAVR Pro v7
* Oscillator:      8 Mhz external
* Ext. Modules:    Matrix R click
* SW:              MikroC PRO for AVR

```
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
```
