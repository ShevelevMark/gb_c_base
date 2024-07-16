/**
 * Написать только одну функцию, которая ставит в начало массива все четные
 * элементы, а в конец – все нечетные. Не нарушайте порядок следования чисел
 * между собой. Строго согласно прототипу:
 *     void sort_even_odd(int n, int a[])
 * **/

void even_odd_partition(int *begin, int *end);

void sort_even_odd(int n, int a[]) {
    even_odd_partition(a, a + n);
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * Идея алгоритма:
 * odd - уазывает на последний нечётный
 * even - на первый чётный за нечётным
 * Затем even движется назад, переставляя элементы, пока не достигнет odd
 * Важно! end - это past-the-end адрес, 
 *    он никогда не будет разыменован, но с ним могут сравниваться другие действительные адреса
 * **/
void even_odd_partition(int *begin, int *end) {
    int *odd = begin, *even = begin;
    while (1) {
        while (odd != end && 0 == *odd % 2) ++odd;
        if (odd == end) break;
        even = odd + 1;

        while (even != end && 1 == *even % 2) ++even;
        if (even == end) break;
        while (even > odd) {
            swap(even, even - 1);
            --even;
        }
        ++odd;
    }
}
