#include <stdlib.h>

#ifndef freen
#define freen(x) { while (x) { free(x); x = NULL; } }
#endif
