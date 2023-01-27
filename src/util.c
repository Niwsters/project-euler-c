#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void freen(void *x) {
    if (x != NULL) {
        free(x);
        x = NULL;
    }
}

bool streq(char *a, char *b) {
    if (a == NULL || b == NULL)
        return false;

    return strcmp(a, b) == 0;
}
