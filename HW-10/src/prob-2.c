/**
 * В файле .txt необходимо удалить все лишние пробелы (в начале предложения и сдвоенные пробелы). 
 * Для решения задачи разработать функцию. Результат записать в .txt.
 * **/

#include <stdbool.h>
#include <stdio.h>

bool bad_symbol_predicate(char *str, char *pos) {
    return ' ' == *pos && (str == pos || ' ' == pos[-1]); // плохой пробел лежит в начале строки, либо до него тоже пробел
}

char* trim_spaces(char *str) {
    char *vacant = str;
    while (0 != *vacant && !bad_symbol_predicate(str, vacant) ) ++vacant;
    if (0 != *vacant)
        for (char *swap = vacant + 1; 0 != *swap; ++swap)
            if (!bad_symbol_predicate(str, swap)) 
                *vacant++ = *swap;
    return str != vacant && ' ' == vacant[-1] ? (vacant - 1) : vacant; // проверка для удаления завершающего пробела
}

int trim_spaces_files(char const *input_file, char const *output_file) {
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

    char *end = trim_spaces(str);
    {
        FILE *fd = fopen(output_file, "w");
        if (NULL == fd) {
            printf("Can't open file %s to write\n", output_file);
            return 1;
        }

        fprintf(fd, "%.*s\n", (int)(end - str), str);

        fclose(fd);
    }

    return 0;
}