// C program to scan and count the number of vowel characters in the given input file and print the characters (without duplicates)

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_VOWELS 5

// Function to check if a character is a vowel
bool isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    FILE *file;
    char ch;
    bool foundVowels[MAX_VOWELS] = {false};  // To track found vowels: [a, e, i, o, u]
    int vowelCount = 0;
    int vowelFrequency[MAX_VOWELS] = {0};   // To track the count of each vowel

    // Open the file for reading
    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    printf("Vowels found: ");
    
    // Read file character by character
    while ((ch = fgetc(file)) != EOF) {
        // Check if the character is a vowel
        if (isVowel(ch)) {
            char lowerCh = tolower(ch);
            vowelCount++;
            
            // Determine the vowel index (0 for 'a', 1 for 'e', etc.)
            int vowelIndex;
            if (lowerCh == 'a') vowelIndex = 0;
            else if (lowerCh == 'e') vowelIndex = 1;
            else if (lowerCh == 'i') vowelIndex = 2;
            else if (lowerCh == 'o') vowelIndex = 3;
            else if (lowerCh == 'u') vowelIndex = 4;

            // Increment the frequency count for the vowel
            vowelFrequency[vowelIndex]++;

            // Print the vowel the first time it is found
            if (!foundVowels[vowelIndex]) {
                foundVowels[vowelIndex] = true;
                printf("%c ", lowerCh);
            }
        }
    }

    // Close the file
    fclose(file);

    // Print the total vowel count and individual vowel frequencies
    printf("\nTotal number of vowels: %d\n", vowelCount);
    printf("Frequency of each vowel:\n");
    printf("a: %d\n", vowelFrequency[0]);
    printf("e: %d\n", vowelFrequency[1]);
    printf("i: %d\n", vowelFrequency[2]);
    printf("o: %d\n", vowelFrequency[3]);
    printf("u: %d\n", vowelFrequency[4]);

    return 0;
}
