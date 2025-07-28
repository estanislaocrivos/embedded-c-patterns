#ifndef RETURN_VALUE_H
#define RETURN_VALUE_H

/* ============================================================================================== */

#include <stdint.h>

/* ============================================================================================== */

/* The return error pattern tries to standardize error codes across the different layers of the
 * system. According to this pattern, a 0 will always respresent success, a negative value will
 * represent an error and in case a partial success must be notified, a positive value > 0 could be
 * returned. The errno.h file defines the error codes used in this pattern */

/**
 * @brief This function is an example of a generic function that returns different error codes
 * @param some_parameter A parameter that determines the return value
 * @return uint8_t Returns 0 for success, negative values for errors defined in errno.h, or a
 * positive value for partial success (not used in this example).
 */
int8_t generic_function(uint8_t some_parameter);

/* ============================================================================================== */

#endif
