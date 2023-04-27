#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>

#include "primes.c"

#define GOAL 10001

static Primes primes;

int main() {
    primes_init(&primes);
    primes_add(&primes, 2);

    size_t n = 3;
    while (primes.length < GOAL) {
        if (is_prime(&primes, n)) {
            primes_add(&primes, n);
        }

        n++;
    }

    printf("10 001st prime: %li\n", primes.values[GOAL-1]);

    return 0;
}
