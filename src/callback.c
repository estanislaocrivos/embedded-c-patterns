#include "callback.h"

/* ============================================================================================== */

#include <stdlib.h>

/* ============================================================================================== */

void uart_observer_list_init(uart_observer_list_t* list)
{
    list->uart_observer_list = NULL;
}

/* ============================================================================================== */

void uart_register_observer(uart_observer_list_t* list, uart_observer_t* ob)
{
    ob->next                 = list->uart_observer_list;
    list->uart_observer_list = ob;
}

/* ============================================================================================== */

void uart_remove_observer(uart_observer_list_t* list, uart_observer_t* ob)
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

void uart_notify_observers(uart_observer_list_t* list, uint8_t byte)
{
    uart_observer_t* ob = list->uart_observer_list;
    while (ob)
    {
        ob->on_byte(ob, byte);
        ob = (uart_observer_t*)ob->next;
    }
}

/* ============================================================================================== */
