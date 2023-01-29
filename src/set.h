#ifndef SET_H
#define SET_H

typedef struct Set Set;

Set *set_create();
void set_add(Set *set, char *value);
bool set_has(Set *set, char *value);
void set_destroy(Set *set);

void set_test();

#endif
