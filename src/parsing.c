#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "helpers.h"
#include "parsing.h"

UBuffer WHITESPACE = {.buff=(u_int32_t[26]){9,10,11,12,13,32,133,160,5760,8192,8193,8194,
                8195,8196,8197,8198,8199,8200,8201,8202,8232,8233,8239,8287,12288,0},
                .sz=25};
//convert_stack_to_heap(WHITESPACE);
UBuffer COMMENT_CHAR = {.buff=(u_int32_t[2]){'#',0}, .sz=1};
//convert_stack_to_heap(&COMMENT_CHAR);
UBuffer NEWLINE_CHAR = {.buff=(u_int32_t[2]){'\n',0}, .sz=1};
//convert_stack_to_heap(&NEWLINE_CHAR);

// return the position in the buffer b after matching with target, 0 if no match
unsigned long skip_until(UBuffer* b, unsigned long curr_pos, UBuffer* target) {
    int i=0;    // index for target buffer
    while (curr_pos<=b->sz) {
        while ((b->buff[curr_pos]==target->buff[i])&&(i<target->sz)) {
            i++;
            curr_pos++;
        }
        if (i==target->sz) return curr_pos;
        i=0;
        curr_pos++;
    }
    return 0L;      // 0 means skipped until end, found nothing
}

// delete whitespace characters and resize buffer
void remove_whitespace(UBuffer* b) {
    u_int32_t* x = b->buff;
    u_int32_t* y = b->buff;
    unsigned long i=0;
    while (i<b->sz) {
        if (!contains(&WHITESPACE, *y, 0)) {
            *x = *y;
            x++;
        }
        y++;
        i++;
    }
    *x = 0;     // last UBuffer element is 0 by convention
    reallocate(b);
}

// remove trailing and leading whitespace as defined by WHITESPACE
void strip(UBuffer* b) {
    unsigned long i, j;
    i = skip_all(b, 0, &WHITESPACE);
    j = b->sz-1;
    while (contains(&WHITESPACE, b->buff[j], 0) && j>=0) {
        j--;
    }
    b->sz = j - i + 1;
    b->buff = memmove(b->buff, b->buff+i, i*sizeof(u_int32_t)); // leading
    b->buff = realloc(b->buff, (b->sz+1)*sizeof(u_int32_t));    // trailing
    b->buff[b->sz] = 0;
}

// skip all characters contained in target from current pos
unsigned long skip_all(UBuffer* b, unsigned long curr_pos, UBuffer* target) {
    while (contains(target, b->buff[curr_pos], 0) && curr_pos<b->sz) {
        curr_pos++;
    }
    return curr_pos;
}

// determine number of non comment lines
unsigned long count_lines(UBuffer* b) {
    unsigned long i=0;
    unsigned long lines = 0;
    while (i<b->sz) {
        if (contains(&WHITESPACE, b->buff[i], 0)) {
            i = skip_all(b, i, &WHITESPACE);
        } else if (b->buff[i]==COMMENT_CHAR.buff[0]) {
            i = skip_until(b, i, &NEWLINE_CHAR);
        } else {
            lines++;
            i = skip_until(b, i, &NEWLINE_CHAR);
        }
    }
    return lines;
}
