#ifndef IO_H
#define IO_H

#include "helpers.h"

// read ray bytes from file and convert them to 4-byte wide integers
int read_utf8_file(char* fname, UBuffer* b);


#endif
