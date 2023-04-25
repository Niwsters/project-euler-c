#include <stdio.h>
#include <string.h>

#define count_t unsigned long 
#define n_t unsigned long
#define SIZE 1000000
#define LIMIT 1000000

n_t collatz(n_t n, count_t counts[SIZE]) {
    n_t count = 1;
    while (n != 1) {
        if (n < SIZE && counts[n] > 0) {
            return count + counts[n];
        }

        if (n % 2 == 0) {
            n = n/2;
        } else {
            n = 3*n+1;
        }

        count++;
    }

    return count;
}

typedef struct Largest {
    count_t count;
    n_t n;
} Largest;

count_t counts[SIZE];
int main() {
    memset(counts, 0, SIZE);
    Largest largest = { 1, 1 };

    for (n_t n=LIMIT/2; n<LIMIT; n++) {
        count_t count = collatz(n, counts);
        counts[n] = count;
        if (count > largest.count)
            largest = (Largest) { count, n };
    }

    printf("%li\n", largest.n);

    return 0;
}
