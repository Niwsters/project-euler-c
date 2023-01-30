#include <stdio.h>
#include <math.h>

unsigned long count_divisors(unsigned long n) {
    long count = 0;
    for (long i=1; i<=sqrt(n); i++) {
        if (n % i == 0)
            count += 2;
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
        if (divisors > 500)
            return triangle;
    }

    return 0;
}
