#include <stdio.h>

#include "primes.h"

unsigned long count_divisors(unsigned long n) {
    List *factors = primes_find_factors(n);

    unsigned long count = 0;
    while (n > 1) {
        for (size_t i=0; i<list_count(factors); i++) {
            unsigned long prime = (unsigned long) list_get(factors, i);
            if (n % prime == 0) {
                count++;
                n = n / prime;
            }
        }
    }
    return count;
}

long problem12() {
    long triangle = 0;
    long divisors = 0;
    long i = 1;
    while (divisors < 500) {
        triangle += i++;
        divisors = count_divisors(triangle);
        printf("%li %li\n", triangle, divisors);
        if (divisors > 500)
            return triangle;
    }

    return 0;
}
