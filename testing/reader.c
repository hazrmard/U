#include <stdio.h>
#include <stdlib.h>
#include "utf8.h"
#include "helpers.h"
#include "io.h"
#include "parsing.h"

int main(int argc, char* argv[]) {
    printf("This program tests Urdu reading:\n");
    printf("\n=== Basic diagnostics ===\n");
    printf("Size of UBuffer:\t" CYAN "%d bytes\n" RESET, (int) sizeof(UBuffer));
    printf("Size of codepoint:\t" CYAN "%d bytes\n" RESET, (int) sizeof(u_int32_t));
// =========================================================
    printf("\n=== IO ===\n");
    print_error("Standard error message.");
    UBuffer b;
    if (read_utf8_file("urdu.txt", &b)) {
        printf("File read:\t\t\t" GREEN "SUCCESS" RESET "\n");
        free(b.buff);
    } else {
        printf("File read:\t\t\t" RED "FAILURE" RESET "\n");
    }

    b.buff = (u_int32_t[21]) {' ',' ','i','b','r','a','h','i','m',' ','\t','\n',
                                'r','o','c','k','s','!',' ','\n',0};
    b.sz = 20;
    if (convert_stack_to_heap(&b))  {
        printf("UBuffer heap allocation:\t" GREEN "SUCCESS" RESET "\n");
        //free(b.buff);
    } else {
        printf("UBuffer heap allocation:\t" RED "FAILURE" RESET "\n");
    }
// =========================================================
    printf("\n=== Parsing ===\n");
    UBuffer c, d;
    c.buff = (u_int32_t[21]) {' ',' ','i','b','r','a','h','i','m',' ','\t','\n',
                                'r','o','c','k','s','!',' ','\n',0};
    c.sz = 20;
    convert_stack_to_heap(&c);
    d.buff = (u_int32_t[21]) {' ',' ','i','b','r','a','h','i','m',' ','\t','\n',
                                'r','o','c','k','s','!',' ','\t',0};
    c.sz = 20;
    convert_stack_to_heap(&d);

    if (is_equal(&b,&c) && !is_equal(&b,&d))  {
        printf("Equality check:\t\t\t" GREEN "SUCCESS" RESET "\n");
        //free(b.buff);
    } else {
        printf("Equality check:\t\t\t" RED "FAILURE" RESET "\n");
    }

    free(b.buff);
    free(c.buff);
    free(d.buff);
    return 0;
}
