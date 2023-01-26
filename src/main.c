#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "primes.h"

#include "problem1.h"
#include "problem2.h"
#include "problem3.h"
#include "problem4.h"
#include "problem5.h"
#include "problem6.h"
#include "problem7.h"
#include "problem8.h"
#include "problem9.h"
#include "problem10.h"

int main() {
    primes_init();

    primes_test();

    /*
    printf("Problem 1: %li\n", problem1());
    printf("Problem 2: %li\n", problem2());
    printf("Problem 3: %li\n", problem3());
    printf("Problem 4: %li\n", problem4());
    printf("Problem 5: %li\n", problem5());
    printf("Problem 6: %li\n", problem6());
    printf("Problem 7: %li\n", problem7());
    printf("Problem 8: %li\n", problem8());
    printf("Problem 9: %li\n", problem9());
    */
    printf("Problem 10: %li\n", problem10());

    primes_exit();

    return EXIT_SUCCESS;
}
