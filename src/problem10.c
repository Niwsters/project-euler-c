#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "primes.h"

long problem10() {
    long largest_prime = 1;

    long sum = 0;
    for (long n=2; n<2e6; n++) {
        if (is_prime(n))
            sum = sum + n;
    }

    return sum;
}
