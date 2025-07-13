#ifndef OBSERVER_H
#define OBSERVER_H

/* ============================================================================================== */

#include <stdint.h>

/* ============================================================================================== */

/* Each uart observer will have this form */
typedef struct uart_observer
{
    void (*on_byte)(struct uart_observer* self, uint8_t byte);
    struct uart_observer* next;
} uart_observer_t;

/* ============================================================================================== */

/* This structure holds the list of observers */
typedef struct
{
    uart_observer_t* uart_observer_list;
} uart_observer_list_t;

/* ============================================================================================== */

void uart_observer_list_init(uart_observer_list_t* list);

/* ============================================================================================== */

void uart_register_observer(uart_observer_list_t* list, uart_observer_t* ob);

/* ============================================================================================== */

void uart_remove_observer(uart_observer_list_t* list, uart_observer_t* ob);

/* ============================================================================================== */

void uart_notify_observers(uart_observer_list_t* list, uint8_t byte);

/* ============================================================================================== */

#endif
