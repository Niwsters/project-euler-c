#include <stdio.h>

long count_divisors(long n) {
    long count = 1;
    for (long i=1; i<=n/2; i++) {
        if (n % i == 0)
            count++;
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
