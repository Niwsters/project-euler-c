#include <stdbool.h>

bool is_prime(long n) {
    for (int i=2; i <= n/2; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}

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
