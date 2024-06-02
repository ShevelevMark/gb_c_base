/**
 * @file test.prob-3.c
 * @brief В этом файле находится тестирующий код для третьей задачи
 * **/

int find_max_array(int size, int a[]);

#include <stdio.h>
#include <limits.h>

int main() {
    // test 1
    {
        int a[10] = {1, 2, -2, 0, 3, 4, -1, 5, -6, -3};
        int expected = 5;
        int actual = find_max_array(10, a);
        printf("Test 1: %s\n", actual == expected ? "OK" : "FAIL");
    }

    // test 2
    {
        int a[1] = {1};
        int expected = 1;
        int actual = find_max_array(1, a);
        printf("Test 2: %s\n", actual == expected ? "OK" : "FAIL");
    }

    // test 3  
    {
        int a[10] = {-1, 0, 1, 2, 3, 4, 5, 6, 7, 9};
        int expected = 9;
        int actual = find_max_array(10, a);
        printf("Test 3: %s\n", actual == expected ? "OK" : "FAIL");
    }

    // test 4
    {
        int a[3] = {INT_MIN, INT_MIN, INT_MIN};
        int expected = INT_MIN;
        int actual = find_max_array(3, a);
        printf("Test 4: %s\n", actual == expected ? "OK" : "FAIL");
    }

    // test 5
    {
        int a[5] = {INT_MIN, -1, 0, 1, INT_MAX};
        int expected = INT_MAX;
        int actual = find_max_array(5, a);
        printf("Test 5: %s\n", actual == expected ? "OK" : "FAIL");
    }

    return 0;
}