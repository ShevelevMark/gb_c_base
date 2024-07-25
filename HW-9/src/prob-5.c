/**
 * В файле .txt дана строка слов, разделенных пробелами. 
 * Найти самое длинное слово и вывести его в файл .txt. 
 * Случай, когда самых длинных слов может быть несколько, не обрабатывать.
 *
 * Не совсем понятно "не обрабатывать". Означает ли это, что программа ничего 
 * не должна вывести в файл, если несколько слов с одинаково максимальной
 * длиной, или поведение функции не определено и может быть произвольным.
 *
 * Представленное решение записывает в файл первое найденное слово самой большой длины.
 * **/

#include <ctype.h>
#include <stdio.h>

char const * find_max_length_word(char const *str) {
    char const *word_it, *max_word_it = str;
    unsigned word_length, max_word_length = 0;
    while (0 != *str) {
        while (0 != *str && ' ' == *str) ++str;
        if (0 == *str) break;

        word_it = str;
        while (0 != *str && isalpha(*str)) ++str;
        word_length = (int)(str - word_it);

        if (word_length > max_word_length) {
            max_word_length = word_length;
            max_word_it = word_it;
        }
    }
    return 0 == max_word_length ? str : max_word_it;
}

int max_length_word_files(char const *input_file, char const *output_file) {
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

    char const *word_begin = find_max_length_word(str);
    if (0 == *word_begin) {
        printf("There's no any word in %s file\n", input_file);
        return 3;
    }
    char const *word_end = word_begin;
    while (0 != *word_end && isalpha(*word_end)) ++word_end;

    {
        FILE *fd = fopen(output_file, "w");
        if (NULL == fd) {
            printf("Can't open file %s to write", output_file);
            return 1;
        }

        fprintf(fd, "%.*s\n", (int)(word_end - word_begin), word_begin);
        fclose(fd);
    }

    return 0;
}