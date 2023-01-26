#include "primes.h"

long problem7() {
    int count = 0;
    int n = 1;
    while (count < 10001) {
        n++;

        if (is_prime(n))
            count++;
    }

    return n;
}
