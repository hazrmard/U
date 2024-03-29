/* some functions to facilitate parsing of unicode buffer of type UBuffer */
#ifndef PARSING_H
#define PARSING_H

#include "helpers.h"

extern UBuffer COMMENT_CHAR;
extern UBuffer NEWLINE_CHAR;
extern UBuffer WHITESPACE;
extern UBuffer* ALPHABET;
extern UBuffer* NATIVE;

// return the position in the buffer b after matching with target, 0 if no match
unsigned long skip_until(UBuffer* b, unsigned long curr_pos, UBuffer* target);

// return index of target's starting position in UBuffer
unsigned long find(UBuffer* b, unsigned long curr_pos, UBuffer* target);

// delete whitespace characters and resize buffer
void remove_whitespace(UBuffer* b);

// remove trailing and leading whitespace as defined by WHITESPACE
void strip(UBuffer* b);

// skip all characters contained in target from current pos
unsigned long skip_all(UBuffer* b, unsigned long curr_pos, UBuffer* target);

// determine number of non comment lines
unsigned long count_lines(UBuffer* b);

#endif
