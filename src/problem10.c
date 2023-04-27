#include <stdio.h>

#include "primes.c"

Primes primes;

int main() {
    primes_init(&primes);
    long largest_prime = 1;

    long sum = 0;
    for (long n=2; n<2e6; n++) {
        if (is_prime(&primes, n)) {
            primes_add(&primes, n);
            sum = sum + n;
        }
    }

    printf("%li\n", sum);

    return 0;
}
