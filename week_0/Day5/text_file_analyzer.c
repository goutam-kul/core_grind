#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// function prototypes 
int count_characters(const char *string);
int count_words(const char *string);
int count_lines(const char *string);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error: Empty file\n");
        return 1;
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);

    // Allocate buffer for file content
    char *buffer = (char *)malloc(size + 1);
    if (buffer == NULL) {
        printf("Error: Memory allocation failed\n");
        fclose(file);
        return 1;
    }

    size_t read_size =  fread(buffer, sizeof(char), size, file);
    buffer[read_size] = '\0';

    // close the file 
    fclose(file);

    printf("No. of characters (non-space): %d\n", count_characters(buffer));
    printf("No. of words: %d\n", count_words(buffer));
    printf("No. of lines: %d\n", count_lines(buffer));

    // free buffer
    free(buffer);
    return 0;
}

// count characters function 
int count_characters(const char *string) {
    int count = 0;
    if (string == NULL || *string == '\0') {
        printf("No. of characters = 0\n");
    }

    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] != ' ' && string[i] != '\n' && string[i] != '\t') {
            count++;
        }
    }

    return count;
}

// count words  function 
int count_words(const char *string) {
    int count = 0;
    int in_word = 0;

    if (string == NULL || *string == '\0') {
        return 0;
    }

    while (*string) {
        if (*string == ' ' || *string == '\n' || *string == '\t') {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            count++;
        }
        string++;
    }
    
    return count;
}

// count lines function 
int count_lines(const char *string) {
    int count = 0;

    if (string == NULL || *string == '\0') {
        return 0;
    }

    while(*string) {
        if (*string == '\n') {
            count++;
        }
        string++;
    }

    // If line doesn't ends with '\n'
    if (*(string - 1) != '\n' && *(string - 1) != '\0') {
        count++;
    }

    return count;
    
}

