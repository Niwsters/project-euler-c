#ifndef PRIMES_H
#define PRIMES_H

#include <stdbool.h>

#include "list.h"

bool is_prime(long n);
void primes_test();
List *primes_find_factors(unsigned long n);

#endif
