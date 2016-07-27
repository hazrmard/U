#ifndef IO_H
#define IO_H

#include "helpers.h"


#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

// read ray bytes from file and convert them to 4-byte wide integers
unsigned long read_utf8_file(char* fname, UBuffer* b);

// print codepoints of UBuffer with delimiter character in between
void print_codepoints(UBuffer* b, char delimiter);

// prints an error message in red color to stderr
void print_error(char* err);

#endif
