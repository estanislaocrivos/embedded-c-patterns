#ifndef OBSERVER_H
#define OBSERVER_H

#include <stdint.h>

/* Each uart observer will have this form */
typedef struct
{
    void (*on_byte)(void* self, uint8_t byte);
    void* next;
} uart_observer_t;

/* Manejador principal del driver UART */
typedef struct
{
    uart_observer_t* uart_observer_list;
} uart_observer_list_t;

#endif
