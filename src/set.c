#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "util.h"
#include "list.h"

typedef struct PrimeNode PrimeNode;

struct PrimeNode {
    unsigned long value;
    List *children;
};

PrimeNode *pnode_create(unsigned long value) {
    PrimeNode *node = calloc(1, sizeof(PrimeNode));
    node->value = value;
    node->children = list_create();
    return node;
}

void pnode_destroy(PrimeNode *node) {
}

unsigned long pnode_get_value(PrimeNode *node) {
    return node->value;
}

void pnode_add_child(PrimeNode *node, PrimeNode *child) {
    list_add(node->children, child);
}

PrimeNode *pnode_get_child(PrimeNode *node, unsigned long value) {
    for (size_t i=0; i<list_count(node->children); i++) {
        PrimeNode *child = list_get(node->children, i);
        if (child->value == value)
            return child;
    }

    return NULL;
}


void pnode_test_get_value() {
    PrimeNode *node = pnode_create(3);
    assert(pnode_get_value(node) == 3);
    pnode_destroy(node);
}

void pnode_test_add_child() {
    PrimeNode *node = pnode_create(0);

    PrimeNode *child = pnode_create(1);
    pnode_add_child(node, child);
    assert(pnode_get_child(node, 1) == child);

    pnode_destroy(node);
}

void pnode_test() {
    pnode_test_get_value();
    pnode_test_add_child();
}


typedef struct Set Set;

struct Set {
    PrimeNode *root;
};

Set *set_create() {
    Set *set = calloc(1, sizeof(Set));
    set->root = pnode_create(0);
    return set;
}

void set_add(Set *set, long value) {
}

bool set_has(Set *set, long value) {
    return false;
}

void set_destroy(Set *set) {
    freen(set);
}


void set_test() {
    /*
    pnode_test();

    Set *set = set_create();
    set_add(set, 3);
    assert(set_has(set, 3) == true);
    assert(set_has(set, 1) == false);
    set_destroy(set);
    */
}
