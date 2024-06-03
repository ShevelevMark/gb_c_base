/**
 * В файле .txt строка из маленьких и больших английских букв, знаков препинания и пробелов. 
 * Требуется удалить из нее повторяющиеся символы и все пробелы. Результат записать в файл .txt.
 * Строка из маленьких и больших английских букв, знаков препинания и пробелов. Размер строки не более 1000 символов.
 * 
 * Из задания следует, что нужно удалить любые повторяющиеся символы, включая знаки препинания.
 * Пробелы же должны быть удалены полностью.
 * "  Abra mabra cadabra!  Mamma mia! Oh, didn't notice you...  Xander, hello! " -> "Abramcd!MiOh,n'toeyu.Xl"
 *
 * Будем предполагать, что файл не пуст и в нём содержатся только символы кодировки ASCII - 127 кодов.
 * Последнее позволит нам отслеживать повторения с помощью таблицы.
 * **/

#include <stdbool.h>

void map_string(char const *str, char *mapped) {
    bool set[128];
    for (unsigned idx = 0; idx != 128; ++idx)
        set[idx] = false;

    while (0 != *str) {
        if (' ' == *str || set[(int)(*str)]) { ++str; continue; }
        set[(int)(*str)] = true;
        *mapped++ = *str++;
    }
    *mapped = 0;
}

#include <stdio.h>

int map_string_files(char const *input_file, char const *output_file) {
    char str[1001], mapped[128]; // результирующая строка не может быть более 127 символов
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

    map_string(str, mapped);

    {
        FILE *fd = fopen(output_file, "w");
        if (NULL == fd) {
            printf("Can't open file %s to write", output_file);
            return 1;
        }

        fprintf(fd, "%s\n", mapped);
        fclose(fd);
    }

    return 0;
}


