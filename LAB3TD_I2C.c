/************************************************************************************************
TRANSMISIÓN DE DATOS 2023

Laboratorio N° 3 - Integrantes:
	- Medina Raed, Luis Eugenio
	- Padros, Marcos Isaias
	- Vaca Paz, Diego
	
*************************************************************************************************/

/************************************************************************************************
Copyright (c) 2022-2023, Laboratorio de Microprocesadores
Facultad de Ciencias Exactas y Tecnología, Universidad Nacional de Tucumán
https://www.microprocesadores.unt.edu.ar/

Copyright (c) 2022-2023, Esteban Volentini <evolentini@herrera.unt.edu.ar>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial
portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*************************************************************************************************/

/** \brief EDU-CIAA-NXP board sample application
 **
 ** \addtogroup samples Samples
 ** \brief Samples applications with MUJU Framwork
 ** @{ */

/* === Headers files inclusions =============================================================== */

#include "chip.h"
#include <stdio.h>


#include "stdlib.h"
#include "stdint.h"
#include "configuracion.h"
#include <string.h>

#define USB_UART LPC_USART2
#define MODEM_UART LPC_USART3

#define OVERRUN "ERROR OVERRUN\r\n"
#define PARITY "ERROR PARITY\r\n"
#define FRAMING "ERROR FRAMING\r\n"
#define BREAK "ERROR BREAK\r\n"
#define UNKNOWN "ERROR UNKNOWN\r\n"

/* === Macros definitions ====================================================================== */

#define LED_R_PORT    2
#define LED_R_PIN     0
#define LED_R_FUNC    SCU_MODE_FUNC4
#define LED_R_GPIO    5
#define LED_R_BIT     0

#define LED_G_PORT    2
#define LED_G_PIN     1
#define LED_G_FUNC    SCU_MODE_FUNC4
#define LED_G_GPIO    5
#define LED_G_BIT     1

#define LED_B_PORT    2
#define LED_B_PIN     2
#define LED_B_FUNC    SCU_MODE_FUNC4
#define LED_B_GPIO    5
#define LED_B_BIT     2

#define LED_1_PORT    2
#define LED_1_PIN     10
#define LED_1_FUNC    SCU_MODE_FUNC0
#define LED_1_GPIO    0
#define LED_1_BIT     14

#define LED_2_PORT    2
#define LED_2_PIN     11
#define LED_2_FUNC    SCU_MODE_FUNC0
#define LED_2_GPIO    1
#define LED_2_BIT     11

#define LED_3_PORT    2
#define LED_3_PIN     12
#define LED_3_FUNC    SCU_MODE_FUNC0
#define LED_3_GPIO    1
#define LED_3_BIT     12

#define I2C_RATE      100000

#define CHIP_ADDRESS  0x28

#define REG_MAIN_CTRL 0x00

/* === Private data type declarations ========================================================== */

/**
 * @brief Enumeration with color sequence of RGB led
 */
typedef enum rgb_color_e {
    LED_RED_ON = 0,
    LED_RED_OFF,
    LED_GREEN_ON,
    LED_GREEN_OFF,
    LED_BLUE_ON,
    LED_BLUE_OFF,
} rgb_color_t;

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/**
 * @brief Function to configure pins and gpio bits used by board leds
 */
static void ConfigureLeds(void);

/**
 * @brief Function to configure pins and gpio bits used by board keys
 */
static void ConfigureKeys(void);

/**
 * @brief Function to generate a delay of approximately 100 ms
 */
static void Delay(void);

/* === Public variable definitions ============================================================= */

static uint8_t actualizar = 0;

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

