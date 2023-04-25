#include <stdio.h>

int main() {
    int a = 1;
    int b = 1;

    int sum = 0;
    int c = a+b;
    while (c < 4e6) {
        if (c % 2 == 0) {
            sum += c;
        }

        a = b;
        b = c;
        c = a + b;
    }
    printf("%i\n", sum);

    return 0;
}
