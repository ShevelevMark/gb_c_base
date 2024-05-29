/**
 * Ввести три числа, найти их сумму и произведение
 * Нужно напечатать сумму и произведение трех чисел
 *
 * Данные на входе: три целых числа через пробел
 * Данные на выходе:
 *      %d+%d+%d=%d
 *      %d*%d*%d=%d 
 * **/

#include <stdio.h>

int main() {
    int a, b, c;
    int success_cnt = scanf("%d %d %d", &a, &b, &c);
    if (3 != success_cnt) {
        printf("Error");
        return 1;
    }

    printf("%d+%d+%d=%d\n%d*%d*%d=%d\n", a, b, c, a + b + c, a, b, c, a * b * c);
    return 0;
}