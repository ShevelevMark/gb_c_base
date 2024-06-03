/**
 * В файле .txt дано предложение. Необходимо определить, сколько слов заканчиваются на букву 'а'. 
 * Ответ записать в файл .txt.
 * **/

unsigned last_a_count(char const *str) {
    if (0 == *str) return 0;
    unsigned cnt = 0;
    char const *curr = str, *next = str + 1;
    while (0 != *next) {
        if (' ' == *next && ('a' == *curr || 'A' == *curr)) ++cnt;
        ++curr, ++next;
    }
    if ('a' == *curr || 'A' == *curr) ++cnt;
    return cnt;
}

#include <stdio.h>

int last_a_count_files(char const *input_file, char const *output_file) {
    char str[1001];
    {
        FILE *fd = fopen(input_file, "r");
        if (NULL == fd) {
            printf("Can't open file %s to read\n", input_file);
            return 1;
        }

        if (1 != fscanf(fd, "%1000[^\n]s", str)) {
            printf("Can't read string from %s\n", input_file);
            fclose(fd);
            return 2;
        }

        fclose(fd);
    }

    unsigned cnt = last_a_count(str);

    {
        FILE *fd = fopen(output_file, "w");
        if (NULL == fd) {
            printf("Can't open file %s to write\n", output_file);
            return 1;
        }

        fprintf(fd, "%u", cnt);
        fclose(fd);
    }

    return 0;
}