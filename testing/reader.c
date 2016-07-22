#include <stdio.h>
#include <stdlib.h>
#include "utf8.h"
#include "helpers.h"
#include "io.h"
#include "parsing.h"

int main(int argc, char* argv[]) {
    printf("This program tests Urdu reading:\n");
    UBuffer b;
    read_utf8_file("urdu.txt", &b);
    printf("Converted text:\n");
    int i=0;
    for (i=0; i<b.sz; i++) {
        printf("%u ", b.buff[i]);
    }
    printf("removing whitespace\n");
    remove_whitespace(&b);
    for (i=0; i<b.sz;i++){
        printf("%u ",b.buff[i]);
    }
    free(b.buff);
    return 0;
}
