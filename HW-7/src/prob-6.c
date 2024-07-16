/**
 * Дан массив из 10 элементов. 
 * Определить, какое число в массиве встречается чаще всего. Гарантируется, что такое число ровно 1.
 * 
 * Идея решения состоит в том, что после сортировки одинаковые числа будут идти подряд.
 * Тогда можно двигаться по отсортированному массиву и подсчитывать количество равных чисел, 
 * запоминая скользящий максимум. 
 * 
 * Хотя в решении используется сортировка пузырьком со сложностью О(N^2), но при использовании более быстрых 
 * сортировок можно добиться сложности O(N * log(N)), что лучше наивного решения.
 * **/

#include <stdio.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void buble_sort(int *begin, int *end) {
    if (begin == end) return;
    int sorted = 0;
    while (!sorted) {
        sorted = 1;
        for (int *it = begin; it != end - 1; ++it)
            if (*it > *(it + 1))
                swap(it, it + 1), sorted = 0;
    }
}

int main() {
    int nums[10];
    // read
    for (int *it = nums, *end = nums + 10; it != end; ++it)
        if (1 != scanf("%d", it)) {
            printf("Error");
            return 1;
        }

    // sort
    buble_sort(nums, nums + 10);

    /**
     * max_frq_number - число, которое до сих пор было самым частым
     * max_frq_number_cnt - количество повторений самого частого до сих пор числа
     * **/
    int max_frq_number = nums[0], max_frq_number_cnt = 1, curr_number = nums[0], curr_cnt = 1;
    for (int *it = nums + 1, *end = nums + 10; it != end; ++it)
        if (*it != curr_number) {
            if (curr_cnt > max_frq_number_cnt) {
                max_frq_number = curr_number;
                max_frq_number_cnt = curr_cnt;
            }
            curr_number = *it;
            curr_cnt = 1;
        } else
            ++curr_cnt;

    printf("%d\n", max_frq_number);
    return 0;
}