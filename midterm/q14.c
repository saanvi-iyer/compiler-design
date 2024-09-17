// reverse alphabet transformation to decode a message

#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to translate a character based on the reverse alphabet
char reverseAlphabet(char c) {
    if (isalpha(c)) {
        // Convert to uppercase for uniformity
        c = toupper(c);
        // Calculate the reverse letter (A -> Z, B -> Y, etc.)
        return 'Z' - (c - 'A');
    }
    return c;  // Return non-alphabetic characters as is
}

// Function to translate the entire message
void translateMessage(char message[]) {
    int i;
    printf("Translated Message: ");
    for (i = 0; message[i] != '\0'; i++) {
        // Translate each character using reverseAlphabet function
        printf("%c", reverseAlphabet(message[i]));
    }
    printf("\n");
}

int main() {
    // Input message
    char message[] = "Z HXLFGH SLMLFI RH GL YV";

    // Display the original message
    printf("Original Message: %s\n", message);

    // Translate and display the message
    translateMessage(message);

    return 0;
}
