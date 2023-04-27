#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX 10001

typedef struct Primes {
    size_t values[MAX];
    size_t length;
} Primes;

void primes_init(Primes *primes) {
    memset(primes, 0, MAX);
    primes->length = 0;
}

void primes_add(Primes *primes, size_t prime) {
    primes->values[primes->length++] = prime;
}

bool is_prime(Primes primes, size_t n) {
    for (size_t i=0; i<primes.length; i++) {
        size_t prime = primes.values[i];

        if (prime*prime > n) {
            return true;
        }

        if (n % prime == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    Primes primes;
    primes_init(&primes);
    primes_add(&primes, 2);

    size_t n = 3;
    while (primes.length < MAX) {
        if (is_prime(primes, n)) {
            primes_add(&primes, n);
        }
        n++;
    }

    printf("10 001st prime: %li\n", primes.values[MAX-1]);

    return 0;
}
