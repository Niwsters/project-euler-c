#ifndef NODE_H
#define NODE_H

typedef struct Node Node;

Node *node_create(char key, void *value);
void node_destroy(Node *node);
void node_add_child(Node *node, Node *child);
Node *node_get_child(Node *node, char key);
void node_set_value(Node *node, void *value);
void *node_get_value(Node *node);
char node_get_key(Node *node);

void node_test();

#endif
