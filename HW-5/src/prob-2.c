/**
 * Составить функцию, которая определяет наибольший общий делитель двух натуральных 
 * и привести пример ее использования
 * **/

int nod(int a, int b) {
    if (a < b) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    while (0 != b) {
        a %= b;
        int tmp = a;
        a = b;
        b = tmp;
    }

    return a;
}

#include <stdio.h>

int main() {
    // test 1
    {
        printf("Test-1: ");
        int in_a = 14, in_b = 21, expected = 7;
        int actual = nod(in_a, in_b);
        printf("%s\n", actual == expected ? "OK" : "FAIL");
    }

    // test 2
    {
        printf("Test-2: ");
        int in_a = 21, in_b = 14, expected = 7;
        int actual = nod(in_a, in_b);
        printf("%s\n", actual == expected ? "OK" : "FAIL");
    }

    // test 3
    {
        printf("Test-3: ");
        int in_a = 56807, in_b = 103451, expected = 1;
        int actual = nod(in_a, in_b);
        printf("%s\n", actual == expected ? "OK" : "FAIL");
    }

    // test 4
    {
        printf("Test-4: ");
        int in_a = 31031, in_b = 1771, expected = 77;
        int actual = nod(in_a, in_b);
        printf("%s\n", actual == expected ? "OK" : "FAIL");
    }

    return 0;
}