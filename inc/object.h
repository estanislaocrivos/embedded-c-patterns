#ifndef OBJECT_H
#define OBJECT_H

/* ============================================================================================== */

#include <stdint.h>

/* ============================================================================================== */

#define DATA_SIZE 8

/* ============================================================================================== */

typedef struct
{
    uint8_t object_flags;
    uint8_t object_data[DATA_SIZE];
    void (*print_something)(void*); /* This method is used to print something from the object. */
    void (*set_data_value)(void*,
                           uint8_t,
                           uint8_t); /* This method is used to set a value in the object's data. */
} my_object_t;

/* ============================================================================================== */

/**
 * @brief Initializes the object with default values.
 * @param self The pointer to the object.
 * @param print_something_func Function pointer to print something.
 * @param set_data_value_func Function pointer to set data value.
 */
void object_init(my_object_t* self);

/* ============================================================================================== */

#endif
