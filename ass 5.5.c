#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_LINE_LENGTH 1000
#define NUM_LETTERS 26
int main() {
    char data_file_name[] = "data.txt";
    char statistics_file_name[] = "statistics.txt";
    char line[MAX_LINE_LENGTH];
    int letter_counts[NUM_LETTERS] = {0},i;
    FILE *data_file, *statistics_file;
    data_file = fopen(data_file_name, "r");
    if (data_file == NULL) {
        fprintf(stderr, "Failed to open data file\n");
        exit(EXIT_FAILURE);
    }
    while (fgets(line, MAX_LINE_LENGTH, data_file) != NULL) {
        for (i = 0; line[i] != '\0'; i++) {
            if (isalpha(line[i])) {
                letter_counts[tolower(line[i]) - 'a']++;
            }
        }
    }
    fclose(data_file);
    statistics_file = fopen(statistics_file_name, "w");
    if (statistics_file == NULL) {
        fprintf(stderr, "Failed to open statistics file\n");
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < NUM_LETTERS; i++) {
        fprintf(statistics_file, "%c: %d\n", 'a' + i, letter_counts[i]);
    }
    fclose(statistics_file);
    return 0;
}
