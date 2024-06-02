/**
 * @file test.prob-2.c
 * @brief В этом файле находится тестирующий код для второй задачи
 * **/
 
void sort_even_odd(int n, int a[]);

#include <stdio.h>

int main() {
    int arr[10];
    for (int *it = arr, *end = arr + size; it != end; ++it)
        if (1 != scanf("%d", it)) {
            printf("Error");
            return 1;
        }

    sort_even_odd(size, arr);

    for (int *it = arr, *end = arr + size; it != end; ++it)
        printf("%d ", *it);
    printf("\n");

    return 0;
}