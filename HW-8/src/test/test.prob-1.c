/**
 * @file test.prob-1.c
 * @brief В этом файле находится тестирующий код для первой задачи
 * **/

void sort_array(int size, int a[]);

#include <stdio.h>

int main() {
    int input[7] = {1, 7, 9 ,-2, 4, 0, 8};
    int expected[7] = {-2, 0, 1, 4, 7, 8, 9};

    sort_array(7, input);

    int check = 1;
    for (int *et = expected, *it = input, *end = input + 7; it != end; ++it, ++et)
        if (*et != *it) {
            check = 0;
            break;
        }

    printf("%s\n", check ? "OK" : "FAIL"); 

    return 0;
}