/**
 * Ввести три числа и определить, верно ли, что они вводились в порядке возрастания.
 * **/

#include <stdio.h>

int main() {
    int a1, a2, a3;
    if ( 3 != scanf("%d %d %d", &a1, &a2, &a3) ) {
        printf("Error");
        return 1;
    }

    printf("%s\n", (a1 < a2 && a2 < a3 ? "YES" : "NO"));
    return 0; 
}