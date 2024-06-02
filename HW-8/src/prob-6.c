/**
 * Определить количество положительных элементов квадратной матрицы, 
 * превышающих по величине среднее арифметическое всех элементов главной диагонали.
 * Реализовать функцию среднее арифметическое главной диагонали.
 * **/

float diagonal_average(float **matrix, unsigned size) {
    float avg = 0.f;
    for (unsigned idx = 0; idx != size; ++idx)
        avg += matrix[idx][idx];
    return avg / (float)(size);
}

unsigned count_positive_less(float **matrix, unsigned size, float pivot) {
    unsigned cnt = 0u;
    for (int row_idx = 0; row_idx != size; ++row_idx)
        for (int col_idx = 0; col_idx != size; ++col_idx)
            cnt += 
                matrix[row_idx][col_idx] > 0 && 
                matrix[row_idx][col_idx] > pivot 
                ? 1 : 0;
    return cnt;
}

unsigned count_positive_less_diagonal_average(float **matrix, unsigned size) {
    return count_positive_less(matrix, size, diagonal_average(matrix, size));
}

