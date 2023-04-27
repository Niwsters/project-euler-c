#include <stdio.h>

long next_prime(long n) {
    int i;
    for (i=3; i < n/2; i++) {
        if (n % i == 0 || n == i)
            return i;
    }

    return n;
}

long problem3() {
    long n = 600851475143;
    long largest_prime = 1;
    while (n != 1) {
        long prime = next_prime(n);
        n = n / prime;
        largest_prime = prime;
    }

    return largest_prime;
}

int main() {
    printf("%li\n", problem3());
    return 0;
}
