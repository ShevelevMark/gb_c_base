/**
 * Считать массив из 10 элементов и отсортировать его по последней цифре.
 *
 * Задача решена для неотрицательных чисел.
 * **/

#include <stdio.h>

int main() {
    int nums[10];
    // read
    for (int *it = nums, *end = nums + 10; it != end; ++it)
        if (1 != scanf("%d", it)) {
            printf("Error");
            return 1;
        }

    // корзины для чисел с различными последними цифрами
    int buckets[10][10]; // 10 цифр и для каждой массив из 10 элементов (т.к. больше быть не может, всего 10 чисел)
    int bucket_size[10] = {0}; // количество чисел в бакете
    for (int *it = nums, *end = nums + 10; it != end; ++it)
        buckets[*it % 10][bucket_size[*it % 10]++] = *it;
    
    for (int digit = 0; digit != 10; ++digit)
        for (int idx = 0; idx != bucket_size[digit]; ++idx)
            printf("%d ", buckets[digit][idx]);
    printf("\n");

    return 0;
}