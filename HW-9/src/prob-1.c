/**
 * В файле .txt даны два слова не более 100 символов каждое, 
 * разделенные одним пробелом. Найдите только те символы слов, 
 * которые встречаются в обоих словах только один раз. 
 * Напечатайте их через пробел в файл .txt в лексикографическом порядке.
 * 
 * Отметим, что всего есть 26 английских букв, что позволит нам создавать 
 * таблицы символов фиксированного размера.
 * **/

void count_letters(char const *w, int *count) {
    while (0 != *w) {
        ++count[*w - 'a'];
        ++w;
    }
}

#include <stdbool.h>

void unique_common_letters(char const *w1, char const *w2, bool *ucl) {
    int letters1[26] = {0}, letters2[26] = {0};
    count_letters(w1, letters1);
    count_letters(w2, letters2);

    for (unsigned idx = 0; idx != 26; ++idx)
        if (1 == letters1[idx] && 1 == letters2[idx]) ucl[idx] = true;
}

#include <stdio.h>

int unique_common_letters_files(char const *input_file, char const *output_file) {
    char w1[101], w2[101];
    {
        FILE *fd = fopen(input_file, "r");
        if (NULL == fd) {
            printf("Can't open file %s to read\n", input_file);
            return 1;
        }

        if (2 != fscanf(fd, "%100s %100s", w1, w2)) {
            printf("Can't read data from %s\n", input_file);
            fclose(fd);
            return 2;
        }

        fclose(fd);
    }

    bool ucl[26];
    for (int idx = 0; idx != 26; ++idx)
        ucl[idx] = false;

    unique_common_letters(w1, w2, ucl);

    {
        FILE *fd = fopen(output_file, "w");
        if (NULL == fd) {
            printf("Can't open file %s to write\n", output_file);
            return 1;
        }

        for (int idx = 0; idx != 26; ++idx)
            if (ucl[idx])
                fprintf(fd, "%c ", (char)('a' + idx));

        fclose(fd);
    }

    return 0;
}