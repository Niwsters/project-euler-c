#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "primes.h"
#include "util.h"
#include "node.h"
#include "dict.h"
#include "list.h"
#include "set.h"

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
#include "problem11.h"
#include "problem12.h"

int main(int argc, char **argv) {
    if (argc > 1 && streq(argv[1], "--test")) {
        primes_test();
        dict_test();
        list_test();
        node_test();
        set_test();
    } else {
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
        printf("Problem 10: %li\n", problem10());
        printf("Problem 11: %li\n", problem11());
        */
        printf("Problem 12: %li\n", problem12());
    }

    return EXIT_SUCCESS;
}
