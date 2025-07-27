#ifndef VIRTUAL_API_H
#define VIRTUAL_API_H

/* ============================================================================================== */

#include <stdint.h>
#include <stddef.h>

/* ============================================================================================== */

typedef struct
{
    void (*init)(void* self);
    uint8_t (*read)(void* self, uint8_t* buf, size_t len);
    uint8_t (*write)(void* self, const uint8_t* buf, size_t len);
} serial_t;

/* ============================================================================================== */

serial_t* serial_init(void* serial_impl);

/* ============================================================================================== */

#endif
