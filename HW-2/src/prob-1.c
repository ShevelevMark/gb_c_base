/**
 * Ввести три числа, найти их сумму. 
 * Нужно напечатать сумму трех чисел.
 * 
 * Данные на входе: три целых числа через пробел
 * Данные на выходе: строка вида %d+%d+%d=%d
 * **/

#include <stdio.h>

int main() {
    int a, b, c;
    int success_cnt = scanf("%d %d %d", &a, &b, &c);
    if (3 != success_cnt) {
        printf("Error");
        return 1;
    }

    printf("%d+%d+%d=%d\n", a, b, c, a + b + c);
    return 0;
}