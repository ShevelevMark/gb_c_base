/**
 * Известно, что шахматная доска имеет размерность 8х8 
 * и состоит из клеток 2х цветов, например, черного и белого. 
 * Каждая клетка имеет координату, состоящую из буквы и цифры. 
 * Горизонтальное расположение клетки определяется буквой от A до H, 
 * а вертикальное – цифрой от 1 до 8. 
 * Заметим, что клетка с координатой А1 имеет черный цвет. 
 * Требуется по заданной координате определить цвет клетки.
 * **/

#include <stdio.h>

int cell_color(char const *input_file, char const *output_file) {
    char row;
    int col;
    {
        FILE *fd = fopen(input_file, "r");
        if (NULL == fd) {
            printf("Can't open file to read %s\n", input_file);
            return 1;
        }

        if (1 != fscanf(fd, "%c", &row)) {
            printf("Can't read char from %s\n", input_file);
            return 2;
        }
        if (1 != fscanf(fd, "%d", &col)) {
            printf("Can't read int from %s\n", input_file);
            return 2;
        }
        fclose(fd);
    }

    char const *color = 0 == ((int)(row - 'A') + (int)(col - 1)) % 2 ?
        "BLACK" :
        "WHITE";

    {
        FILE *fd = fopen(output_file, "w");
        if (NULL == fd) {
            printf("Can't open file to write %s\n", output_file);
            return 1;
        }

        fprintf(fd, "%s", color);

        fclose(fd); 
    }

    return 0;
}
