#ifndef VIRTUAL_API_DRIVER_H
#define VIRTUAL_API_DRIVER_H

/* ============================================================================================== */

#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

/* ============================================================================================== */

#include "virtual_api.h"

/* ============================================================================================== */

/* Driver configuration*/
typedef struct
{
    uint32_t baudrate;
    uint8_t  port;
} stm32_uart_config_t;

/* This implementation strictly requires the first element of the driver struct to be the HAL api */
typedef struct
{
    serial_t             api;
    stm32_uart_config_t* uart_config;
} stm32_uart_t;

/* ============================================================================================== */

void stm32_uart_construct(stm32_uart_t* self, stm32_uart_config_t* config);

/* ============================================================================================== */

#endif
