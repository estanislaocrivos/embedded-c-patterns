#ifndef MINIMAL_DRIVER_H
#define MINIMAL_DRIVER_H

/* ============================================================================================== */

#include <stdint.h>

/* ============================================================================================== */

typedef void (*uart_rx_isr_callback_t)(uint8_t byte);

void uart_driver_set_rx_callback(uart_rx_isr_callback_t ob);

/* Exposed only for demonstration purposes on main() */
void uart_driver_isr(void);

/* ============================================================================================== */

#endif
