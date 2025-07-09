#include "../inc/singleton.h"

/* ============================================================================================== */

#include <string.h>
#include <stdio.h>

/* ============================================================================================== */

/* In the singleton pattern the data structure is private. The API only exposes methods for
 * initializing, reading and writing data to the structure, but it cannot be accesed directly from
 * outside. */

typedef struct
{
    uint8_t data_a;
    uint8_t data_b;
    uint8_t data_c;
} singleton_obj_t;

/* Internal global struct. to mantain data */
static singleton_obj_t _singleton_object;

/* ============================================================================================== */

void singleton_init(void)
{
    /* Here you may disable interrupts to lock access to memory for write op. */
    memset(&_singleton_object, 0, sizeof(singleton_obj_t));
    /* Here you may set init. values for each parameter inside the struct. */
    /* Release lock */
}

/* ============================================================================================== */

void singleton_set_data(char data_id, uint8_t value)
{
    /* Here you may disable interrupts to lock access to memory for write op. */
    switch (data_id)
    {
        case 'a':
        {
            _singleton_object.data_a = value;
            break;
        }
        case 'b':
        {
            _singleton_object.data_b = value;
            break;
        }
        case 'c':
        {
            _singleton_object.data_c = value;
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

uint8_t singleton_get_data(char data_id)
{
    switch (data_id)
    {
        case 'a':
        {
            return _singleton_object.data_a;
        }
        case 'b':
        {
            return _singleton_object.data_b;
        }
        case 'c':
        {
            return _singleton_object.data_c;
        }
        default:
        {
            return 0;
        }
    }
}

/* ============================================================================================== */
