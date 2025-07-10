#include "../inc/opaque.h"

/* ============================================================================================== */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* ============================================================================================== */

/* In the opaque pattern the data structure is private. The API only exposes methods for
 * initializing, reading and writing data to the structure, but it cannot be accesed directly from
 * outside. */

typedef struct
{
    uint8_t data_a;
    uint8_t data_b;
    uint8_t data_c;
} opaque_obj_t;

/* ============================================================================================== */

uint8_t get_opaque_obj_size(void)
{
    return sizeof(opaque_obj_t);
}

/* ============================================================================================== */

struct opaque* opaque_obj_new(void)
{
    return malloc(sizeof(opaque_obj_t));
}

/* ============================================================================================== */

void opaque_obj_free(struct opaque** self)
{
    free(*self);
    *self = NULL;
}

/* ============================================================================================== */

void opaque_obj_init(void* self)
{
    opaque_obj_t* op_obj = (opaque_obj_t*)self;
    /* Here you may disable interrupts to lock access to memory for write op. */
    memset(op_obj, 0, sizeof(*op_obj));
    /* Here you may set init. values for each parameter inside the struct. */
    /* Release lock */
}

/* ============================================================================================== */

void opaque_obj_set_data(void* self, char data_id, uint8_t value)
{
    opaque_obj_t* op_obj = (opaque_obj_t*)self;
    /* Here you may disable interrupts to lock access to memory for write op. */
    switch (data_id)
    {
        case 'a':
        {
            op_obj->data_a = value;
            break;
        }
        case 'b':
        {
            op_obj->data_b = value;
            break;
        }
        case 'c':
        {
            op_obj->data_c = value;
            break;
        }
        default:
        {
            break;
        }
    }
    /* Release lock */
}

/* ============================================================================================== */

uint8_t opaque_obj_get_data(void* self, char data_id)
{
    opaque_obj_t* op_obj = (opaque_obj_t*)self;
    switch (data_id)
    {
        case 'a':
        {
            return op_obj->data_a;
        }
        case 'b':
        {
            return op_obj->data_b;
        }
        case 'c':
        {
            return op_obj->data_c;
        }
        default:
        {
            return 0;
        }
    }
}

/* ============================================================================================== */
