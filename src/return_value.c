#include "../inc/return_value.h"

/* ============================================================================================== */

#include "../inc/errno.h"

/* ============================================================================================== */

int8_t generic_function(uint8_t some_parameter)
{
    switch (some_parameter)
    {
        case 0:
        {
            return -EACCESS;
        }
        case 1:
        {
            return -EIO;
        }
        case 2:
        {
            return -EBUSY;
        }
        case 3:
        {
            return -ENOENT;
        }
        case 4:
        {
            return -EAGAIN;
        }
        default:
        {
            return 0;
        }
    }
}

/* ============================================================================================== */
