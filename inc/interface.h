#ifndef HAL_H
#define HAL_H

/* ============================================================================================== */

#include <stdint.h>

/* ============================================================================================== */

typedef void (*led_toggle_t)(void);
typedef void (*led_on_t)(void);
typedef void (*led_off_t)(void);

typedef struct
{
    led_toggle_t toggle;
    led_on_t     on;
    led_off_t    off;
} led_iface_t;

/* ============================================================================================== */

void led_iface_init(led_iface_t* self,
                    led_toggle_t led_toggle_driver,
                    led_on_t     led_on_driver,
                    led_off_t    led_off_driver);

/* ============================================================================================== */

#endif
