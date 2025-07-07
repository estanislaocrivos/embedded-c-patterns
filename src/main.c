#include "../inc/main.h"

/* ============================================================================================== */

int main(void)
{
    /* Object pattern */
    my_object_t object;
    object_init(&object);
    object.print_something(&object);
    uint8_t index = 0;
    uint8_t value = 255;
    object.set_data_value(&object, index, value);
    printf("Object data @ [%d] = %d\n", index, value);
    return 0;
}

/* ============================================================================================== */
