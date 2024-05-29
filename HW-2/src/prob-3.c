/**
 * Ввести два числа и найти их разность 
 * Нужно напечатать разность двух чисел
 * **/

#include <stdio.h>

int main() {
    int a, b;
    int success_cnt = scanf("%d %d", &a, &b);
    if (2 != success_cnt) {
        printf("Error");
        return 1;
    }

    printf("%d\n", a - b);
    return 0;
}