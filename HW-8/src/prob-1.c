/**
 * Написать только одну функцию, которая сортирует массив по возрастанию.
 * Необходимо реализовать только одну функцию, всю программу составлять не надо.
 * Строго согласно прототипу. Имя функции и все аргументы должны быть:
 *     void sort_array(int size, int a[])
 * Всю программу загружать не надо, только одну эту функцию. 
 * Можно просто закомментировать текст всей программы, кроме данной функции.
 * **/

/**
 * В файле, согласно заданию отсутсвует функция main. Она перенесена в 
 * файл test.prob-1.c
 * **/

void asc_hoar_sort(int*, int*);

void sort_array(int size, int a[]) {
    if (0 == size) return;          // проверка на пустоту массива
    // крайне важно, чтобы в функцию asc_hoar_sort отправлялся верный к разыменованию адрес, так как внутри происходит сравнение адресов
    asc_hoar_sort(a, a + size - 1); // адрес первого адресуемого элемента и последнего адресуемого элемента (НЕ past-the-end)
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * Неустойчивая партиция Хоара для сортировки по возрастанию (ascending).
 * @param l *int     допустимый к разыменованию первый адрес промежутка для партиции
 * @param r *int     допустимый к разыменованию последний адрес промежутка для партиции (НЕ past-the-end)
 * @param pivot int  значение, относительно которого элементы распределяются по принципу "сначала меньшие pivot, затем большие pivot"
 * 
 * @return *int      допустимый к разыменованию адрес последнего допустимого элемента промежутка "сначала меньшие", т.е. элемент *(return + 1) 
 *                   больше или равен pivot
 */
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

/**
 * Рекурсивный вызов быстрой сортировки Хоара.
 * @param l *int        допустимый к разыменованию первый адрес промежутка для сортировки
 * @param r *int        допустимый к разыменованию последний адрес промежутка для сортировки (НЕ past-the-end)
 * 
 * Вызов успешно пропустит сортировку для l == r (массив из одного элемента)
 */
void asc_hoar_sort(int *l, int *r) {
    if (l < r) {
        int *split = asc_partition(l, r, *(l + (r - l) / 2));
        asc_hoar_sort(l, split);
        asc_hoar_sort(split + 1, r);
    }
}
