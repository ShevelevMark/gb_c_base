/**
 * В файле .txt дана символьная строка не более 1000 символов. 
 * Необходимо заменить все буквы "а" на буквы "b" и наоборот, как заглавные, так и строчные. 
 * Результат записать в .txt.
 * **/

void a_to_b(char *str) {
    while (0 != *str) {
        switch(*str) {
            case 'a':
                *str = 'b';
                break;
            case 'b':
                *str = 'a';
                break;
            case 'A':
                *str = 'B';
                break;
            case 'B':
                *str = 'A';
                break;
        }
        ++str;
    }
}

#include <stdio.h>

int a_to_b_files(char const *input_file, char const *output_file) {
    char str[1001];
    {
        FILE *fd = fopen(input_file, "r");
        if (NULL == fd) {
            printf("Can't open file %s to read\n", input_file);
            return 1;
        }

        if (1 != fscanf(fd, "%1000s", str)) {
            printf("Can't read string from %s\n", input_file);
            fclose(fd);
            return 2;
        }

        fclose(fd);
    }

    a_to_b(str);

    {
        FILE *fd = fopen(output_file, "w");
        if (NULL == fd) {
            printf("Can't open file %s to write\n", output_file);
            return 1;
        }

        fprintf(fd, "%s", str);
        fclose(fd);
    }

    return 0;
}