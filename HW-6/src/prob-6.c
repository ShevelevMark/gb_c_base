/*
 * Написать рекурсивную функцию возведения целого числа n в степень p.
 * int recurs_power(int n, int p)
 * Используя данную функцию, решить задачу.
 * **/

#include <stdio.h>

int recurs_power(int n, int p) {
    if (0 == p) return 1;                    // любое положительное число в нулевой степени равно 1 (база рекурсии)
    if (1 == p % 2)                          
        return n * recurs_power(n, p - 1);   // если степень нечётная, то рекурсивный вызов понижает степень на 1
    int x = recurs_power(n, p / 2);          // если степень чётная (2k), то можно вычислить x^k
    return x * x;                            // затем по свойству степени возвести x^k в квадрат -> x^(2k)
}

int main() {
    // test 1
    {
        int in_n = 2, in_p = 3;
        int expected = 8;
        int actual = recurs_power(in_n, in_p);
        printf("Test 1: %s\n", actual == expected ? "OK" : "FAIL");
    }

    // test 2
    {
        int in_n = 3, in_p = 4;
        int expected = 81;
        int actual = recurs_power(in_n, in_p);
        printf("Test 2: %s\n", actual == expected ? "OK" : "FAIL");
    }

    // test 3
    {
        int in_n = 2, in_p = 10;
        int expected = 1024;
        int actual = recurs_power(in_n, in_p);
        printf("Test 3: %s\n", actual == expected ? "OK" : "FAIL");
    }

    // test 4
    {
        int in_n = 1, in_p = 1024;
        int expected = 1;
        int actual = recurs_power(in_n, in_p);
        printf("Test 4: %s\n", actual == expected ? "OK" : "FAIL");
    }

    // test 5
    {
        int in_n = 3, in_p = 17;
        int expected = 129140163;
        int actual = recurs_power(in_n, in_p);
        printf("Test 5: %s\n", actual == expected ? "OK" : "FAIL");
    }

    return 0;
}