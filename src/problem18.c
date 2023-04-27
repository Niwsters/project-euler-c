#include <stdio.h>
#include <assert.h>

#define ROWS 16
#define MAX_COLS ROWS
#define SIZE (15+1)*15/2

typedef struct Pyramid {
    int values[SIZE];
} Pyramid;

Pyramid pyramid = {
    {
        75,
        95, 64,
        17, 47, 82,
        18, 35, 87, 10,
        20, 4, 82, 47, 65,
        19, 1, 23, 75, 3, 34,
        88, 2, 77, 73, 7, 63, 67,
        99, 65, 4, 28, 6, 16, 70, 92,
        41, 41, 26, 56, 83, 40, 80, 70, 33,
        41, 48, 72, 33, 47, 32, 37, 16, 94, 29,
        53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14,
        70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57,
        91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48,
        63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31,
        4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23
    }
};

int trianglesum(int n) {
    return (n+1)*n/2;
}

int pyramidi(int row, int col) {
    assert(col < row);
    int from = trianglesum(row-1);
    int i = from+col;
    assert(i < SIZE);
    return i;
}

int pyramidn(Pyramid *pyramid, int row, int col) {
    return pyramid->values[pyramidi(row, col)];
}

void merge(Pyramid *new_pyramid, Pyramid pyramid, int row) {
    for (int i=0; i<row-1; i++) {
        for (int j=i; j<i+2; j++) {
            int a = pyramidn(&pyramid, row-1, i);
            int b = pyramidn(&pyramid, row, j);

            if (pyramidn(new_pyramid, row, j) < a+b) {
                new_pyramid->values[pyramidi(row, j)] = a+b;
            }
        }
    }
}

void pyramid_print(Pyramid *pyramid) {
    for (int row=0; row<ROWS; row++) {
        int colcount = row;

        for (int col=0; col<colcount; col++) {
            printf(" %i", pyramidn(pyramid, row, col));
        }
        printf("\n");
    }
}

int main() {
    pyramid_print(&pyramid);
    for (int row=2; row<ROWS; row++) {
        merge(&pyramid, pyramid, row);
        pyramid_print(&pyramid);
    }

    int largest = 0;
    for (int i=0; i<ROWS-1; i++) {
        int n = pyramidn(&pyramid, ROWS-1, i);
        if (n > largest) {
            largest = n;
        }
    }

    printf("%i\n", largest);

    return 0;
}
