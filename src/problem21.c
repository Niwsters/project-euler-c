#include <math.h>
#include <stdint.h>
#include <stdio.h>

uint64_t sum_divisors(unsigned long n) {
    uint64_t sum = 0;
    for (uint64_t i=2; i<=sqrt(n); i++) {
        if (n % i == 0) {
            sum = sum + i + n/i;
        }
    }
    return sum + 1;
}

int main() {
    int32_t checked[10000];
    for (int i=0; i<10000; i++) {
        checked[i] = 0;
    }

    uint64_t sum = 0;
    for (uint64_t a=1; a<10000; a++) {
        uint64_t b = sum_divisors(a);

        if (a == sum_divisors(b) && a != b && checked[a] == 0) {
            sum = sum + a + b;
        }

        if (a < 10000) {
            checked[a] = 1;
        }

        if (b < 10000) {
            checked[b] = 1;
        }
    }

    printf("%lu\n", sum);

    return 0;
}
