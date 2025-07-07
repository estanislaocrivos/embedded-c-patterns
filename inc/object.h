#ifndef OBJECT_H
#define OBJECT_H

#include <stdint.h>

typedef struct
{
    uint8_t object_flags;
    uint8_t object_data[255];
    void (*object_method)(void);
} my_object_t;

void object_init(my_object_t* self);

void object_deinit(my_object_t* self);

#endif
