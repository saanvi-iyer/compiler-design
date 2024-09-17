// C program to scan and count the number of lines in the given input file that has exactly five words.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LEN 1000

// Function to count the number of words in a line
int countWords(char *line) {
    int count = 0, inWord = 0;
    for (int i = 0; line[i] != '\0'; i++) {
        if (!isspace(line[i])) {
            if (!inWord) {
                count++;  // Starting a new word
                inWord = 1;
            }
        } else {
            inWord = 0;  // Ending a word
        }
    }
    return count;
}

int main() {
    FILE *file;
    char line[MAX_LINE_LEN];
    int fiveWordLinesCount = 0;

    // Open the file for reading
    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    printf("Lines with exactly 5 words:\n");

    // Read the file line by line
    while (fgets(line, sizeof(line), file)) {
        // Count the number of words in the line
        int wordCount = countWords(line);
        if (wordCount == 5) {
            // Print the line if it has exactly 5 words
            printf("%s", line);
            fiveWordLinesCount++;
        }
    }

    // Close the file
    fclose(file);

    // Print the total count of lines with exactly 5 words
    printf("\nTotal number of lines with exactly 5 words: %d\n", fiveWordLinesCount);

    return 0;
}
