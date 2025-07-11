#include "../inc/main.h"

/* ============================================================================================== */

void led_on_driver_x(void)
{
    printf("Setting the LED on, on device X...\n");
}

void led_off_driver_x(void)
{
    printf("Setting the LED off, on device X...\n");
}

void led_toggle_driver_x(void)
{
    printf("Toggling the LED, on device X...\n");
}

void led_on_driver_y(void)
{
    printf("Setting the LED on, on device Y...\n");
}

void led_off_driver_y(void)
{
    printf("Setting the LED off, on device Y...\n");
}

void led_toggle_driver_y(void)
{
    printf("Toggling the LED, on device Y...\n");
}

/* ============================================================================================== */

int main(void)
{
    /* ========================================================================================== */

    /* Object pattern */

    my_object_t object;
    object_init(&object);
    object.print_something(&object);
    uint8_t index = 0;
    uint8_t value = 255;
    object.set_data_value(&object, index, value);
    printf("Object data @ [%d] = %d\n", index, value);

    /* ========================================================================================== */

    /* Interface pattern */

    /* Dependency inversion principle applied through dependency injection. Here you can set the
     * drivers to be used for handling LEDs X and Y through the LED interface, common to all LEDs.
     * This allows polymorphism and higher abstraction/low coupling. */

    led_iface_t led_x;
    led_iface_init(&led_x, led_toggle_driver_x, led_on_driver_x, led_off_driver_x);

    led_iface_t led_y;
    led_iface_init(&led_y, led_toggle_driver_y, led_on_driver_y, led_off_driver_y);

    led_x.on();
    led_x.off();
    led_y.on();
    led_y.off();

    /* ========================================================================================== */

    /* Singleton pattern */

    singleton_init();
    singleton_set_data('a', 16);
    singleton_set_data('b', 32);
    singleton_set_data('c', 64);
    printf("Singleton object data 'a' = %d\n", singleton_get_data('a'));
    printf("Singleton object data 'b' = %d\n", singleton_get_data('b'));
    printf("Singleton object data 'c' = %d\n", singleton_get_data('c'));

    /* ========================================================================================== */

    /* Opaque pattern */

    /* Using alloca() for object allocation on stack. Create a pointer to struct and assign it to
     * the opaque object allocated on stack */
    struct opaque* op_object_1 = alloca(get_opaque_obj_size());
    opaque_obj_init(op_object_1);
    opaque_obj_set_data(op_object_1, 'a', 16);
    opaque_obj_set_data(op_object_1, 'b', 32);
    opaque_obj_set_data(op_object_1, 'c', 64);
    printf("Opaque object 1 data 'a' = %d\n", opaque_obj_get_data(op_object_1, 'a'));
    printf("Opaque object 1 data 'b' = %d\n", opaque_obj_get_data(op_object_1, 'b'));
    printf("Opaque object 1 data 'c' = %d\n", opaque_obj_get_data(op_object_1, 'c'));

    /* Using this pattern you can hide all struct. members but create many objects of the same kind
     */
    struct opaque* op_object_2 = alloca(get_opaque_obj_size());
    opaque_obj_init(op_object_2);
    opaque_obj_set_data(op_object_2, 'a', 2);
    opaque_obj_set_data(op_object_2, 'b', 4);
    opaque_obj_set_data(op_object_2, 'c', 8);
    printf("Opaque object 2 data 'a' = %d\n", opaque_obj_get_data(op_object_2, 'a'));
    printf("Opaque object 2 data 'b' = %d\n", opaque_obj_get_data(op_object_2, 'b'));
    printf("Opaque object 2 data 'c' = %d\n", opaque_obj_get_data(op_object_2, 'c'));

    /* Using new/free methods for object allocation on the heap (uses malloc() internally) */
    struct opaque* op_object = opaque_obj_new();
    opaque_obj_set_data(op_object, 'a', 1);
    opaque_obj_set_data(op_object, 'b', 2);
    opaque_obj_set_data(op_object, 'c', 4);
    printf("Opaque object data 'a' = %d\n", opaque_obj_get_data(op_object, 'a'));
    printf("Opaque object data 'b' = %d\n", opaque_obj_get_data(op_object, 'b'));
    printf("Opaque object data 'c' = %d\n", opaque_obj_get_data(op_object, 'c'));
    opaque_obj_free(&op_object); /* Needs ptr. to ptr. */

    /* ========================================================================================== */

    /* Factory pattern */

    shape_t* c = shape_create(SHAPE_CIRCLE);
    shape_t* r = shape_create(SHAPE_RECTANGLE);
    shape_draw(c);
    shape_draw(r);
    shape_destroy(c);
    shape_destroy(r);

    /* ========================================================================================== */

    return 0;
}

/* ============================================================================================== */
