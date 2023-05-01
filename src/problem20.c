#include <stdio.h>
#include <gmp.h>
#include <stdint.h>
#include <stdlib.h>

int main() {
    mpz_t n;
    mpz_init_set_ui(n, 0);
    mpz_fac_ui(n, 100);

    size_t size = 0;
    char *buffer = NULL;
    FILE *fp = open_memstream(&buffer, &size);

    mpz_out_str(fp, 10, n);
    mpz_clear(n);

    uint32_t c = 0;
    uint32_t sum = 0;
    while ((c = getc(fp)) != EOF) {
        sum = sum + c - '0';
    }
    printf("%i\n", sum);

    fclose(fp);
    free(buffer);

    return 0;
}
