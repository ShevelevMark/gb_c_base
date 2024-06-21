/**
 * Ввести с клавиатуры массив из 5 элементов, 
 * найти среднее арифметическое всех элементов массива.
 * **/

#include <stdio.h>

int main() {
    float nums[5];
    for (int *it = nums, *end = nums + 5; it != end; ++it)
        if (1 != scanf("%f", it)) {
            printf("Error");
            return 1;
        }
    
    float avg = 0.f;
    for (int *it = nums, *end = nums + 5; it != end; ++it)
        avg += *it;
    avg /= 5.f;
    printf("%.3f\n", avg);

    return 0; 
}