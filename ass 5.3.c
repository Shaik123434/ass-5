#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 1000
int main() {
    char input_file_name[] = "input.txt";
    char output_file_name[] = "output.txt";
    char line[MAX_LINE_LENGTH];
    FILE *input_file, *output_file;
    input_file = fopen(input_file_name, "r");
    if (input_file == NULL) {
        fprintf(stderr, "Failed to open input file\n");
        exit(EXIT_FAILURE);
    }
    output_file = fopen(output_file_name, "w");
    if (output_file == NULL) {
        fprintf(stderr, "Failed to open output file\n");
        exit(EXIT_FAILURE);
    }
    while (fgets(line, MAX_LINE_LENGTH, input_file) != NULL) {
        char *pos;
        while ((pos = strstr(line, "red")) != NULL) {
            strcpy(pos, "blue");
            pos += strlen("blue");
            strcpy(pos, pos + strlen("red"));
        }
        fprintf(output_file, "%s", line);
    }
    fclose(input_file);
    fclose(output_file);
    return 0;
}

