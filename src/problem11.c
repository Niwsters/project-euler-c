#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "dict.h"


const char *input = "08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08\n49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00\n81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65\n52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91\n22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80\n24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50\n32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70\n67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21\n24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72\n21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95\n78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92\n16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57\n86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58\n19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40\n04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66\n88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69\n04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36\n20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16\n20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54\n01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48\n";

const size_t WIDTH = 20;
const size_t HEIGHT = 20;

void format_key(char *key, int x, int y) {
    sprintf(key, "%i:%i", x, y);
}

Dict *create_dict(char **lines) {
    Dict *dict = dict_create();
    for (int y=0; y<HEIGHT; y++) {
        char *line = lines[y];

        char key[6];
        char *cell = strtok(line, " ");
        for (int x=0; x<WIDTH; x++) {
            char *end;
            long num = strtol(cell, &end, 10);

            format_key(key, x, y);
            dict_set(dict, key, (void*) num);

            cell = strtok(NULL, " ");
        }
    }
    return dict;
}

long mult_product(Dict *dict, int x, int y, long product) {
    char key[6];
    format_key(key, x, y);
    long value = (long) dict_get(dict, key);
    return product * value;
}

long product_right(Dict *dict, int x, int y) {
    long product = 1;
    for (int x2=0; x2<4; x2++) {
        if (x+4 > WIDTH)
            break;

        product = mult_product(dict, x+x2, y, product);
    }
    return product;
}

long product_down(Dict *dict, int x, int y) {
    long product = 1;
    for (int y2=0; y2<4; y2++) {
        if (y+4 > HEIGHT)
            break;

        product = mult_product(dict, x, y+y2, product);
    }
    return product;
}

long product_diagonal_right(Dict *dict, int x, int y) {
    long product = 1;
    for (int i=0; i<4; i++) {
        if (x+4 > WIDTH || y+4 > HEIGHT)
            break;

        int x2 = i;
        int y2 = i;

        product = mult_product(dict, x+x2, y+y2, product);
    }
    return product;
}

long product_diagonal_left(Dict *dict, int x, int y) {
    long product = 1;
    for (int i=0; i<4; i++) {
        if (x-4 < 0 || y+4 > HEIGHT)
            break;

        int x2 = -i;
        int y2 = i;

        product = mult_product(dict, x+x2, y+y2, product);
    }
    return product;
}

long update_largest_product(long product, long largest_product) {
    if (product > largest_product) {
        return product;
    }

    return largest_product;
}

long problem11() {
    char *input_cpy = calloc(strlen(input) + 1, sizeof(char));
    strcpy(input_cpy, input);

    char *lines[HEIGHT];
    char *line = strtok(input_cpy, "\n");
    lines[0] = line;
    for (int i=1; i<HEIGHT; i++) {
        lines[i] = strtok(NULL, "\n");
    }

    Dict *dict = create_dict(lines);

    long largest_product = 0;

    for (int y=0; y<HEIGHT; y++) {
        long product = 1;
        for (int x=0; x<WIDTH; x++) {
            // right
            product = product_right(dict, x, y);
            largest_product = update_largest_product(product, largest_product);

            // down
            product = product_down(dict, x, y);
            largest_product = update_largest_product(product, largest_product);

            // diagonal down right
            product = product_diagonal_right(dict, x, y);
            largest_product = update_largest_product(product, largest_product);

            // diagonal down left
            product = product_diagonal_left(dict, x, y);
            largest_product = update_largest_product(product, largest_product);
        }
    }

    dict_destroy(dict);

    return largest_product;
}
