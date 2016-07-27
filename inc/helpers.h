/* This file includes functions to help with miscellaneous utility functions.
*/

#ifndef HELPERS_H
#define HELPERS_H

#include "utf8.h"

// stores unicode code points. By convention last element is 0
// sz is # of elements excluding ending 0
// buffer must be malloc()-ed or use convert_stack_to_heap()
typedef struct {
    unsigned long sz;
    u_int32_t* buff;
} UBuffer;

// returns file size in bytes
unsigned long file_size(FILE *f);

// reallocate buffer to only contain non-NULL
void reallocate(UBuffer* b);

// convert string to unicode codepoints and return pointer to UBuffer object
void to_unicode(char* src, unsigned long sz, UBuffer* dest);

// check if character is in UBuffer
int contains(UBuffer* b, u_int32_t c, unsigned long start);

// converts stack memory into heap for UBuffer instance
int convert_stack_to_heap(UBuffer* b);

// check if two UBuffer instances are equal
int is_equal(UBuffer* a, UBuffer* b);

#endif
