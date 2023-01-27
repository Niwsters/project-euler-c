#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "util.h"

typedef struct Node Node;

Node *CHILD_NOT_FOUND = NULL;

struct Node {
    char key;
    void *value;
    Node **children;
    size_t child_count;
    size_t child_space;
};

Node *node_create(char key, void *value) {
    Node *node = calloc(1, sizeof(Node));
    node->key = key;
    node->value = value;
    node->children = NULL;
    node->child_count = 0;
    node->child_space = 0;
    return node;
}

void node_destroy(Node *node) {
    for (size_t i=0; i<node->child_count; i++) {
        node_destroy(node->children[i]);
    }

    freen(node->children);
    freen(node);
}

void node_add_child(Node *node, Node *child) {
    if (node->children == NULL) {
        node->children = calloc(1, sizeof(Node*));
        node->children[0] = child;
        node->child_count++;
        node->child_space = sizeof(Node*);
        return;
    }

    size_t size_required = (node->child_count + 1) * sizeof(Node*);
    size_t size_available = node->child_space;

    if (size_required > size_available) {
        size_t new_size = size_available * 2;
        node->children = realloc(node->children, new_size);
        node->child_space = new_size;
    }

    node->children[node->child_count++] = child;
}

Node *node_get_child(Node *node, char key) {
    for (int i=0; i<node->child_count; i++) {
        Node *child = node->children[i];
        if (child->key == key)
            return child;
    }
    
    return CHILD_NOT_FOUND;
}

void node_set_value(Node *node, void *value) {
    node->value = value;
}


void node_test_add_once() {
    Node *node = node_create('a', "blargh");
    Node *child = node_create('b', "honk");
    node_add_child(node, child);

    assert(node->children[0]->key == 'b');
    assert(streq(node->children[0]->value, "honk"));

    node_destroy(node);
}

void node_test_add_twice() {
    Node *node = node_create('a', "blargh");

    Node *child = node_create('b', "honk");
    node_add_child(node, child);

    Node *child2 = node_create('c', "oh hi");
    node_add_child(node, child2);

    assert(node->children[1]->key == 'c');

    node_destroy(node);
}

void node_test_get_node_by_key() {
    Node *node = node_create('a', "blargh");

    Node *child = node_create('b', "honk");
    node_add_child(node, child);

    Node *child2 = node_create('c', "oh hi");
    node_add_child(node, child2);

    assert(node->children[1]->key == 'c');

    Node *found = node_get_child(node, 'c');

    assert(found == child2);

    node_destroy(node);
}

void node_test_set_value() {
    Node *node = node_create('a', "oh hi");
    node_set_value(node, ":D");
    assert(streq(node->value, ":D"));
    node_destroy(node);
}

void node_test() {
    node_test_add_once();
    node_test_add_twice();
    node_test_get_node_by_key();
}


typedef struct Dict Dict;

struct Dict {
    Node *root;
};

Node *NODE_NOT_FOUND = NULL;
void *KEY_NOT_FOUND = NULL;

Dict *dict_create() {
    Dict *dict = calloc(1, sizeof(Dict));
    dict->root = node_create('\0', NULL);
    return dict;
}

void dict_destroy(Dict *dict) {
    node_destroy(dict->root);
    freen(dict);
}

Node *dict_get_node(Dict *dict, char *key) {
    int length = strlen(key);
    Node *node = dict->root;

    for (int i=0; i<length; i++) {
        char c = key[i];
        node = node_get_child(node, c);
        if (node == CHILD_NOT_FOUND)
            return NODE_NOT_FOUND;
    }

    return node;
}

void dict_set(Dict *dict, char *key, void *value) {
    int length = strlen(key);
    Node *node = dict->root;
    Node *child = NULL;
    for (int i=0; i<length; i++) {
        char c = key[i];
        child = node_get_child(node, c);
        if (child == CHILD_NOT_FOUND) {
            child = node_create(c, NULL);
            node_add_child(node, child);
        }
    }
    node_set_value(child, value);
}

void *dict_get(Dict *dict, char *key) {
    Node *node = dict_get_node(dict, key);

    if (node == NODE_NOT_FOUND)
        return KEY_NOT_FOUND;

    return node->value;
}

void dict_test_set_get() {
    Dict *dict = dict_create();
    dict_set(dict, "a", "b");
    assert(streq(dict_get(dict, "a"), "b"));
    dict_destroy(dict);
}

void dict_test_replace() {
    Dict *dict = dict_create();
    dict_set(dict, "a", "b");
    dict_set(dict, "a", "c");
    assert(streq(dict_get(dict, "a"), "c"));
    dict_destroy(dict);
}

void dict_test() {
    node_test();
    dict_test_set_get();
}