static void ConfigureLeds(void) {
    Chip_SCU_PinMuxSet(LED_R_PORT, LED_R_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | LED_R_FUNC);
    Chip_GPIO_SetPinState(LPC_GPIO_PORT, LED_R_GPIO, LED_R_BIT, false);
    Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, LED_R_GPIO, LED_R_BIT, true);

    Chip_SCU_PinMuxSet(LED_G_PORT, LED_G_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | LED_G_FUNC);
    Chip_GPIO_SetPinState(LPC_GPIO_PORT, LED_G_GPIO, LED_G_BIT, false);
    Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, LED_G_GPIO, LED_G_BIT, true);

    Chip_SCU_PinMuxSet(LED_B_PORT, LED_B_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | LED_B_FUNC);
    Chip_GPIO_SetPinState(LPC_GPIO_PORT, LED_B_GPIO, LED_B_BIT, false);
    Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, LED_B_GPIO, LED_B_BIT, true);

    /******************/
    Chip_SCU_PinMuxSet(LED_1_PORT, LED_1_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | LED_1_FUNC);
    Chip_GPIO_SetPinState(LPC_GPIO_PORT, LED_1_GPIO, LED_1_BIT, false);
    Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, LED_1_GPIO, LED_1_BIT, true);

    Chip_SCU_PinMuxSet(LED_2_PORT, LED_2_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | LED_2_FUNC);
    Chip_GPIO_SetPinState(LPC_GPIO_PORT, LED_2_GPIO, LED_2_BIT, false);
    Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, LED_2_GPIO, LED_2_BIT, true);

    Chip_SCU_PinMuxSet(LED_3_PORT, LED_3_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | LED_3_FUNC);
    Chip_GPIO_SetPinState(LPC_GPIO_PORT, LED_3_GPIO, LED_3_BIT, false);
    Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, LED_3_GPIO, LED_3_BIT, true);
}

static void ConfigureKeys(void) {
    /* Inicialización del Puerto I2C */

    // Configuracion de las lineas de SDA y SCL de la placa
    Chip_SCU_I2C0PinConfig(I2C0_STANDARD_FAST_MODE);
    // Inicializacion del periferico
    Chip_I2C_Init(I2C0);
    // Seleccion de velocidad del bus
    Chip_I2C_SetClockRate(I2C0, I2C_RATE);
    // Configuracion para que los eventos se resuelvan por polling
    // (la otra opcion es por interrupcion)
    Chip_I2C_SetMasterEventHandler(I2C0, Chip_I2C_EventHandlerPolling);
    // ToDo: Verificar si se inicializó correctamente
}

static void FlashLed(void) {
    static int divisor = 0;
    static rgb_color_t state = LED_BLUE_OFF;

    divisor++;
    if (divisor == 5) {
        divisor = 0;
        state = (state + 1) % (LED_BLUE_OFF + 1);

        switch (state) {
        case LED_RED_ON:
            Chip_GPIO_SetPinState(LPC_GPIO_PORT, LED_R_GPIO, LED_R_BIT, true);
            break;
        case LED_GREEN_ON:
            Chip_GPIO_SetPinState(LPC_GPIO_PORT, LED_G_GPIO, LED_G_BIT, true);
            break;
        case LED_BLUE_ON:
            Chip_GPIO_SetPinState(LPC_GPIO_PORT, LED_B_GPIO, LED_B_BIT, true);
            break;
        default:
            Chip_GPIO_SetPinState(LPC_GPIO_PORT, LED_R_GPIO, LED_R_BIT, false);
            Chip_GPIO_SetPinState(LPC_GPIO_PORT, LED_G_GPIO, LED_G_BIT, false);
            Chip_GPIO_SetPinState(LPC_GPIO_PORT, LED_B_GPIO, LED_B_BIT, false);
            break;
        }
    }
}

