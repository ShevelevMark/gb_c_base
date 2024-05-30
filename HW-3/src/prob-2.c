/**
 * Ввести пять чисел и вывести наименьшее из них 
 * Нужно напечатать наименьшее число
 * **/

#include <stdio.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main() {
    int a1, a2, a3, a4, a5;
    if ( 5 != scanf("%d %d %d %d %d", &a1, &a2, &a3, &a4, &a5) ) {
        printf("Error");
        return 1;
    }

    int min = a1;
    min = MIN(a2, min);
    min = MIN(a3, min);
    min = MIN(a4, min);
    min = MIN(a5, min);
    printf("%d\n", min);
    return 0;
}