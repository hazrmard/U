#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"
#include "io.h"

// reads utf-8 encoded file into a UBuffer variable
unsigned long read_utf8_file(char* fname, UBuffer* b) {
    FILE* f = fopen(fname, "rb");
    if (!f) {
        return 0;
    }
    unsigned long sz = file_size(f);
    char* buff = (char*) malloc(sz);
    fread(buff, sizeof(u_int32_t), sz, f);
    fclose(f);
    to_unicode(buff, sz, b);
    free(buff);
    return sz;
}

// print codepoints of UBuffer with delimiter character in between
void print_codepoints(UBuffer* b, char delimiter) {
    int i=0;
    while (i<b->sz) {
        printf("%u%c", b->buff[i], delimiter);
        i++;
    }
}

// prints an error message in red color to stderr
void print_error(char* err) {
    fprintf(stderr, RED "%s\n" RESET, err);
}
