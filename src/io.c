#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"

// reads utf-8 encoded file into a UBuffer variable
unsigned long read_utf8_file(char* fname, UBuffer* b) {
    FILE* f = fopen(fname, "rb");
    unsigned long sz = file_size(f);
    char* buff = (char*) malloc(sz);
    fread(buff, sizeof(u_int32_t), sz, f);
    fclose(f);
    to_unicode(buff, sz, b);
    free(buff);
    return sz;
}
