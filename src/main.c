#include "../inc/main.h"

int main(void)
{
    /* Object pattern */
    my_object_t object;
    object_init(&object);
    object.object_method();
    return 0;
}
