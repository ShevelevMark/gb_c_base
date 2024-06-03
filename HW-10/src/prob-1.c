/*
 * В файле .txt записаны символы. Необходимо разработать функцию, 
 * которая меняет местами пары соседних символов не обращая внимание на символы пробел. 
 * Если количество символов нечетно (пробелы не считаем), то последний символ не меняем. 
 * Результат записать в файл .txt.
 *
 * Строка из английских букв, пробелов и знаков препинания. Не более 1000 символов.
 * **/

void swap(char *l, char *r) {
    char tmp = *l;
    *l = *r;
    *r = tmp;
}

void swap_adjacent(char *str) {
    char *left = str, *right = str;
    while(0 != *left) {
        while(0 != *left && ' ' == *left) ++left;
        if (0 == *left) break;

        right = left + 1;
        while(0 != *right && ' ' == *right) ++right;
        if (0 == *right) break;

        swap(left, right);
        left = right + 1;
    }
}

#include <stdio.h>

int swap_adjacent_files(char const *input_file, char const *output_file) {
    char str[1001];
    {
        FILE *fd = fopen(input_file, "r");
        if (NULL == fd) {
            printf("Can't open file %s to read\n", input_file);
            return 1;
        }

        if (1 != fscanf(fd, "%1000[^\n]s", str)) {
            printf("Can't read data from %s\n", input_file);
            fclose(fd);
            return 2;
        }

        fclose(fd);
    }

    swap_adjacent(str);

    {
        FILE *fd = fopen(output_file, "w");
        if (NULL == fd) {
            printf("Can't open file %s to write\n", output_file);
            return 1;
        }

        fprintf(fd, "%s\n", str);

        fclose(fd);
    }

    return 0;
}
