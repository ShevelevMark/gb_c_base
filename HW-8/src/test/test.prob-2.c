/**
 * @file test.prob-2.c
 * @brief В этом файле находится тестирующий код для второй задачи
 * **/
 
void sort_even_odd(int n, int a[]);

#include <stdio.h>

int check(int *begin, int *end, int *cmp) {
    for (int *it = begin; it != end; ++it, ++cmp)
        if (*it != *cmp) return 0;
    return 1;
}

int main() {
    // test
    {  
        int input[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
        int expected[10] = {2, 4, 6, 8, 0, 1, 3, 5, 7, 9};
        sort_even_odd(10, input);
        printf("Test 1: %s\n", check(input, input + 10, expected) ? "OK" : "FAIL");
    }

    // test 2
    {
        int input[10] = {2, 4, 6, 8, 0, 10, 12, 14, 16, 20};
        int expected[10] = {2, 4, 6, 8, 0, 10, 12, 14, 16, 20};
        sort_even_odd(10, input);
        printf("Test 2: %s\n", check(input, input + 10, expected) ? "OK" : "FAIL");
    }
    
    // test 3
    {
        int input[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
        int expected[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
        sort_even_odd(10, input);
        printf("Test 3: %s\n", check(input, input + 10, expected) ? "OK" : "FAIL");
    }

    // test 4
    {
        int input[2] = {1, 2};
        int expected[2] = {2, 1};
        sort_even_odd(2, input);
        printf("Test 4: %s\n", check(input, input + 2, expected) ? "OK" : "FAIL");
    }
    return 0;
}