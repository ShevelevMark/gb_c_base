/**
 * Составить функцию, которая меняет в массиве минимальный и максимальный элемент местами. 
 * Прототип функции
 *     void change_max_min(int size, int a[])
 *
 * Будем предполагать, что в массиве ровно один минимальный и ровно один максимальный
 * и они не совпадают, так как подробно в условии этот краевой случай не описан
 * **/

/**
 * Вспомогательные функции
 * **/
void swap(int*,int*);
int* max_element(int *begin, int *end);
int* min_element(int *begin, int *end);

void change_max_min(int size, int a[]) {
    swap(max_element(a, a + size), min_element(a, a + size));
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

inline
int* max_indirect(int *a, int *b) {
    return *a > *b ? a : b;
}
int* max_element(int *begin, int *end) {
    int *max_it = begin;
    for (int *it = begin + 1; it != end; ++it)
        max_it = max_indirect(it, max_it);
    return max_it;
}

inline
int* min_indirect(int *a, int *b) {
    return *a < *b ? a : b;
}
int* min_element(int *begin, int *end) {
    int *min_it = begin;
    for (int *it = begin + 1; it != end; ++it)
        min_it = min_indirect(it, min_it);
    return min_it;
}
