/**
 * Ввести пять чисел и вывести наибольшее из них 
 * Нужно напечатать наибольшее число
 * **/

#include <stdio.h>

int main() {
    int a1, a2, a3, a4, a5;
    if ( 5 != scanf("%d %d %d %d %d", &a1, &a2, &a3, &a4, &a5) ) {
        printf("Error");
        return 1;
    }

    int max = a1;
    max = a2 > max ? a2 : max;
    max = a3 > max ? a3 : max;
    max = a4 > max ? a4 : max;
    max = a5 > max ? a5 : max;
    printf("%d\n", max);
    return 0;
}