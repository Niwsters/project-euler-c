#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool is_palindrome(int n) {
    char str[10];
    sprintf(str, "%d", n);

    size_t len = strlen(str);
    for (int i=0; i<len/2; i++) {
        if (str[i] != str[len - i - 1])
            return false;
    }

    return true;
}

long problem4() {
    int a = 1;
    int b = 1;
    int n = 1;
    int largest_palindrome = 1;
    for (int a=1; a<1000; a++) {
        for (int b=1; b<1000; b++) {
            n = a*b;
            if (is_palindrome(n) && n > largest_palindrome)
                largest_palindrome = n;
        }
    }

    return largest_palindrome;
}

int main() {
    printf("%li\n", problem4());
    return 0;
}
