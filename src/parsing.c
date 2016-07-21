#include <stdio.h>
#include "helpers.h"


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
