/**
 * В файле .txt дана строка, не более 1000 символов, содержащая буквы, целые числа и иные символы. 
 * Требуется все числа, которые встречаются в строке, поместить в отдельный целочисленный массив. 
 * Например, если дана строка "data 48 call 9 read13 blank0a", то в массиве числа 48, 9, 13 и 0. 
 * Вывести массив по возрастанию в файл .txt.
 * 
 * Разобьём задачу на подзадачи: 
 *     1) прочитать данные из файла;
 *     2) преобразовать строку в набор чисел;
 *     3) отсортировать массив;
 *     4) записать результат в файл.
 * 
 * Для преобразования и сортировки будем использовать дополнительные функции.
 * Основная функция будет читать данные и записывать их.
 * **/

#include <stdio.h>

/**
 * @brief Функция считывает данные из строки с цифрами и буквами в числа
 * 
 * @param str        входящая строка, не будет изменена
 * @param nums       массив целых чисел, будет перезаписан, должен содержать достаточно памяти для всех чисел
 * @return unsigned  количество успешно прочитанных чисел
 * **/
unsigned map_string_to_nums(char const *str, int *nums);

/**
 * @brief Сортитует целые числа в промежутке адресов [first, last], оба адреса должны быть верными для разыменования
 * 
 * @param first адрес первого числа в промежутке для сортировки 
 * @param last  адрес последнего числа в промежутке для сортировки
 */
void hoar_sort(int *first, int *last);

int map_string_to_numbers_files(char const *input_filename, char const *output_file) {
    char input_string[1002];
    input_string[0] = 'a'; // костыль для функции map_string_to_nums - неверно работает, если строка начинается с цифры
    int nums[500]; // в строке из 1000 символов может быть не более 500 чисел, разделённых пробелами
    {
        FILE *fd = fopen(input_filename, "r");
        if (NULL == fd) {
            printf("Can't open file %s to read\n", input_filename);
            return 1;
        }

        if (1 != fscanf(fd, "%1000[^\n]s", input_string + 1)) { // + 1 - это костыль для функции map_string_to_nums, строка input_string всегда содержит букву первым символовм
            printf("Can't read data from file %s\n", input_filename);
            fclose(fd);
            return 2;
        }

        fclose(fd);
    }
    
    unsigned nums_cnt = map_string_to_nums(input_string, nums);
    if (0 == nums_cnt) {
        printf("No numbers read\n");
        return 3;
    }

    hoar_sort(nums, nums + nums_cnt - 1);

    {
        FILE *fd = fopen(output_file, "w");
        if (NULL == fd) {
            printf("Can't open file %s to write\n", output_file);
            return 1;
        }

        for (unsigned idx = 0; idx != nums_cnt; ++idx)
            fprintf(fd, "%d ", nums[idx]);
        fclose(fd);
    }

    return 0;
}

unsigned map_string_to_nums(char const *str, int *nums) {
    unsigned nums_cnt = 0, offset = 0, offset_before = 0;
    while (1 == sscanf(str += offset, "%*[^0123456789]%n%d%n", &offset_before, nums + nums_cnt, &offset)) { 
        if ('-' == *(str + offset_before - 1)) 
            nums[nums_cnt] = -nums[nums_cnt];
        ++nums_cnt;
    }
    return nums_cnt;
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int* partition(int *l, int *r, int pivot) {
    while (l <= r) {
        while (*l < pivot) ++l;
        while (*r > pivot) --r;

        if (l >= r) break;
        swap(l, r);
        ++l, --r;
    }
    return r;
}

void hoar_sort(int *l, int *r) {
    if (l < r) {
        int *split = partition(l, r, *(l + (r - l) / 2));
        hoar_sort(l, split);
        hoar_sort(split + 1, r);
    }
}
