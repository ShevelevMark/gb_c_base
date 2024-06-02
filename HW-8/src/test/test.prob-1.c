/**
 * @file test.prob-1.c
 * @brief В этом файле находится тестирующий код для первой задачи
 * **/

void sort_array(int size, int a[]);

#include <stdio.h>

int main() {
    // test 1
    {
        int input[7] = {1, 7, 9 ,-2, 4, 0, 8};
        int expected[7] = {-2, 0, 1, 4, 7, 8, 9};
        sort_array(7, input);

        int check = 1;
        for (int *et = expected, *it = input, *end = input + 7; it != end; ++it, ++et)
            if (*et != *it) {
                check = 0;
                break;
            }

        printf("Test 1: %s\n", check ? "OK" : "FAIL"); 
    }

    // test 2
    {
        int input[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
        int expected[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        sort_array(10, input);

        int check = 1;
        for (int *et = expected, *it = input, *end = input + 10; it != end; ++it, ++et)
            if (*et != *it) {
                check = 0;
                break;
            }

        printf("Test 2: %s\n", check ? "OK" : "FAIL"); 
    }
    
    // test 3
    {
        int input[11] = {-1, -2, -3, -4, -5, -6, -7, 0, 1, -4, 9};
        int expected[11] = {-7, -6, -5, -4, -4, -3, -2, -1, 0, 1, 9};
        sort_array(11, input);

        int check = 1;
        for (int *et = expected, *it = input, *end = input + 11; it != end; ++it, ++et)
            if (*et != *it) {
                check = 0;
                break;
            }

        printf("Test 3: %s\n", check ? "OK" : "FAIL"); 
    }

    // test 4
    {
        int input[7] = {-1, 1, -1, 1, 1, -1, 0};
        int expected[7] = {-1, -1, -1, 0, 1, 1, 1};
        sort_array(7, input);

        int check = 1;
        for (int *et = expected, *it = input, *end = input + 7; it != end; ++it, ++et)
            if (*et != *it) {
                check = 0;
                break;
            }

        printf("Test 4: %s\n", check ? "OK" : "FAIL"); 
    }

    return 0;
}