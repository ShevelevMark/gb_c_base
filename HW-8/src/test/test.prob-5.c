/**
 * @file test.prob-5.c
 * @brief В этом файле находится тестирующий код для пятой задачи
 * **/

void change_max_min(int size, int a[]);

#include <stdio.h>

int check(int size, int a[], int b[]) {
    for (int *a_it = a, *b_it = b, *a_end = a + size; a_it != a_end; ++a_it, ++b_it)
        if (*a_it != *b_it) return 0;
    return 1;
}

int main() {
    // test 1
    {
        int input[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        int expected[10] = {9, 1, 2, 3, 4, 5, 6, 7, 8, 0};
        change_max_min(10, input);
        printf("Test 1: %s\n", check(10, input, expected) ? "OK" : "FAIL");
    }

    // test 2
    {
        int input[10] = {1, 1, -1, 1, 1, 1, 2, 1, 1, 1};
        int expected[10] = {1, 1, 2, 1, 1, 1, -1, 1, 1, 1};
        change_max_min(10, input);
        printf("Test 2: %s\n", check(10, input, expected) ? "OK" : "FAIL");
    }

    // test 3
    {
        int input[2] = {-100, 50};
        int expected[2] = {50, -100};
        change_max_min(2, input);
        printf("Test 2: %s\n", check(2, input, expected) ? "OK" : "FAIL");
    }

    return 0;
}