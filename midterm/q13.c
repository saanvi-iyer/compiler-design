// C program to scan and count the number of words with length of 4 in the given input file and print the words

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100

// Function to check if a character is a delimiter (space, punctuation, etc.)
int isDelimiter(char c) {
    return (isspace(c) || ispunct(c));
}

int main() {
    FILE *file;
    char word[MAX_WORD_LEN];
    int wordLength = 0;
    int wordCount = 0;
    char ch;
    
    // Open the file for reading
    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    printf("Words with length 4:\n");

    // Read the file character by character
    while ((ch = fgetc(file)) != EOF) {
        // If we encounter a delimiter (space, punctuation, newline, etc.)
        if (isDelimiter(ch)) {
            if (wordLength == 4) {  // Check if the current word length is 4
                word[wordLength] = '\0';  // Null terminate the word
                printf("%s\n", word);  // Print the word
                wordCount++;
            }
            wordLength = 0;  // Reset for the next word
        } else {
            if (wordLength < MAX_WORD_LEN - 1) {  // Add character to the word
                word[wordLength++] = ch;
            }
        }
    }

    // Check the last word (in case the file doesn't end with a delimiter)
    if (wordLength == 4) {
        word[wordLength] = '\0';
        printf("%s\n", word);
        wordCount++;
    }

    // Close the file
    fclose(file);

    // Print the total count of words with length 4
    printf("Total number of words with length 4: %d\n", wordCount);

    return 0;
}
