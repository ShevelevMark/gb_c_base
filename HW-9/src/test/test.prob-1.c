/**
 * @file test.prob-1.c
 * @brief Файл с запускаемой программой для тестирования 
 * **/

int unique_common_letters_files(char const *input_file, char const *output_file);

int main() {
    return unique_common_letters_files("in.txt", "out.txt");
}