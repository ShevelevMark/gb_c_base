/**
 * @file test.prob-4.c
 * @brief В этом файле находится тестирующий код для четвёртой задачи
 * **/

int is_two_same(int size, int a[]);

#include <stdio.h>

int main() {
    // test 1
    {
        int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
        int expected = 0;
        int actual = is_two_same(10, a);
        printf("Test 1: %s\n", actual == expected ? "OK" : "FAIL");
    }

    // test 2
    {
        int a[10] = {1, 0, 3, 4, 5, 6, 7, 8, 9, 0};
        int expected = 1;
        int actual = is_two_same(10, a);
        printf("Test 2: %s\n", actual == expected ? "OK" : "FAIL");
    }

    // test 3
    {
        int a[10] = {1, 9, 3, 4, 5, 6, 7, 8, 9, 0};
        int expected = 1;
        int actual = is_two_same(10, a);
        printf("Test 3: %s\n", actual == expected ? "OK" : "FAIL");
    }

    // test 4
    {
        int a[10] = {1, 7, 3, 4, 5, 6, 7, 8, 9, 0};
        int expected = 1;
        int actual = is_two_same(10, a);
        printf("Test 4: %s\n", actual == expected ? "OK" : "FAIL");
    }

    // test 5
    {
        int a[10] = {-1, -2, -3, -4, -5, -6, -7, 0, 1, -4};
        int expected = 1;
        int actual = is_two_same(10, a);
        printf("Test 5: %s\n", actual == expected ? "OK" : "FAIL");
    }

    // test 6
    {
        int a[10] = {-1, -2, -3, -4, -5, -6, -7, 0, 1, 2};
        int expected = 0;
        int actual = is_two_same(10, a);
        printf("Test 6: %s\n", actual == expected ? "OK" : "FAIL");
    }

    return 0;
}