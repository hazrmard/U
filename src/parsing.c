#include <stdio.h>
#include "helpers.h"
#include "parsing.h"

UBuffer WHITESPACE = {.buff=(u_int32_t[26]){9,10,11,12,13,32,133,160,5760,8192,8193,8194,
                8195,8196,8197,8198,8199,8200,8201,8202,8232,8233,8239,8287,12288},
                .sz=25};

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
