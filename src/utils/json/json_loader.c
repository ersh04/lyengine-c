#include <stdio.h>
#include <stdlib.h>

char* read_file_to_string(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Ошибка: не удалось открыть файл %s\n", filename);
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = malloc(length + 1);
    if (buffer == NULL) {
        printf("Ошибка: не удалось выделить память\n");
        fclose(file);
        return NULL;
    }

    size_t read_bytes = fread(buffer, 1, length, file);
    buffer[read_bytes] = '\0';

    fclose(file);
    return buffer;
}