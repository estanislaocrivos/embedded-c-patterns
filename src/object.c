#include "../inc/object.h"

/* ============================================================================================== */

#include <string.h>
#include <stdio.h>

/* ============================================================================================== */

static void object_method(void* self)
{
    my_object_t* obj = (my_object_t*)self;
    printf("Hello, from inside the object method...\n");
}

/* ============================================================================================== */

static void set_data_value(void* self, uint8_t data_index, uint8_t data_value)
{
    my_object_t* obj = (my_object_t*)self;
    if (data_index < DATA_SIZE)
    {
        obj->object_data[data_index] = data_value;
    }
}

/* ============================================================================================== */

void object_init(my_object_t* self)
{
    memset(self, 0, sizeof(*self));
    self->print_something = object_method;
    self->set_data_value  = set_data_value;
}

/* ============================================================================================== */
