#include "../inc/interface.h"

/* ============================================================================================== */

#include <string.h>

/* ============================================================================================== */

void led_iface_init(led_iface_t* self,
                    led_toggle_t led_toggle_driver,
                    led_on_t     led_on_driver,
                    led_off_t    led_off_driver)
{
    memset(self, 0, sizeof(*self));
    self->toggle = led_toggle_driver;
    self->on     = led_on_driver;
    self->off    = led_off_driver;
}

/* ============================================================================================== */
