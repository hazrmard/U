#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utf8.h"
#include "helpers.h"

// return size of file in bytes
unsigned long file_size(FILE *f) {
    unsigned long curr_pos = ftell(f);
    fseek(f, 0L, SEEK_END);
    unsigned long sz = ftell(f);
    fseek(f, curr_pos, SEEK_SET);
    return sz;
}

// reallocate utf8 buffer to only contain non-NULL
int reallocate(UBuffer* b) {
    unsigned long i=0;
    u_int32_t* original = b->buff;
    while (*b->buff != 0) {
        b->buff++;
        i++;
    }
    b->sz = i;
    b->buff = realloc(original, sizeof(*original)*i+1); //+1 for ending \0
    if (b->buff) return 1;
    return 0;
}

// convert string to unicode codepoints and return pointer to UBuffer object
void to_unicode(char* src, unsigned long sz, UBuffer* dest) {
    dest->buff = (u_int32_t*) calloc(sz+1, sizeof(u_int32_t)); //+1 for \0
    u8_toucs(dest->buff, sz+1, src, sz);
    reallocate(dest);
}

// check if character is in UBuffer
int contains(UBuffer* b, u_int32_t c, unsigned long start) {
    int i;
    for (i=start; i<b->sz; i++) {
        if (c==b->buff[i]) return 1;
    }
    return 0;
}

// converts stack memory into heap for UBuffer instance
int convert_stack_to_heap(UBuffer* b) {
    u_int32_t* buff = malloc(sizeof(u_int32_t)*(b->sz+1));
    if (!buff) return 0;    // memory allocation error
    b->buff = memcpy(buff, b->buff, sizeof(u_int32_t)*(b->sz+1));
    if (!b->buff) return 0;
    return 1;
}

// check if two UBuffer instances are equal
int is_equal(UBuffer* a, UBuffer* b) {
    if (a->sz!=b->sz) return 0;
    unsigned long i=0;
    while (i<a->sz) {
        if (a->buff[i]!=b->buff[i]) return 0;
        i++;
    }
    return 1;
}
