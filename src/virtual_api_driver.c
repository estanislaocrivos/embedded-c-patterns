#include "virtual_api_driver.h"
#include <_string.h>
#include <stdint.h>

/* ============================================================================================== */

static void stm32_init(void* self)
{
    stm32_uart_t* obj = (stm32_uart_t*)self;

    /* UART hardware init. implementation */
    uint32_t baudrate = obj->uart_config->baudrate;
    uint8_t  port     = obj->uart_config->port;
    printf("Initializing STM32 UART @ baudrate %d, port %d...\n", baudrate, port);
}

/* ============================================================================================== */

static uint8_t stm32_read(void* self, uint8_t* buf, size_t len)
{
    stm32_uart_t* obj = (stm32_uart_t*)self;

    /* UART hardware read implementation */
    printf("Reading from STM32 UART...\n");
    return 0;
}

/* ============================================================================================== */

static uint8_t stm32_write(void* self, const uint8_t* buf, size_t len)
{
    stm32_uart_t* obj = (stm32_uart_t*)self;

    /* UART hardware write implementation */
    printf("Writing to STM32 UART...\n");
    return 0;
}

/* ============================================================================================== */

/* Set the common API methods. All API methods must point to an implementation */
static const serial_t stm32_uart_api
    = {.init = stm32_init, .read = stm32_read, .write = stm32_write};

/* ============================================================================================== */

void stm32_uart_construct(stm32_uart_t* self, stm32_uart_config_t* config)
{
    memset(self, 0, sizeof(*self));
    self->api         = stm32_uart_api;  // Assign the api methods to the driver methods
    self->uart_config = config;
}

/* ============================================================================================== */
