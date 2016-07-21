#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"
#include "utf8.h"

// reads utf-8 encoded file into a UBuffer variable
unsigned long read_utf8_file(char* fname, UBuffer* b) {
    FILE* f = fopen(fname, "rb");
    unsigned long sz = file_size(f);
    char* buff = (char*) malloc(sz);
    b->buff = (u_int32_t*) calloc(sz+1, sizeof(u_int32_t)); //+1 for \0
    fread(buff, sizeof(u_int32_t), sz, f);
    fclose(f);
    u8_toucs(b->buff, sz, buff, sz);
    free(buff);
    reallocate(b);
    return sz;
}
