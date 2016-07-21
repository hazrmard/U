#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include "utf8.h"
#include "helpers.h"
#include "io.h"
#include "parsing.h"

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "");
    printf("This program tests Urdu reading:\n");
    UBuffer b;
    long int sz = read_utf8_file("urdu.txt", &b);
    printf("Converted text:\n");
    int i=0;
    for (i=0; i<b.sz; i++) {
        printf("%C", b.buff[i]);
    }
    free(b.buff);
    return 0;
}
