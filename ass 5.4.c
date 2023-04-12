#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 1000
#define MAX_SEARCH_STRING_LENGTH 1000
#define MAX_LINE_LENGTH 1000

int main() {
    char file_name[MAX_FILE_NAME_LENGTH];
    char search_string[MAX_SEARCH_STRING_LENGTH];
    char line[MAX_LINE_LENGTH];
    FILE *file;
    printf("Enter the name of a file: ");
    fgets(file_name, MAX_FILE_NAME_LENGTH, stdin);
    file_name[strcspn(file_name, "\n")] = '\0';
    printf("Enter a search string: ");
    fgets(search_string, MAX_SEARCH_STRING_LENGTH, stdin);
    search_string[strcspn(search_string, "\n")] = '\0';
    file = fopen(file_name, "r");
    if (file == NULL) {
        fprintf(stderr, "Failed to open file\n");
        exit(EXIT_FAILURE);
    }
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        if (strstr(line, search_string) != NULL) {
            printf("%s", line);
        }
    }
    fclose(file);
    return 0;
}

