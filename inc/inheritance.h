#ifndef INHERITANCE_H
#define INHERITANCE_H

/* ============================================================================================== */

#include "object.h"
#include "interface.h"

/* ============================================================================================== */

/**
 * @brief Derived object structure that extends the base object and includes an LED interface.
 * This structure inherits from the base object and adds an LED interface and a new method.
 * @note This structure is used to demonstrate inheritance (quasi-composition) in C, where the
 * derived object can handle both the base object functionalities and the LED interface
 * functionalities.
 */
typedef struct
{
    my_object_t object_base;
    led_iface_t led_iface;
    void (*added_method)(void*);
} derived_object_t;

/* ============================================================================================== */

/**
 * @brief Initializes the derived object with default values.
 * @param self Pointer to the derived object structure to be initialized.
 */
void derived_object_init(derived_object_t* self);

/* ============================================================================================== */

#endif
