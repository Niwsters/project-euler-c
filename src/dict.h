#include <stdlib.h>

void dict_test();
typedef struct Dict Dict;
Dict *dict_create();
void dict_set(Dict *dict, char *key, void *value);
void *dict_get(Dict *dict, char *key);
void dict_destroy(Dict *dict);
