#ifndef OPAQUE_H
#define OPAQUE_H

/* ============================================================================================== */

#include <stdint.h>

/* ============================================================================================== */

/**
 * @brief Get the opaque object size.
 * @return uint8_t Returns the object size for dynamic allocation on the stack (alloca()) or on the
 * heap (malloc()).
 * @note This function can be used as parameter for the alloca() function which allocates memory on
 * the stack for the object.
 */
uint8_t get_opaque_obj_size(void);

/* ============================================================================================== */

/**
 * @brief Creates a new opaque object by allocating memory on the heap.
 * @return struct opaque* Returns a pointer to the object. May be then initialized with the
 * apropriate function.
 */
struct opaque* opaque_obj_new(void);

/* ============================================================================================== */

/**
 * @brief Frees the allocated memory for the object on the heap.
 * @param self The pointer to the pointer of the object. Sets the pointer to NULL.
 */
void opaque_obj_free(struct opaque** self);

/* ============================================================================================== */

/**
 * @brief Initializes object members to 0.
 * @param self The pointer to the object.
 */
void opaque_obj_init(void* self);

/* ============================================================================================== */

/**
 * @brief Writes to an object's attribute.
 * @param self The pointer to the object.
 * @param data_id The data field identifier.
 * @param value The value to be written in the data field.
 */
void opaque_obj_set_data(void* self, char data_id, uint8_t value);

/* ============================================================================================== */

/**
 * @brief Reads an object's attribute.
 * @param self The pointer to the object.
 * @param data_id The data field identifier.
 * @return The data value.
 */
uint8_t opaque_obj_get_data(void* self, char data_id);

/* ============================================================================================== */

#endif
