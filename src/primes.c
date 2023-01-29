#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>

#include "util.h"

bool INITIALIZED = false;

typedef struct Prime Prime;

struct Prime {
    Prime *next;
    unsigned long value;
};

Prime *prime_create(unsigned long value) {
    Prime *prime = calloc(1, sizeof(Prime));
    prime->next = NULL;
    prime->value = value;
    return prime;
}

void prime_destroy(Prime *prime) {
    Prime *child = prime->next;
    while (child != NULL) {
        Prime *next = child->next;
        freen(child);
        child = next;
    }
    freen(prime);
}



typedef struct Primes Primes;

Primes *FOUND_PRIMES;

struct Primes {
    Prime *root;
    Prime *end;
};

void primes_destroy(Primes *primes) {
    prime_destroy(primes->root);
    freen(primes);
}

Primes *primes_create() {
    Primes *primes = calloc(1, sizeof(Primes));
    primes->root = prime_create(2);
    primes->end = primes->root;
    return primes;
}

void primes_add(Primes *primes, unsigned int n) {
    Prime *prime = prime_create(n);
    primes->end->next = prime;
    primes->end = prime;
}

void primes_exit() {
    primes_destroy(FOUND_PRIMES);
}

void primes_ensure_init() {
    if (!INITIALIZED) {
        FOUND_PRIMES = primes_create();
        atexit(primes_exit);
        INITIALIZED = true;
    }
}

bool is_prime(long n) {
    primes_ensure_init();

    if (n == 2)
        return true;

    Prime *prime = FOUND_PRIMES->root;
    while (prime != NULL && pow(prime->value, 2) <= n) {
        if (n % prime->value == 0)
            return false;

        prime = prime->next;
    }

    primes_add(FOUND_PRIMES, n);

    return true;
}

void primes_test() {
    assert(is_prime(2) == true);
    assert(is_prime(3) == true);
    assert(is_prime(4) == false);
    assert(is_prime(5) == true);
    assert(is_prime(7) == true);
    assert(is_prime(11) == true);
    assert(is_prime(13) == true);
    assert(is_prime(17) == true);
    assert(is_prime(18) == false);
}
