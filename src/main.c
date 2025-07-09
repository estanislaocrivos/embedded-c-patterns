#include "../inc/main.h"
#include <stdio.h>
#include "singleton.h"

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
    printf("Singleton data 'a' = %d\n", singleton_get_data('a'));
    printf("Singleton data 'b' = %d\n", singleton_get_data('b'));
    printf("Singleton data 'c' = %d\n", singleton_get_data('c'));

    /* ========================================================================================== */

    return 0;
}

/* ============================================================================================== */
