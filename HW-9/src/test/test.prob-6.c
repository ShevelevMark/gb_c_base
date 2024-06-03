/**
 * @file test.prob-6.c
 * @brief Файл с кодом для сборки запускаемой программы
 * **/

int last_a_count_files(char const *input_file, char const *output_file);

int main() {
    return last_a_count_files("in.txt", "out.txt");
}