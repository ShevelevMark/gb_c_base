/**
 * На вход подается произвольное четырехзначное число
 * Нужно напечатать среднее арифметическое цифр 
 * **/

#include <stdio.h>

int main() {
    int a;
    int success_cnt = scanf("%d", &a);
    if (1 != success_cnt) {
        printf("Error");
        return 1;
    }

    float avg = 0.f;
    for (unsigned digit_cnt = 0; digit_cnt != 4; ++digit_cnt) {
        if (0 == a) {
            printf("Error");
            return 2;
        }
        avg += (float)(a % 10);
        a /= 10;
    }
    avg /= 4.f;
    printf("%.2f\n", avg);
    return 0;
}