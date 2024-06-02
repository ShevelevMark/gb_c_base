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

void even_odd_partition(int *begin, int *end) {
    int *wall = begin, *even = begin;
    while (even != end) {
        while (even != end && 1 == *even % 2) ++even;
        if (even == end) break;
        while (even > wall + 1) {
            swap(even, even - 1);
            --even;
        }
        wall = even;
        ++even;
    }
}
