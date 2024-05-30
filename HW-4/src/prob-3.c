/**
 * Ввести целое число и определить, верно ли, что все его цифры четные
 * **/

#include <stdio.h>

int main() {
    int num;
    if ( 1 != scanf("%d", &num)) {
        printf("Error");
        return 1;
    }

    num = 0 > num ? -num : num;
    int res = 1;
    while (0 != num) {
        if (0 != (num % 10) % 2) {
            res = 0;
            break;
        }
        num /= 10;
    }

    printf("%s\n", res ? "YES" : "NO");
    return 0;
}