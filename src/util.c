#include <stdlib.h>

void freen(void *x) {
    if (x != NULL) {
        free(x);
        x = NULL;
    }
}
