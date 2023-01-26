#include <math.h>

long problem6() {
    long squares = 0;
    long sum = 0;
    for (int i=1; i<=100; i++) {
        squares += pow(i, 2);
        sum += i;
    }
    sum = pow(sum, 2);

    return sum - squares;
}
