/**
 * Считать массив из 12 элементов и выполнить циклический сдвиг ВПРАВО на 4 элемента.
 * **/

/**
 * @brief Вспомогательная функция, которая обращает порядок элементов в массиве:
 * 1 2 3 4 5 -> 5 4 3 2 1
 * 
 * @param begin первый адрес промежутка
 * @param end   past-the-end адрес промежутка
 */
void reverse(int *begin, int *end) {
    if (begin == end) return;
    --end;
    while (begin < end) {
        int tmp = *begin;
        *begin = *end;
        *end = tmp;
        ++begin;
        --end;
    }
}

#include <stdio.h>

int main() {
    int nums[12];
    // read
    for (int *it = nums, *end = nums + 12; it != end; ++it)
        if (1 != scanf("%d", it)) {
            printf("Error");
            return 1;
        }

    // shift 4
    reverse(nums, nums + 12);
    reverse(nums, nums + 4);
    reverse(nums + 4, nums + 12);

    // write
    for (int *it = nums, *end = nums + 12; it != end; ++it)
        printf("%d ", *it);
    printf("\n");

    return 0;
}