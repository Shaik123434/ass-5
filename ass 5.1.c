#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 1024
int main() {
    FILE *input_file, *error_log_file;
    char buffer[BUFFER_SIZE];
    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error opening input file\n");
        exit(1);
    }
    error_log_file = fopen("error_log.txt", "w");
    if (error_log_file == NULL) {
        fprintf(stderr, "Error opening error log file\n");
        exit(1);
    }
    while (fgets(buffer, BUFFER_SIZE, input_file) != NULL) {
        if (strstr(buffer, "error") != NULL) {
            fputs(buffer, error_log_file);
        }
    }
    fclose(input_file);
    fclose(error_log_file);
    error_log_file = fopen("error_log.txt", "r");
    if (error_log_file == NULL) {
        fprintf(stderr, "Error opening error log file\n");
        exit(1);
    }
    printf("Contents of error log file:\n");
    while (fgets(buffer, BUFFER_SIZE, error_log_file) != NULL) {
        printf("%s", buffer);
    }
    fclose(error_log_file);
    return 0;
}
