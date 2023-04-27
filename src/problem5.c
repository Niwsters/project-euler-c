#include <math.h>
#include <stdio.h>

typedef struct {
    int twos;
    int threes;
    int fives;
    int sevens;
    int elevens;
    int thirteens;
    int seventeens;
    int nineteens;
} Primes;

void find_primes(int n, Primes *primes) {
    int twos = 0;
    int threes = 0;
    int fives = 0;
    int sevens = 0;
    int elevens = 0;
    int thirteens = 0;
    int seventeens = 0;
    int nineteens = 0;

    while (n > 1) {
        if (n % 2 == 0) {
            twos++;
            n = n / 2;
        }

        if (n % 3 == 0) {
            threes++;
            n = n / 3;
        }

        if (n % 5 == 0) {
            fives++;
            n = n / 5;
        }

        if (n % 7 == 0) {
            sevens++;
            n = n / 7;
        }

        if (n % 11 == 0) {
            elevens++;
            n = n / 11;
        }

        if (n % 13 == 0) {
            thirteens++;
            n = n / 13;
        }

        if (n % 17 == 0) {
            seventeens++;
            n = n / 17;
        }

        if (n % 19 == 0) {
            nineteens++;
            n = n / 19;
        }
    }

    if (twos > primes->twos)
        primes->twos = twos;

    if (threes > primes->threes)
        primes->threes = threes;

    if (fives > primes->fives)
        primes->fives = fives;

    if (sevens > primes->sevens)
        primes->sevens = sevens;

    if (elevens > primes->elevens)
        primes->elevens = elevens;

    if (thirteens > primes->thirteens)
        primes->thirteens = thirteens;

    if (seventeens > primes->seventeens)
        primes->seventeens = seventeens;

    if (nineteens > primes->nineteens)
        primes->nineteens = nineteens;
}

long problem5() {
    Primes primes = { 0, 0, 0, 0, 0, 0, 0, 0 };
    for (int i=0; i<=20; i++) {
        find_primes(i, &primes);
    }

    /*
    printf("%i %i %i %i %i %i %i %i\n",
        primes.twos,
        primes.threes,
        primes.fives,
        primes.sevens,
        primes.elevens,
        primes.thirteens,
        primes.seventeens,
        primes.nineteens);
        */

    return
        pow(2, primes.twos) *
        pow(3, primes.threes) *
        pow(5, primes.fives) *
        pow(7, primes.sevens) *
        pow(11, primes.elevens) *
        pow(13, primes.thirteens) *
        pow(17, primes.seventeens) *
        pow(19, primes.nineteens);
}

int main() {
    printf("%li\n", problem5());
}
