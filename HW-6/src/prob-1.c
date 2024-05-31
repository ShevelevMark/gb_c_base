/**
 * Дано натуральное число N. 
 * Выведите все его цифры по одной, в прямом порядке, разделяя их пробелами или новыми строками. 
 * Необходимо реализовать рекурсивную функцию.
 * **/

#include <stdio.h>

void print_num(int num) {
    if (0 == num) return;
    print_num(num / 10);
    printf("%d ", num % 10);
}

int main() {
    // test 1
    {
        printf("Test 1: (");
        int input = 1234;
        char const *expected = "1 2 3 4 ";
        printf("actual: ");
        print_num(input);
        printf("; expected: %s;)\n", expected);
    }

    // test 2
    {
        printf("Test 2: (");
        int input = 1;
        char const *expected = "1 ";
        printf("actual: ");
        print_num(input);
        printf("; expected: %s;)\n", expected);
    }

    // test 3
    {
        printf("Test 3: (");
        int input = 50000;
        char const *expected = "5 0 0 0 0 ";
        printf("actual: ");
        print_num(input);
        printf("; expected: %s;)\n", expected);
    }

    // test 4
    {
        printf("Test 4: (");
        int input = 1024;
        char const *expected = "1 0 2 4 ";
        printf("actual: ");
        print_num(input);
        printf("; expected: %s;)\n", expected);
    }

    return 0;
}
