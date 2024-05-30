/**
 * Составить функцию, которая определяет сумму всех чисел от 1 до N и привести
 * пример ее использования.
 *
 * Заметим, что сумму от 1 до N можно вычислить по формуле арифметической прогрессии:
 * n * (a1 + an) / 2. Вероятно в задании, всё же, подразумевается цикл. 
 * **/

int consecutive_sum(int max) {
    int sum = 0;
    for (int num = 1; num != max + 1; ++num)
        sum += num;
    return sum;
}

#include <stdio.h>

int main() {
    // test 1
    {
        printf("Test-1: ");
        int in_max = 100, expected = 100 / 2 * 101;
        int actual = consecutive_sum(in_max);
        printf("%s\n",actual == expected ? "OK" : "FAIL");
    }

    // test 2
    {
        printf("Test-2: ");
        int in_max = 1, expected = 1;
        int actual = consecutive_sum(in_max);
        printf("%s\n",actual == expected ? "OK" : "FAIL");
    }

    // test 3
    {
        printf("Test-3: ");
        int in_max = 305, expected = 306 / 2 * 305;
        int actual = consecutive_sum(in_max);
        printf("%s\n",actual == expected ? "OK" : "FAIL");
    }

    return 0;
}