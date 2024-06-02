/**
 * @file test.prob-6.c
 * @brief В этом файле находится тестирующий код для шестой задачи
 * **/

unsigned count_positive_less_diagonal_average(float **, unsigned size);

#include <stdio.h>

int main() {
    // test 1
    {
        float mtx[5][5] = {
            {1.f, 1.f, 1.f, 1.f, 1.f},
            {2.f, 2.f, 2.f, 2.f, 2.f},
            {3.f, 3.f, 3.f, 3.f, 3.f},
            {4.f, 4.f, 4.f, 4.f, 4.f},
            {5.f, 5.f, 5.f, 5.f, 5.f} 
        };

        float *input[5] = {
            &mtx[0][0],
            &mtx[1][0],
            &mtx[2][0],
            &mtx[3][0],
            &mtx[4][0]
        };

        unsigned expected = 10u;
        unsigned actual = count_positive_less_diagonal_average(input, 5u);
        printf("Test 1: %s\n", actual == expected ? "OK" : "FAIL");
    }

    // test 2
    {
        float mtx[5][5] = {
            {-1.f, 1.f, 1.f, 1.f, 1.f},
            {2.f, -2.f, 2.f, 2.f, 2.f},
            {3.f, 3.f, -3.f, 3.f, 3.f},
            {4.f, 4.f, 4.f, -4.f, 4.f},
            {5.f, 5.f, 5.f, 5.f, -6.f} 
        };

        float *input[5] = {
            &mtx[0][0],
            &mtx[1][0],
            &mtx[2][0],
            &mtx[3][0],
            &mtx[4][0]
        };

        unsigned expected = 20u;
        unsigned actual = count_positive_less_diagonal_average(input, 5u);
        printf("Test 1: %s\n", actual == expected ? "OK" : "FAIL");
    }
}