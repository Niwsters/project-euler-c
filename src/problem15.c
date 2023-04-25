#include <stdio.h>
#include <string.h>
#define LIMIT 20

int main() {
    size_t routes[LIMIT][LIMIT];
    memset(routes, 1, LIMIT*LIMIT);

    size_t x = 0;
    size_t y = 0;
    for (size_t y=0; y<LIMIT; y++) {
        for (size_t x=0; x<LIMIT; x++) {
            size_t routes_down = 1;
            size_t routes_right = 1;
            if (y > 0) {
                routes_down = routes[y-1][x];
            }
            if (x > 0) {
                routes_right = routes[y][x-1];
            }
            routes[y][x] = routes_down + routes_right;
        }
    }

    printf("%li\n", routes[LIMIT-1][LIMIT-1]);

    return 0;
}
