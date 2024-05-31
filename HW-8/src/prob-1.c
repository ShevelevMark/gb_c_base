/**
 * Написать только одну функцию, которая сортирует массив по возрастанию.
 * Необходимо реализовать только одну функцию, всю программу составлять не надо.
 * Строго согласно прототипу. Имя функции и все аргументы должны быть:
 *     void sort_array(int size, int a[])
 * Всю программу загружать не надо, только одну эту функцию. 
 * Можно просто закомментировать текст всей программы, кроме данной функции.
 * **/

/**
 * В файле, согласно заданию закомментирована функция main.
 * Из него нельзя будет собрать исполняемый файл приложенным Makefile.
 * **/

void asc_hoar_sort(int*, int*);

void sort_array(int size, int a[]) {
    asc_hoar_sort(a, a + size);
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int* asc_partition(int *l, int *r, int pivot) {
    while (l <= r) {
        while (*l < pivot) ++l;
        while (*r > pivot) --r;

        if (l >= r) break;
        swap(l, r);
        ++l, --r;
    }
    return r;
}

void asc_hoar_sort(int *l, int *r) {
    if (l < r) {
        int *split = asc_partition(l, r, *(l + (r - l) / 2));
        asc_hoar_sort(l, split);
        asc_hoar_sort(split + 1, r);
    }
}

/*#include <stdio.h>

int main() {
    int arr[7] = {1, 7, 9 ,-2, 4, 0, 8};

    for (int *it = arr, *end = arr + 7; it != end; ++it)
        printf("%d ", *it);
    printf("\n");

    asc_hoar_sort(arr, arr + 6);

    for (int *it = arr, *end = arr + 7; it != end; ++it)
        printf("%d ", *it);
    printf("\n");

    return 0;
}*/

