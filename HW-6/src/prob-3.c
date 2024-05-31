/**
 * Дано натуральное число N. Посчитать количество «1» в двоичной записи числа.
 *
 * Учитывая тему лекции, полагаю, что нужно было сделать рекурсивно.
 * **/

unsigned count_ones(unsigned n) {
    if (0 == n) return 0;
    return (n & 1 ? 1 : 0) + count_ones(n >> 1);
}

#include <stdio.h>

int main() {
    // test 1
    {
        unsigned input = 5, expected = 2;
        unsigned actual = count_ones(input);
        printf("Test 1: (actual: %u; expected: %u;) %s\n", actual, expected, actual == expected ? "OK" : "FAIL");
    }

    // test 2
    {
        unsigned input = 255, expected = 8;
        unsigned actual = count_ones(input);
        printf("Test 2: (actual: %u; expected: %u;) %s\n", actual, expected, actual == expected ? "OK" : "FAIL");
    }

    // test 3
    {
        unsigned input = 1, expected = 1;
        unsigned actual = count_ones(input);
        printf("Test 3: (actual: %u; expected: %u;) %s\n", actual, expected, actual == expected ? "OK" : "FAIL");
    }

    // test 4
    {
        unsigned input = 1023, expected = 10;
        unsigned actual = count_ones(input);
        printf("Test 4: (actual: %u; expected: %u;) %s\n", actual, expected, actual == expected ? "OK" : "FAIL");
    }

    // test 5
    {
        unsigned input = 1025, expected = 2;
        unsigned actual = count_ones(input);
        printf("Test 5: (actual: %u; expected: %u;) %s\n", actual, expected, actual == expected ? "OK" : "FAIL");
    }

    return 0;
}