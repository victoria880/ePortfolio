/*
 * Copyright (c) 2015-2020, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ======== gpiointerruptenhancement.c ========
 */
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>

#include <ti/drivers/Timer.h>
#include <ti/drivers/UART.h>
#include <ti/drivers/I2C.h>
#include <ti/drivers/GPIO.h>

#include "ti_drivers_config.h"

// Global variables
volatile int flag_button = 0;
enum { LEFT, RIGHT } button;
int end_period_cnt = 0;
int set_point = 23;
const int period_in_milliseconds = 100;
const int one_second_in_milliseconds = 1000;

// I2C Variables
static const struct {
    uint8_t address;
    uint8_t resultReg;
    char *id;
} sensors[3] = {
    { 0x48, 0x0000, "11X" },
    { 0x49, 0x0000, "116" },
    { 0x41, 0x0001, "006" }
};
uint8_t txBuffer[1];
uint8_t rxBuffer[2];
I2C_Transaction i2cTransaction;
I2C_Handle i2c;

// UART Variables
char uartOutput[64];
UART_Handle uart;

// Timer Variables
Timer_Handle timer0;
volatile unsigned char TimerFlag = 0;

// Function prototypes
void initI2C(void);
int16_t readTemp(void);
void initUART(void);
void timerCallback(Timer_Handle myHandle, int_fast16_t status);
void initTimer(void);
void gpioButtonFxn0(uint_least8_t index);
void gpioButtonFxn1(uint_least8_t index);
void interpretation_check(void);
void temperature_check(void);
void LED_check_print(void);

void initI2C(void) {
    int8_t i;
    bool found = false;
    I2C_Params i2cParams;

    UART_write(uart, "Initializing I2C Driver\n", sizeof("Initializing I2C Driver\n"));

    I2C_init();
    I2C_Params_init(&i2cParams);
    i2cParams.bitRate = I2C_400kHz;
    i2c = I2C_open(CONFIG_I2C_0, &i2cParams);

    if (i2c == NULL) {
        UART_write(uart, "Failed to open I2C driver\n", sizeof("Failed to open I2C driver\n"));
        while (1);
    }

    for (i = 0; i < 3; ++i) {
        i2cTransaction.slaveAddress = sensors[i].address;
        txBuffer[0] = sensors[i].resultReg;
        sprintf(uartOutput, "Checking sensor %s...", sensors[i].id);
        UART_write(uart, uartOutput, strlen(uartOutput));

        if (I2C_transfer(i2c, &i2cTransaction)) {
            sprintf(uartOutput, "Sensor %s found\n", sensors[i].id);
            UART_write(uart, uartOutput, strlen(uartOutput));
            found = true;
            break;
        } else {
            UART_write(uart, "No\n", sizeof("No\n"));
        }
    }

    if (found) {
        sprintf(uartOutput, "Detected TMP%s I2C address: %x\n", sensors[i].id, i2cTransaction.slaveAddress);
        UART_write(uart, uartOutput, strlen(uartOutput));
    } else {
        UART_write(uart, "Temperature sensor not found\n", sizeof("Temperature sensor not found\n"));
    }
}

int16_t readTemp(void) {
    int16_t temperature = 0;

    i2cTransaction.readCount = 2;
    if (I2C_transfer(i2c, &i2cTransaction)) {
        temperature = (rxBuffer[0] << 8) | rxBuffer[1];
        temperature *= 0.0078125;

        if (rxBuffer[0] & 0x80) {
            temperature |= 0xF000;
        }
    } else {
        UART_write(uart, "Error reading temperature sensor\n", sizeof("Error reading temperature sensor\n"));
        UART_write(uart, "Please power cycle your board\n", sizeof("Please power cycle your board\n"));
    }

    return temperature;
}

void initUART(void) {
    UART_Params uartParams;

    UART_init();
    UART_Params_init(&uartParams);
    uartParams.writeDataMode = UART_DATA_BINARY;
    uartParams.readDataMode = UART_DATA_BINARY;
    uartParams.readReturnMode = UART_RETURN_FULL;
    uartParams.baudRate = 115200;

    uart = UART_open(CONFIG_UART_0, &uartParams);
    if (uart == NULL) {
        UART_write(uart, "Failed to open UART driver\n", sizeof("Failed to open UART driver\n"));
        while (1);
    }
}

