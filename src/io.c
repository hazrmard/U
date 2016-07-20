#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"
#include "utf8.h"

void read_utf8_file(char* fname, UBuffer* b) {
    FILE* f = fopen(fname, "rb");
    long int sz = file_size(f);
    char* buff = (char*) malloc(sz);
    b->buff = (u_int32_t*) malloc(sz*4);
    fread(buff, sizeof(u_int32_t), sz, f);
    fclose(f);
    u8_toucs(b->buff, sz, buff, sz);
    free(buff);
    reallocate(b);
}
