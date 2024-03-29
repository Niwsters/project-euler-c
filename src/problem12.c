#include <math.h>
#include <stdio.h>

unsigned long count_divisors(unsigned long n) {
    unsigned long count = 0;
    for (unsigned long i=1; i<=sqrt(n); i++) {
        if (n % i == 0)
            count += 2;
    }

    return count;
}

int main() {
    long triangle = 0;
    long divisors = 0;
    long i = 1;
    while (divisors < 500) {
        triangle += i++;
        divisors = count_divisors(triangle);
    }

    printf("%li\n", triangle);
}
