#include "callback.h"

/* ============================================================================================== */

#include <stdlib.h>

/* ============================================================================================== */

void uart_observer_list_init(uart_observer_list_t* list)
{
    list->uart_observer_list = NULL;
}

/* ============================================================================================== */

void uart_register_callback(uart_observer_list_t* list, uart_observer_t* ob)
{
    ob->next                 = list->uart_observer_list;
    list->uart_observer_list = ob;
}

/* ============================================================================================== */

/* Quita un callback de la lista */
void uart_unregister_callback(uart_observer_list_t* list, uart_observer_t* ob)
{
    uart_observer_t** current = &list->uart_observer_list;
    while (*current)
    {
        if (*current == ob)
        {
            *current = ob->next;
            return;
        }
        current = &((*current)->next);
    }
}

/* ============================================================================================== */

/* Esta función simula el ISR de recepción de byte */
void uart_on_receive_isr(uart_observer_list_t* list, uint8_t byte)
{
    uart_observer_t* ob = list->uart_observer_list;
    while (ob)
    {
        ob->on_byte(ob, byte);
        ob = ob->next;
    }
}

/* ============================================================================================== */

#if 0

/* ============================================================================================== */

/* UART driver mock implementation */

typedef void (*uart_rx_isr_callback_t)(uint8_t byte);

static uart_rx_isr_callback_t uart_rx_callback = NULL;

void uart_set_rx_callback(uart_rx_isr_callback_t ob)
{
    uart_rx_callback = ob;
}

void uart_isr(void)
{
    uint8_t received_byte_mock;
    if (uart_rx_callback)
    {
        uart_rx_callback(received_byte_mock);
    }
}

/* ============================================================================================== */

/* Callback function which should be called from inside the driver ISR */
static void uart_rx_dispatch(uint8_t byte)
{
    uart_rx_observer_t* obs = observer_list;
    while (obs)
    {
        obs->on_byte(obs, byte);
        obs = obs->next;
    }
}

/* ============================================================================================== */

#endif