static uint8_t ReadKeys(void) {
    static uint8_t result = 0;

    I2CM_XFER_T transfer;
    
    uint8_t datatx[2];
    uint8_t datarx[4];
	
    datatx[0] = REG_MAIN_CTRL;

    // Prepara la lectura de los cuatro primeros registros
    transfer.slaveAddr = CHIP_ADDRESS;
    transfer.options = 0;
    transfer.status = 0;
    transfer.txBuff = &datatx[0]; 
    transfer.txSz = 0x01;
    transfer.rxBuff = &datarx[0];
    transfer.rxSz = 0x04;

    if (Chip_I2CM_XferBlocking(LPC_I2C0, &transfer)) {
        if (datarx[0] & 0x01) { 
            // Borrando el flag INT
            datatx[1] = datarx[0] & 0xfe;
            // Prepara la operación de escritura
            transfer.txBuff = datatx;
            transfer.txSz = 2;
            transfer.rxBuff = 0;
            transfer.rxSz = 0;
            // Borra los flags del integrado
            Chip_I2CM_XferBlocking(LPC_I2C0, &transfer);
        }
        result=datarx[3];
    }
    return result;
}

static void Delay(void) {
    for (int index = 0; index < 100; index++) {
        for (int delay = 0; delay < 2500; delay++) {
            __asm("NOP");
        }
    }
}

/* === Public function implementation ========================================================== */

int main(void) {
    uint8_t teclas;
    bool actual1, actual2, actual3; 
    bool anterior1 = false;
    bool anterior2 = false;
    bool anterior3 = false;
    
    ConfigureLeds();
    ConfigureKeys();

    while (true) {
        teclas = ReadKeys();

        actual1 = teclas & 0x01;
        actual2 = teclas & 0x02;
        actual3 = teclas & 0x04;
        if ((actual1) && (!anterior1)) {
            Chip_GPIO_SetPinToggle(LPC_GPIO_PORT, LED_1_GPIO, LED_1_BIT);
        }
        anterior1 = actual1;

        if ((actual2) && (!anterior2)) {
            Chip_GPIO_SetPinToggle(LPC_GPIO_PORT, LED_2_GPIO, LED_2_BIT);
        }
        anterior2 = actual2;

        if ((actual3) && (!anterior3)) {
            Chip_GPIO_SetPinToggle(LPC_GPIO_PORT, LED_3_GPIO, LED_3_BIT);
        }
        anterior3 = actual3;

        FlashLed();
        Delay();
    }

    return 0;
}

void SysTick_Handler(void) {
   static int contador = 0;

  contador++;
 
   if(contador %1000 == 0) {
       contador = 0;
       actualizar = 1;
   }
}

void ConfigurarUART(LPC_USART_T *pUART){
    Chip_UART_Init(pUART);

    // Habilito DLAB
    pUART->LCR |= 1<<7;

    //Configuro el divisor del clock
    pUART->DLM = 0x01;
    pUART->DLL = 0x4C;

    //Deshabilito DLAB
    pUART->LCR &= 0 << 7;
	
    //Configuro el LCR
    pUART->LCR = 0x3;

	//Habilito Tx
    pUART->TER2 = 1<<0;
}

uint8_t UARTDisponible(LPC_USART_T *pUART){
    return ((pUART->LSR & UART_LSR_THRE) != 0 );
}

uint8_t UARTLeerByte(LPC_USART_T *pUART, uint8_t* data, uint8_t* error){
    uint8_t resultado = 0;
    uint8_t status = pUART->LSR;
    if (status & (1<<0)){
        resultado = 1;
        if (status & ((1<<1)|(1<<2)|(1<<3)|(1<<4))){
            /*ERROR*/
            *error = status & (0x1E);
        } else {
            *data = (pUART->RBR & (0xFF));
        }
    }
    return resultado;
}

void UARTEscribirByte(LPC_USART_T *pUART, uint8_t data){
    while(!UARTDisponible(pUART)){};
    pUART->THR = data;
}

void UARTEscribirString(LPC_USART_T *pUART, char string[]){
    for(int i = 0; i < strlen(string); i++){
        UARTEscribirByte(pUART, (uint8_t)string[i]);
    }
}

/* === End of documentation ==================================================================== */

/** @} End of module definition for doxygen */
