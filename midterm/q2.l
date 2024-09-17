// Lex program to count the number of vowels and consonants in a given string

%{
#include <stdio.h>

int vowels = 0;
int consonants = 0;
%}

%%

[aAeEiIoOuU]    { vowels++; }           // Count vowels (both uppercase and lowercase)
[b-df-hj-np-tv-zB-DF-HJ-NP-TV-Z]  { consonants++; }   // Count consonants (both uppercase and lowercase)

.   ;   // Ignore other characters like digits, spaces, punctuation, etc.

%%

int main() {
    printf("Enter a string: ");
    yylex();  // Start lexical analysis

    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);
    return 0;
}
