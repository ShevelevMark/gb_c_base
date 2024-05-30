/**
 * Ввести целое (положительное) число и определить, верно ли, что в нём ровно 3 цифры.
 * **/

#include <stdio.h>

int main() {
    unsigned num;
    if ( 1 != scanf("%u", &num) ) {
        printf("Error");
        return 1; 
    }

    int cnt = 0;
    while (num > 0) num /= 10, ++cnt;

    printf("%s\n", 3 == cnt ? "YES" : "NO");
    return 0;
}
