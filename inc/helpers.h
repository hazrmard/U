/* This file includes functions to help with miscellaneous utility functions.
*/

# ifndef HELPERS_H
# define HELPERS_H

# include "utf8.h"

typedef struct {
    long int sz;
    u_int32_t* buff;
} UBuffer;

// returns file size in bytes
long int file_size(FILE *f);

// reallocate buffer to only contain non-NULL
UBuffer reallocate(u_int32_t* buff);


# endif
