/**
 * Ввести натуральное число и напечатать все числа от 10 до введенного числа - у которых сумма цифр равна произведению цифр
 * **/

#include <stdio.h>

int main() {
    int num;
    if ( 1 != scanf("%d", &num) || num < 10 ) {
        printf("Error");
        return 1;
    }

    for (int i = 10; i != num + 1; ++i) {
        int tmp = i;
        // Сумма 
        int digit_sum = 0;
        while (0 != tmp) {
            digit_sum += tmp % 10;
            tmp /= 10;
        }

        tmp = i;
        // Произведение
        int digit_product = 1;
        while (0 != tmp) {
            digit_product *= tmp % 10;
            tmp /= 10;
        }

        if (digit_product == digit_sum)
            printf("%d ", i);
    }
    printf("\n");
    return 0;
}