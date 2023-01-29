#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

void list_test();

typedef struct List List;
List *list_create();
void list_destroy(List *list);
void list_add(List *list, void *item);
void *list_get(List *list, size_t index);
size_t list_count(List *list);

#endif
