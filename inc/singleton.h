#ifndef SINGLETON_H
#define SINGLETON_H

/* ============================================================================================== */

#include <stdint.h>

/* ============================================================================================== */

/**
 * @brief Initializes the singleton object.
 */
void singleton_init(void);

/* ============================================================================================== */

/**
 * @brief Sets the data for the singleton object.
 * @param data_id Identifier for the data to be set.
 * @param value Value to be set for the specified data_id.
 */
void singleton_set_data(char data_id, uint8_t value);

/* ============================================================================================== */

/**
 * @brief Gets the data from the singleton object.
 * @param data_id Identifier for the data to be retrieved.
 * @return The value associated with the specified data_id.
 */
uint8_t singleton_get_data(char data_id);

/* ============================================================================================== */

#endif
