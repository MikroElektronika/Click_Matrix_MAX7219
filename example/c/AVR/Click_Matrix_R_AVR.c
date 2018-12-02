/*
Example for Matrix_R Click

    Date          : Jul 2018.
    Author        : Nenad Filipovic

Test configuration AVR :
    
    MCU              : ATMEGA32
    Dev. Board       : EasyAVR v7 
    AVR Compiler ver : v7.0.1.0

---

Description :

The application is composed of three sections :

- System Initialization - Intializes CS and AN pin as output and SPI module
- Application Initialization - Default driver intializes boath max7219 register: decode mode, intensity, scan limit and shutdown.
- Application Task - (code snippet) - This example show functionality of Matrix_R Click - display character, using the SPI interface.

Additional Functions :

- SPI

*/

#include "Click_Matrix_R_types.h"
#include "Click_Matrix_R_config.h"

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_AN_PIN, _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );

    mikrobus_spiInit( _MIKROBUS1, &_MATRIXR_SPI_CFG[0] );
    
    Delay_100ms();
}

void applicationInit()
{
    matrixr_spiDriverInit( (T_MATRIXR_P)&_MIKROBUS1_GPIO, (T_MATRIXR_P)&_MIKROBUS1_SPI );
    
    matrixr_writeDataReg( _MATRIXR_DECODE_MODE_REG, _MATRIXR_NO_DECODE );
    matrixr_writeDataReg( _MATRIXR_INTENSITY_REG,   _MATRIXR_INTEN_LVL_3);
    matrixr_writeDataReg( _MATRIXR_SCAN_LIMIT_REG,  _MATRIXR_DISPLAY_DIGIT_0_6);
    matrixr_writeDataReg( _MATRIXR_SHUTDOWN_REG,    _MATRIXR_NORMAL_OPERATION);
    
    Delay_100ms();
}

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

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
        applicationTask();
    }
}
