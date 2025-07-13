#ifndef OBSERVER_H
#define OBSERVER_H

/* ============================================================================================== */

#include <stdint.h>

/* ============================================================================================== */

/* Each uart observer will have this form. This implementation uses a linked list to link all the
 * observers */
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

/**
 * @brief This function initializes the observer list.
 * @param list Pointer to the observer list to be initialized.
 */
void uart_observer_list_init(uart_observer_list_t* list);

/* ============================================================================================== */

/**
 * @brief Registers an observer to the list.
 * @param list Pointer to the observer list.
 * @param ob Pointer to the observer to be registered.
 * @note The observer should be of type uart_observer_t. Its `on_byte` function should be set to
 *       handle the byte received from the UART interface. Its `next` pointer should be set to
 *       NULL before calling this function. It will then be automatically be linked to the list.
 */
void uart_register_observer(uart_observer_list_t* list, uart_observer_t* ob);

/* ============================================================================================== */

/**
 * @brief Removes an observer from the list.
 * @param list Pointer to the observer list.
 * @param ob Pointer to the observer to be removed.
 */
void uart_remove_observer(uart_observer_list_t* list, uart_observer_t* ob);

/* ============================================================================================== */

/**
 * @brief Notifies all observers in the list about a received byte.
 * @param list Pointer to the observer list.
 * @param byte The byte received from the UART interface.
 */
void uart_notify_observers(uart_observer_list_t* list, uint8_t byte);

/* ============================================================================================== */

#endif
