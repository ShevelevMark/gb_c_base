/**
 * Составить рекурсивную функцию, 
 * Выведите все числа от A до B включительно, в порядке возрастания, если A < B, 
 * или в порядке убывания в противном случае.
 * **/

#include <stdio.h>

void print_consecutive(int a, int b) {
    printf("%d ", a);

    // если числа равны - ничего не делаем
    if (a == b) return;

    if (a > b) // если a > b, то мы должны распечатать ещё и все числа от a - 1 до b 
        print_consecutive(a - 1, b);
    else
        print_consecutive(a + 1, b);
}

int main() {
    // test 1
    {
        printf("Test 1: (actual: ");
        int in_a = 5, in_b = 2;
        char const *expected = "5 4 3 2 ";
        print_consecutive(in_a, in_b);
        printf("; expected: %s;)\n", expected);
    }

    // test 2
    {
        printf("Test 2: (actual: ");
        int in_a = 2, in_b = 7;
        char const *expected = "2 3 4 5 6 7 ";
        print_consecutive(in_a, in_b);
        printf("; expected: %s;)\n", expected);
    }

    // test 3
    {
        printf("Test 3: (actual: ");
        int in_a = 14, in_b = 14;
        char const *expected = "14 ";
        print_consecutive(in_a, in_b);
        printf("; expected: %s;)\n", expected);
    }

    // test 4
    {
        printf("Test 4: (actual: ");
        int in_a = -10, in_b = 0;
        char const *expected = "-10 -9 -8 -7 -6 -5 -4 -3 -2 -1 0 ";
        print_consecutive(in_a, in_b);
        printf("; expected: %s;)\n", expected);
    }

    // test 5
    {
        printf("Test 5: (actual: ");
        int in_a = 0, in_b = 0;
        char const *expected = "0 ";
        print_consecutive(in_a, in_b);
        printf("; expected: %s;)\n", expected);
    }
    return 0;
}

