/* This file includes functions to help with miscellaneous utility functions.
*/

#ifndef HELPERS_H
#define HELPERS_H

#include "utf8.h"
#include <stdio.h>

typedef struct {
    unsigned long sz;
    u_int32_t* buff;
} UBuffer;

// returns file size in bytes
unsigned long file_size(FILE *f);

// reallocate buffer to only contain non-NULL
void reallocate(UBuffer* b);


#endif
