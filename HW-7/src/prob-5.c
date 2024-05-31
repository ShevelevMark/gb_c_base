/**
 * Считать массив из 10 элементов и отобрать в другой массив все числа, 
 * у которых вторая с конца цифра (число десятков) – ноль.
 *
 * Приведённый тест:
 * In:  40 105 203 1 14 1000 22 33 44 55
 * Out: 105 203 1 1000
 * Показывает, что однозначные числа считаются верными
 * **/

/**
 * @brief Вспомогательная функция, которая копирует нужные числа в другой массив
 * 
 * @param src_begin адрес начала массива-источника чисел
 * @param src_end   адрес концаа массива-источника чисел
 * @param dst_begin адрес начала массива-приёмника чисел
 * @return int*     адрес первого элемента в массиве-приёмнике, который не указывает на правильное число (past-the-end)
 *
 * Функция подразумевает, что память для считывания и память для записи не пересекаются
 * В массиве приёмнки должно быть достаточно места для записи
 */
int* filter(int const *src_begin, int const *src_end, int *dst_begin) {
    for (int const *it = src_begin; it != src_end; ++it)
        if (0 == (*it / 10) % 10)
            *dst_begin++ = *it;
    return dst_begin;
}

#include <stdio.h>

int main() {
    int src[10], dst[10];
    // read
    for (int *it = src, *end = src + 10; it != end; ++it)
        if (1 != scanf("%d", it)) {
            printf("Error");
            return 1;
        }

    int *dst_end = filter(src, src + 10, dst);
    // write
    for (int *it = dst; it != dst_end; ++it)
        printf("%d ", *it);
    printf("\n");

    return 0;
}