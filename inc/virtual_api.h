#ifndef VIRTUAL_API_H
#define VIRTUAL_API_H

/* ============================================================================================== */

#include <stdint.h>
#include <stddef.h>

/* ============================================================================================== */

/* This structure defines the api for the required interface. In this case an api for a serial
 * interface was implemented, with various functionalities. Each one of these funcionalities must be
 * implemented by the underneath driver. */
typedef struct
{
    void (*init)(void* self);
    uint8_t (*read)(void* self, uint8_t* buf, size_t len);
    uint8_t (*write)(void* self, const uint8_t* buf, size_t len);
    /* Here you may add new methods for added functionalities. Then, each driver which implements
     * this api must also implement the new functionalities (at least a mock). Else, you can check
     * if each method is implemented on runtime, by checking if the function pointer is not NULL */
    uint8_t (*change_baudrate)(void* self, uint32_t baudrate);  // Example
} serial_t;

/* ============================================================================================== */

/**
 * @brief Initialize the serial interface.
 * @param serial_impl Pointer to the serial implementation (driver). The driver structure MUST hold
 * the serial_t api as the first element.
 * @return serial_t* Pointer to the initialized serial interface.
 */
serial_t* serial_init(void* serial_impl);

/* ============================================================================================== */

#endif
