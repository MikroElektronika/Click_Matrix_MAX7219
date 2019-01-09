![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# Matrix R Click

- **CIC Prefix**  : MATRIXR
- **Author**      : Nenad Filipovic
- **Verison**     : 1.0.1
- **Date**        : Jul 2018.

---

### Software Support

We provide a library for the Matrix R Click on our [LibStock](https://libstock.mikroe.com/projects/view/1852/matrix-r-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

This library contains two drivers for controling  matrix display, 
as well as the functions write register and function for display character.

Key functions :

- ``` void matrixr_writeDataReg(uint8_t registerAdress, uint8_t dataValue) ``` - Generic write register function
- ``` void matrixr_displayCharacter( uint8_t characterLeft, uint8_t characterRight ) ``` - Function display left and right character

**Examples Description**

The application is composed of three sections :

- System Initialization - Intializes CS and AN pin as output and SPI module
- Application Initialization - Default driver intializes boath max7219 register: decode mode, intensity, scan limit and shutdown.
- Application Task - (code snippet) - This example show functionality of Matrix_R Click - display character, using the SPI interface.


```.c

void applicationTask()
{
    matrixr_displayCharacter( ' ', 'M' );
    Delay_1sec();
    matrixr_displayCharacter( 'M', 'i' );
    Delay_1sec();
    matrixr_displayCharacter( 'i', 'k' );
    Delay_1sec();
    matrixr_displayCharacter( 'k', 'r' );
    Delay_1sec();
    matrixr_displayCharacter( 'r', 'o' );
    Delay_1sec();
    matrixr_displayCharacter( 'o', 'E' );
    Delay_1sec();
    matrixr_displayCharacter( 'E', 'l' );
    Delay_1sec();
    matrixr_displayCharacter( 'l', 'e' );
    Delay_1sec();
    matrixr_displayCharacter( 'e', 'k' );
    Delay_1sec();
    matrixr_displayCharacter( 'k', 't' );
    Delay_1sec();
    matrixr_displayCharacter( 't', 'r' );
    Delay_1sec();
    matrixr_displayCharacter( 'r', 'o' );
    Delay_1sec();
    matrixr_displayCharacter( 'o', 'n' );
    Delay_1sec();
    matrixr_displayCharacter( 'n', 'i' );
    Delay_1sec();
    matrixr_displayCharacter( 'i', 'k' );
    Delay_1sec();
    matrixr_displayCharacter( 'k', 'a' );
    Delay_1sec();
    matrixr_displayCharacter( 'a', ' ' );
    Delay_1sec();
}

```



The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/1852/matrix-r-click) page.

Other mikroE Libraries used in the example:

- SPI


**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
