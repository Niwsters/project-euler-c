#include <stdbool.h>
#include <math.h>

bool is_triplet(int a, int b, int c) {
    return pow(a, 2) + pow(b, 2) == pow(c, 2);
}

long problem9() {
    int sum = 1000;
    for (int a=1; a<sum; a++) {
        for (int b=1; b<sum; b++) {
            int c = sum - a - b;
            if (is_triplet(a, b, c))
                return a * b * c;
        }
    }

    return 0;
}
