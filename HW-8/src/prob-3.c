/**
 * Написать только одну функцию, которая находит максимальный элемент в массиве.
 * Всю программу загружать не надо.
 * Прототип функции: int find_max_array(int size, int a[])
 * 
 * Будем предполагать, что массив не пустой
 * **/

inline 
int max_(int a, int b) {
    return a > b ? a : b;
}

int find_max_array(int size, int a[]) {
    int max = *a;
    for (int *it = a + 1, *end = a + size; it != end; ++it)
        max = max_(*it, max);
    return max;
}