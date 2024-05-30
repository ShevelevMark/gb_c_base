/**
 * Проверить строку состоящую из скобок "(" и ")" на корректность.
 *
 * Задачу можно решить методом баланса: на каждую открывающуюся скобку увеличивать баланс, 
 * на каждую закрывающуюся - уменьшать. Если баланс отрицательный, то конструкция не верна, 
 * так как закрывающих скобок уже больше открывающих и это нельзя сбалансировать. Если 
 * дойдя до конца строки мы видим положительный баланс, значит недостаточно закрывающих скобок. 
 * **/

int check_par(char const *str) {
    int balance = 0;
    while (0 != *str) {
        if ('(' == *str) ++balance;
        if (')' == *str) --balance;
        if (0 > balance) return 0;
        ++str;
    }
    return 0 == balance;
}

#include <stdio.h>

int main() {
    // test 1
    {
        printf("Test-1: ");
        char const *input = "";
        int expected = 1;
        int actual = check_par(input);
        printf("%s\n", actual == expected ? "OK" : "FAIL");
    }

    // test 2
    {
        printf("Test-2: ");
        char const *input = "()";
        int expected = 1;
        int actual = check_par(input);
        printf("%s\n", actual == expected ? "OK" : "FAIL");
    }

    // test 3
    {
        printf("Test-3: ");
        char const *input = "(())";
        int expected = 1;
        int actual = check_par(input);
        printf("%s\n", actual == expected ? "OK" : "FAIL");
    }

    // test 4
    {
        printf("Test-4: ");
        char const *input = "()()";
        int expected = 1;
        int actual = check_par(input);
        printf("%s\n", actual == expected ? "OK" : "FAIL");
    }

    // test 5
    {
        printf("Test-5: ");
        char const *input = "(()())";
        int expected = 1;
        int actual = check_par(input);
        printf("%s\n", actual == expected ? "OK" : "FAIL");
    }

    // test 6
    {
        printf("Test-6: ");
        char const *input = ")(";
        int expected = 0;
        int actual = check_par(input);
        printf("%s\n", actual == expected ? "OK" : "FAIL");
    }

    // test 7
    {
        printf("Test-7: ");
        char const *input = ")";
        int expected = 0;
        int actual = check_par(input);
        printf("%s\n", actual == expected ? "OK" : "FAIL");
    }

    // test 8
    {
        printf("Test-8: ");
        char const *input = "(";
        int expected = 0;
        int actual = check_par(input);
        printf("%s\n", actual == expected ? "OK" : "FAIL");
    }

    // test 9
    {
        printf("Test-9: ");
        char const *input = "()(())()(";
        int expected = 0;
        int actual = check_par(input);
        printf("%s\n", actual == expected ? "OK" : "FAIL");
    }

    return 0;
}