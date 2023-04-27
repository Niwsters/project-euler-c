#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

#define MAX_PRIMES (size_t) 1e6

typedef struct Primes {
    size_t values[MAX_PRIMES];
    size_t length;
} Primes;

void primes_init(Primes *primes) {
    memset(primes, 0, MAX_PRIMES);
    primes->length = 0;
}

void primes_add(Primes *primes, size_t prime) {
    assert(primes->length < MAX_PRIMES);
    primes->values[primes->length++] = prime;
}

bool is_prime(Primes *primes, size_t n) {
    for (size_t i=0; i<primes->length; i++) {
        size_t prime = primes->values[i];

        if (prime*prime > n) {
            return true;
        }

        if (n % prime == 0) {
            return false;
        }
    }

    return true;
}
