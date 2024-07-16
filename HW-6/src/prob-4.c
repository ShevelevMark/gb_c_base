/**
 * Дана последовательность целых чисел через пробел, завершающаяся числом 0.
 * Выведите все нечетные числа из этой последовательности, сохраняя их порядок.
 *
 * Так как задача читает данные из стандартного потока, то проверялась вводом данных из файла
 * через перенаправления потока вручную. В файле исходного кода тестов нет.
 * **/

#include <stdio.h>

void odd_numbers(void) {
    int num;
    if ( 1 != scanf("%d", &num) || 0 == num) // "база рекурсии"
        return;
    
    if (1 == num %2)         // основное действие 
        printf("%d ", num);
    odd_numbers();           // рекурсивный вызов
}

int main() {
    odd_numbers();
    return 0;
}