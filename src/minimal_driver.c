#include "minimal_driver.h"

/* ============================================================================================== */

#include <stdio.h>

/* ============================================================================================== */

static uart_rx_isr_callback_t uart_rx_callback = NULL;

/* ============================================================================================== */

void uart_driver_set_rx_callback(uart_rx_isr_callback_t ob)
{
    uart_rx_callback = ob;
}

/* ============================================================================================== */

void uart_driver_isr(void)
{
    uint8_t received_byte_mock = 0xFF;
    printf("UART received byte: 0x%02X\n", received_byte_mock);
    if (uart_rx_callback)
    {
        printf("Calling callback function from inside UART driver...\n");
        uart_rx_callback(received_byte_mock);
    }
}

/* ============================================================================================== */
