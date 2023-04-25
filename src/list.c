#include <assert.h>
#include <stdlib.h>

#include "util.c"

typedef struct List List;

struct List {
    void **items;
    size_t items_count;
    size_t items_size;
};

List *list_create() {
    List *list = calloc(1, sizeof(List));
    list->items = calloc(1, sizeof(void*));
    list->items_count = 0;
    list->items_size = sizeof(void*);
    return list;
}

void list_destroy(List *list) {
    freen(list->items);
    freen(list);
}

void list_add(List *list, void *item) {
    size_t space_required = (list->items_count + 1) * sizeof(void*);
    if (space_required > list->items_size) {
        size_t new_size = list->items_size * 2;
        list->items = realloc(list->items, new_size);
        list->items_size = new_size;
    }

    list->items[list->items_count++] = item;
}

void *list_get(List *list, size_t index) {
    return list->items[index];
}

size_t list_count(List *list) {
    return list->items_count;
}


void list_test_add_get() {
    List *list = list_create();
    list_add(list, "oh hi");
    assert(streq(list_get(list, 0), "oh hi"));
    list_destroy(list);
}

void list_test_add_twice() {
    List *list = list_create();
    list_add(list, "oh hi");
    list_add(list, ":D");
    assert(streq(list_get(list, 1), ":D"));
    list_destroy(list);
}

void list_test_iterate() {
    List *list = list_create();
    list_add(list, "oh hi");
    list_add(list, ":D");

    size_t count = 0;
    for (size_t i=0; i<list_count(list); i++)
        count++;
    assert(count == 2);

    list_destroy(list);
}

void list_test() {
    list_test_add_get();
    list_test_add_twice();
    list_test_iterate();
}
