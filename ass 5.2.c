#include <stdio.h>
#include <stdlib.h>
int main() {
    char file_name[] = "data.bin";
    FILE *file;
    int data;
    file = fopen(file_name, "rb");
    if (file == NULL) {
        fprintf(stderr, "Failed to open file\n");
        exit(EXIT_FAILURE);
    }
    printf("Contents of %s:\n", file_name);
    while (fread(&data, sizeof(int), 1, file) == 1) {
        printf("%d ", data);
    }
    fclose(file);
    return 0;
}