void timerCallback(Timer_Handle myHandle, int_fast16_t status) {
    TimerFlag = 1;
}

void initTimer(void) {
    Timer_Params params;

    Timer_init();
    Timer_Params_init(&params);
    params.period = 100000;
    params.periodUnits = Timer_PERIOD_US;
    params.timerMode = Timer_CONTINUOUS_CALLBACK;
    params.timerCallback = timerCallback;

    timer0 = Timer_open(CONFIG_TIMER_0, &params);
    if (timer0 == NULL) {
        UART_write(uart, "Failed to initialize timer\n", sizeof("Failed to initialize timer\n"));
        while (1);
    }

    if (Timer_start(timer0) == Timer_STATUS_ERROR) {
        UART_write(uart, "Failed to start timer\n", sizeof("Failed to start timer\n"));
        while (1);
    }
}

void gpioButtonFxn0(uint_least8_t index) {
    if (flag_button == 0) {
        flag_button = 1;
        button = LEFT;
    } else {
        flag_button = 0;
        button = LEFT;
    }
}

void gpioButtonFxn1(uint_least8_t index) {
    if (flag_button == 0) {
        flag_button = 1;
        button = RIGHT;
    } else {
        flag_button = 0;
        button = RIGHT;
    }
}

void interpretation_check(void) {
    if (flag_button == 1) {
        sprintf(uartOutput, "Right button pressed\n");
        UART_write(uart, uartOutput, strlen(uartOutput));

        if (button == LEFT) {
            set_point++;
        } else if (button == RIGHT) {
            set_point--;
        }
    } else {
        sprintf(uartOutput, "No button pressed\n");
        UART_write(uart, uartOutput, strlen(uartOutput));
    }
}

void temperature_check(void) {
    int16_t temperature = readTemp();
    sprintf(uartOutput, "Current temperature: %d\n", temperature);
    UART_write(uart, uartOutput, strlen(uartOutput));
}

void LED_check_print(void) {
    int heat;

    int temperature = readTemp();
    if (temperature >= set_point) {
        heat = 0;
        GPIO_write(CONFIG_GPIO_LED_0, CONFIG_GPIO_LED_OFF);
    } else {
        heat = 1;
        GPIO_write(CONFIG_GPIO_LED_0, CONFIG_GPIO_LED_ON);
    }

    sprintf(uartOutput, "<%02d, %02d, %d, %04d>\n", temperature, set_point, heat, (period_in_milliseconds * end_period_cnt) / one_second_in_milliseconds);
    UART_write(uart, uartOutput, strlen(uartOutput));

    end_period_cnt = 0;
}

void *mainThread(void *arg0) {
    GPIO_init();
    initUART();
    initI2C();
    initTimer();

    GPIO_setConfig(CONFIG_GPIO_LED_0, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);
    GPIO_setConfig(CONFIG_GPIO_BUTTON_0, GPIO_CFG_IN_PU | GPIO_CFG_IN_INT_FALLING);
    GPIO_setCallback(CONFIG_GPIO_BUTTON_0, gpioButtonFxn0);
    GPIO_enableInt(CONFIG_GPIO_BUTTON_0);

    if (CONFIG_GPIO_BUTTON_0 != CONFIG_GPIO_BUTTON_1) {
        GPIO_setConfig(CONFIG_GPIO_BUTTON_1, GPIO_CFG_IN_PU | GPIO_CFG_IN_INT_FALLING);
        GPIO_setCallback(CONFIG_GPIO_BUTTON_1, gpioButtonFxn1);
        GPIO_enableInt(CONFIG_GPIO_BUTTON_1);
}
    while(TRUE){
            if (TimerFlag==1){
                end_period_cnt++;
                if(end_period_cnt==5)
                    temperature_check();
                if(end_period_cnt==10){
                    interpretation_check();
                    LED_check_print();
                }
                if(end_period_cnt==2||end_period_cnt==4||end_period_cnt==6||end_period_cnt==8)
                    interpretation_check();

            }TimerFlag = 0; // Reset TimerFla
        }
        return (NULL);
    }
