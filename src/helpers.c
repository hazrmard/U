#include <stdio.h>
#include <stdlib.h>
#include "utf8.h"
#include "helpers.h"

// return size of file in bytes
long int file_size(FILE *f) {
    long int curr_pos = ftell(f);
    fseek(f, 0L, SEEK_END);
    long int sz = ftell(f);
    fseek(f, curr_pos, SEEK_SET);
    return sz;
}

// reallocate utf8 buffer to only contain non-NULL
void reallocate(UBuffer* b) {
    long int i=0;
    u_int32_t* original = b->buff;
    while (*b->buff != 0) {
        b->buff++;
        i++;
    }
    b->sz = i;
    b->buff = realloc(original, sizeof(*original)*i);
}
