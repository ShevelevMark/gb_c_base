/**
 * Дана последовательность целых чисел через пробел, завершающаяся числом 0.
 * Выведите все нечетные числа из этой последовательности, сохраняя их порядок.
 * **/

#include <stdio.h>

void odd_numbers(void) {
    int num;
    if ( 1 != scanf("%d", &num) || 0 == num)
        return;
    
    if (1 == num %2)
        printf("%d ", num);
    odd_numbers();
}

int main() {
    odd_numbers();
    return 0;
}