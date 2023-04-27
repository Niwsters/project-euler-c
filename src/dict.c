#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "util.h"
#include "node.c"

typedef struct Dict Dict;

struct Dict {
    Node *root;
};

Dict *dict_create() {
    Dict *dict = calloc(1, sizeof(Dict));
    dict->root = node_create('\0', NULL);
    return dict;
}

void dict_destroy(Dict *dict) {
    node_destroy(dict->root);
    freen(dict);
}

void dict_set(Dict *dict, char *key, void *value) {
    int length = strlen(key);
    Node *node = dict->root;
    Node *child = NULL;
    for (int i=0; i<length; i++) {
        char c = key[i];
        child = node_get_child(node, c);
        if (child == NULL) {
            child = node_create(c, NULL);
            node_add_child(node, child);
        }
        node = child;
    }
    node_set_value(child, value);
}

void *dict_get(Dict *dict, char *key) {
    int length = strlen(key);
    Node *node = dict->root;

    for (int i=0; i<length; i++) {
        char c = key[i];
        node = node_get_child(node, c);
        if (node == NULL)
            return NULL;
    }

    return node_get_value(node);
}

void dict_test_set_get() {
    Dict *dict = dict_create();
    dict_set(dict, "blargh", "honk");
    assert(strcmp(dict_get(dict, "blargh"), "honk") == 0);
    dict_destroy(dict);
}

void dict_test_replace() {
    Dict *dict = dict_create();
    dict_set(dict, "blargh", "oh hi");
    dict_set(dict, "blargh", ":D");
    assert(strcmp(dict_get(dict, "blargh"), ":D") == 0);
    dict_destroy(dict);
}

void dict_test() {
    dict_test_set_get();
    dict_test_replace();
}
