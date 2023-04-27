#include <stdio.h>
#include <string.h>
#include <assert.h>

const char *lows[] = {
    "",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
    "ten",
    "eleven",
    "twelve",
    "thirteen",
    "fourteen",
    "fifteen",
    "sixteen",
    "seventeen",
    "eighteen",
    "nineteen"
};

const char *low(size_t n) {
    size_t i = 0;
    if (n < 10 || (n % 100) > 19) {
        i = n % 10;
    } else {
        i = n % 20;
    }

    assert(i < 20);
    return lows[i];
}

const char *tens[] = {
    "",
    "",
    "twenty",
    "thirty",
    "forty",
    "fifty",
    "sixty",
    "seventy",
    "eighty",
    "ninety"
};

const char *ten(size_t n) {
    size_t i = (n % 100) / 10;
    assert(i < 10);
    return tens[i];
}

const char *hundred(size_t n) {
    if ((n % 1000) >= 100) return "hundred";
    return "";
}

const char *hundred_count(size_t n) {
    size_t i = (n % 1000) / 100;
    return low(i);
}

const char *and(size_t n) {
    if (n >= 100 && n % 100 > 0) {
        return "and";
    }

    return "";
}

const char *thousand(size_t n) {
    if (n >= 1000) return "thousand";
    return "";
}

const char *thousand_count(size_t n) {
    size_t i = n / 1000;
    return low(i);
}

size_t wordlength(size_t n) {
    return strlen(low(n))
         + strlen(ten(n))
         + strlen(and(n))
         + strlen(hundred(n))
         + strlen(hundred_count(n))
         + strlen(thousand(n))
         + strlen(thousand_count(n));
}

void print_word(size_t n) {
    printf("%s %s %s %s %s %s %s\n",
        thousand_count(n),
        thousand(n),
        hundred_count(n),
        hundred(n),
        and(n),
        ten(n),
        low(n));
}

int main() {
    size_t total = 0;
    for (size_t n=1; n<=1000; n++) {
        total += wordlength(n);
    }

    printf("%li\n", total);

    return 0;
}
