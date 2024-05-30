/**
 * Необходимо составить функцию, 
 * которая определяет, сколько зерен попросил положить на N-ую клетку изобретатель шахмат
 * (на 1-ую – 1 зерно, на 2-ую – 2 зерна, на 3-ю – 4 зерна, ...)
 *
 * Отметим, что на каждую клетку попадает 2^{n - 1} зёрен, где n - номер клетки.
 * Максимальное значение будет 2^{64 - 1} == 2^63, это число можно записать в тип uint64_t.
 * **/

#include <stdint.h>

// ожидаем число не больше 64
uint64_t seed_count(uint64_t cell_number) {
    static uint64_t const unit = 1;
    return unit << (cell_number - 1);
}

#include <stdio.h>

int main() {
    // test 1
    {
        printf("Test-1: ");
        uint64_t input = 1, expect = 1;
        uint64_t actual = seed_count(input);
        printf("%s\n", expect == actual ? "OK" : "FAIL");
    }

    // test 2
    {
        printf("Test-2: ");
        uint64_t input = 64, expect = 9223372036854775808ull;
        uint64_t actual = seed_count(input);
        printf("%s\n", expect == actual ? "OK" : "FAIL");
    }

    // test 3
    {
        printf("Test-3: ");
        uint64_t input = 28, expect = 134217728ull;
        uint64_t actual = seed_count(input);
        printf("%s\n", expect == actual ? "OK" : "FAIL");
    }

    return 0; 
}
