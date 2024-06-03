/**
 * В файле .txt записан полный адрес файла (возможно, без расширения). 
 * Необходимо изменить его расширение на ".html" и записать результат в файл .txt.
 * Строка состоящая из символов: a-z, A-Z, 0-9, /
 *
 * Будем предполагать, что размер строки не более 1000 символов.
 *
 * Так как в задаче не описано, что есть "расширение", определим его как набор 
 * букв и цифр и предваряющей точки в конце строки: *\.[a-z|0-9]+$
 * Будем предполагать, что не встречается неверных строк: "hello/", "abba/.ada", "abba/ada.", "abba/a....b". 
 * Т.е. строка всегда завершается символом или комбинацией символа и раширения \.[a-z|0-9]+
 * **/

char* ext(char *str) {
    char *ext_ = str;
    while (0 != *str) {
        while (0 != *str && '.' != *str) ++str;
        if (0 == *str) return str;
        ext_ = str++;
        while (0 != *str && '.' != *str && '/' != *str) ++str;
    }
    return ext_;
}

#include <string.h>

void change_ext(char *str) {
    char *ext_ = ext(str);
    strcpy(ext_, ".html");
}

#include <stdio.h>

int change_ext_files(char const *input_file, char const *output_file) {
    char str[1006]; // +5 символов на расширение .html 
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

    change_ext(str);
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