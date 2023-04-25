#include <stdio.h>
#include <gmp.h>
#include <stdlib.h>
#include <string.h>

#define twos 1000
int digits[twos];

int main() {
    size_t size = 0;
    char *buffer = NULL;
    FILE *fp = open_memstream(&buffer, &size);

    mpz_t n;
    mpz_init_set_ui(n, 2);
    mpz_pow_ui(n, n, 1000);
    mpz_out_str(fp, 10, n);
    mpz_clear(n);

    int c = 0;
    int sum = 0;
    while ((c = getc(fp)) != EOF) {
        sum = sum + c - '0';
    }
    printf("%i\n", sum);

    fclose(fp);
    free(buffer);

    return 0;
}
