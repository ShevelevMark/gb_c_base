/**
 * Ввести с клавиатуры массив из 5 элементов, найти минимальный из них.
 * **/

#include <stdio.h>

inline
int min_(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int nums[5];
    for (int *it = nums, *end = nums + 5; it != end; ++it)
        if (1 != scanf("%d", it)) {
            printf("Error");
            return 1;
        }

    int min = nums[0];
    for (int *it = nums, *end = nums + 5; it != end; ++it)
        min = min_(min, *it);

    printf("%d\n", min);
    return 0;
}