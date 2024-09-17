// C program to scan and count the number of consonant characters in the given input file and print the characters (without duplicates)

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_CHAR 256

// Function to check if a character is a consonant
bool isConsonant(char c) {
    c = tolower(c);
    return (c >= 'a' && c <= 'z') && !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    FILE *file;
    char ch;
    bool found[MAX_CHAR] = { false };  // To track found consonants
    int consonantCount = 0;
    
    // Open the file for reading
    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }
    
    printf("Consonants found: ");
    
    // Read file character by character
    while ((ch = fgetc(file)) != EOF) {
        // If it's a consonant and not found before, mark it as found and print it
        if (isConsonant(ch) && !found[(unsigned char)tolower(ch)]) {
            found[(unsigned char)tolower(ch)] = true;
            printf("%c ", tolower(ch));  // Print the consonant
        }
        // Increment consonant count if it's a consonant
        if (isConsonant(ch)) {
            consonantCount++;
        }
    }
    
    // Close the file
    fclose(file);
    
    // Print consonant count
    printf("\nTotal number of consonants: %d\n", consonantCount);
    
    return 0;
}
