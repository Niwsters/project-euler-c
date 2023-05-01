#include <stdint.h>
#include <stdio.h>

int main() {
    // 0 = 1901-01-01
    uint32_t day = 0;

    uint32_t mondaycount = 0;

    for (uint32_t year = 1901; year < 2001; year++) {
        uint32_t jan = 31;
        uint32_t feb = 28;
        uint32_t mar = 31;
        uint32_t apr = 30;
        uint32_t may = 31;
        uint32_t jun = 30;
        uint32_t jul = 31;
        uint32_t aug = 31;
        uint32_t sep = 30;
        uint32_t oct = 31;
        uint32_t nov = 30;
        uint32_t dec = 31;

        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
            feb = 29;
        }

        uint32_t monthdays[] = {
            jan,
            feb,
            mar,
            apr,
            may,
            jun,
            jul,
            aug,
            sep,
            oct,
            nov,
            dec
        };

        for (uint32_t month=0; month<12; month++) {
            uint32_t nmonthdays = monthdays[month];
            for (uint32_t monthday=0; monthday < nmonthdays; monthday++) {
                uint32_t weekday = day % 7;
                if (weekday == 0 && monthday == 0) {
                    mondaycount++;
                }

                day++;
            }
        }
    }

    printf("%i\n", mondaycount);

    return 0;
}
