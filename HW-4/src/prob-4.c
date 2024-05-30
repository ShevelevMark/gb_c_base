/**
 * Ввести целое (неотрицательное) число и «перевернуть» его, так чтобы первая цифра стала последней и т.д.
 * **/

#include <stdio.h>

int main() {
    unsigned num;
    if ( 1 != scanf("%u", &num) ) {
        printf("Error");
        return 1;
    }

    unsigned rev = 0;
    while (0 != num) {
        rev = rev * 10 + num % 10;
        num /= 10;
    }
    printf("%u\n", rev);
    return 0;
}