#ifndef ERRNO_H
#define ERRNO_H

/* ============================================================================================== */

/* These error codes must be returned in their negative form (-<error_code>) */

/* Error codes */
#define EACCESS 1 /* Permission denied */
#define EIO     2 /* Input/output error */
#define ENOENT  3 /* Resource not found */
#define EAGAIN  4 /* Resource temporarily unavailable */
#define EBUSY   5 /* Device or resource busy */
#define EINVAL  6 /* Invalid argument */

/* ============================================================================================== */

#endif
