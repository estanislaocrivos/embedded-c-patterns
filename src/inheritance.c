#include "inheritance.h"

/* ============================================================================================== */

#include <string.h>
#include <stdio.h>

/* ============================================================================================== */

/* Interface base object functionalities */

static void led_on_driver_x(void)
{
    printf("Setting the LED on, on device X...\n");
}

static void led_off_driver_x(void)
{
    printf("Setting the LED off, on device X...\n");
}

static void led_toggle_driver_x(void)
{
    printf("Toggling the LED, on device X...\n");
}

/* ============================================================================================== */

static void added_method(void* self)
{
    derived_object_t* obj = (derived_object_t*)self;
    printf("Hello, world, from new method on derived class...\n");
}

/* ============================================================================================== */

void derived_object_init(derived_object_t* self)
{
    memset(self, 0, sizeof(*self));

    /* Initialize base objects */
    object_init(&self->object_base);
    led_iface_init(&self->led_iface, led_toggle_driver_x, led_on_driver_x, led_off_driver_x);

    /* Initialize added functionality */
    self->added_method = added_method;
}

/* ============================================================================================== */
