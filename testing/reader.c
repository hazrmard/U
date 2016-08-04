#include <stdio.h>
#include <stdlib.h>
#include "utf8.h"
#include "helpers.h"
#include "io.h"
#include "parsing.h"
#include <wchar.h>

int main(int argc, char* argv[]) {
    printf("This program tests Urdu reading:\n");
    printf("\n=== Basic diagnostics ===\n");
    printf("Size of UBuffer:\t" CYAN "%d bytes\n" RESET, (int) sizeof(UBuffer));
    printf("Size of codepoint:\t" CYAN "%d bytes\n" RESET, (int) sizeof(u_int32_t));
// =========================================================
    printf("\n=== IO ===\n");
    print_error("Standard error message.");
    UBuffer a, b;
    if (read_utf8_file("urdu.txt", &a)) {
        printf("File read:\t\t\t" GREEN "SUCCESS" RESET "\n");
    } else {
        printf("File read:\t\t\t" RED "FAILURE" RESET "\n");
    }

    b.buff = (u_int32_t[21])   {' ',' ','i','b','r','a','h','i','m',' ','\t','\n',
                                'r','o','c','k','s','!',' ','\n',0};
    b.sz = 20;
    if (convert_stack_to_heap(&b))  {
        printf("UBuffer heap allocation:\t" GREEN "SUCCESS" RESET "\n");
    } else {
        printf("UBuffer heap allocation:\t" RED "FAILURE" RESET "\n");
    }
// =========================================================
    printf("\n=== Utilities ===\n");
    UBuffer c, d, e;
    c.buff = (u_int32_t[21]) {' ',' ','i','b','r','a','h','i','m',' ','\t','\n',
                                'r','o','c','k','s','!',' ','\n',0};
    c.sz = 20;
    convert_stack_to_heap(&c);
    d.buff = (u_int32_t[14]) {'i','b','r','a','h','i','m',
                                'r','o','c','k','s','!',0};
    d.sz = 13;
    convert_stack_to_heap(&d);
    e.buff = (u_int32_t[4]) {'c','k','s',0};
    e.sz = 3;
    convert_stack_to_heap(&e);

    if (is_equal(&b,&c) && !is_equal(&b,&d))  {
        printf("Equality check:\t\t\t" GREEN "SUCCESS" RESET "\n");
    } else {
        printf("Equality check:\t\t\t" RED "FAILURE" RESET "\n");
    }

    if (contains(&b, (u_int32_t) 'c', 0) && !contains(&b, (u_int32_t) 'c', 17)) {
        printf("Membership test:\t\t" GREEN "SUCCESS" RESET "\n");
    } else {
        printf("Membership test:\t\t" RED "FAILURE" RESET "\n");
    }

    free(c.buff);
    c.buff = (u_int32_t[24]) {' ',' ','i','b','r','a','h','i','m',' ','\t','\n',
                                'r','o','c','k','s','!',' ','\n',0,0,0,0};
    c.sz = 23;
    convert_stack_to_heap(&c);
    if (reallocate(&c) && is_equal(&c, &b)) {
        printf("Reallocation test:\t\t" GREEN "SUCCESS" RESET "\n");
    } else {
        printf("Reallocation test:\t\t" RED "FAILURE" RESET "\n");
    }

    char str[] = "  ibrahim \t\nrocks! \n";
    free(c.buff);
    to_unicode(str, 21, &c);
    if (is_equal(&c,&b)) {
        printf("Unicode conversion:\t\t" GREEN "SUCCESS" RESET "\n");
    } else {
        printf("Unicode conversion:\t\t" RED "FAILURE" RESET "\n");
    }


// =========================================================
    printf("\n=== Parsing ===\n");


    free(a.buff);
    free(b.buff);
    free(c.buff);
    free(d.buff);
    free(e.buff);
    // free(WHITESPACE.buff);
    // free(NEWLINE_CHAR.buff);
    // free(COMMENT_CHAR.buff);
    return 0;
}
