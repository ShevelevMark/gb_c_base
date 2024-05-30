/**
 * Составить логическую функцию, которая определяет, верно ли, что в заданном числе сумма цифр равна произведению.
 * int is_happy_number(int n)
 * **/

int digit_sum(int);
int digit_prd(int);

int is_happy_number(int n) {
    return digit_prd(n) == digit_sum(n);
}

int digit_prd(int x) {
    int prd = 1;
    while (0 != x) {
        prd *= x % 10;
        x /= 10;
    }
    return prd;
}

int digit_sum(int x) {
    int sum = 0;
    while (0 != x) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

char const * to_str(int b) {
    if (0 == b) return "NO";
    return "YES";
}

#include <stdio.h>

int main() {
    // test 1
    {
        printf("Test-1: ");
        int input = 123;
        char const *expected = "YES";
        printf("(actual=%s expected=%s)\n", to_str(is_happy_number(input)), expected);
    }

    // test 2
    {
        printf("Test-2: ");
        int input = 528;
        char const *expected = "NO";
        printf("(actual=%s expected=%s)\n", to_str(is_happy_number(input)), expected);
    }

    // test 3
    {
        printf("Test-3: ");
        int input = 123;
        char const *expected = "YES";
        printf("(actual=%s expected=%s)\n", to_str(is_happy_number(input)), expected); 
    }

    // test 4
    {
        printf("Test-4: ");
        int input = 101;
        char const *expected = "NO";
        printf("(actual=%s expected=%s)\n", to_str(is_happy_number(input)), expected); 
    }

    return 0;
}