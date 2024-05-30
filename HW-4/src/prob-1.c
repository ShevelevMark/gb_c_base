/**
 * Ввести два целых числа a и b (a ≤ b) и вывести сумму квадратов всех чисел от a до b.
 * **/

#include <stdio.h>

int main() {
    // Предполагается, что числа достаточно малы
    int a, b;
    if ( 2 != scanf("%d %d", &a, &b) || a > b ) {
        printf("Error");
        return 1;
    } 

    int accum = 0;
    for (int curr = a; curr != b + 1; ++curr) {
        accum += curr * curr;
    }
    printf("%d\n", accum);
    return 0;
}