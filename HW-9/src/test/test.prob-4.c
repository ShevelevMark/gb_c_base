/**
 * @file test.prob-4.c
 * @brief  Файл с кодом для сборки запускаемой программы  
 * **/

int map_string_files(char const *input_file, char const *output_file);

int main() {
    return map_string_files("in.txt", "out.txt");
}