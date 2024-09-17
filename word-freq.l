%{
#include <stdio.h>
#include <string.h>

int count = 0;
char target_word[100]; // Assuming the word length won't exceed 100 characters
%}

%%
[a-zA-Z0-9]+ {
    if (strcmp(yytext, target_word) == 0) {
        count++;
    }
}
.|\n    // Ignore all other characters
%%

int yywrap() {
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s algorithm file.txt\n", argv[0]);
        return 1;
    }

    strcpy(target_word, argv[1]); // Copy the target word from command line argument
    FILE *file = fopen(argv[2], "r");

    if (!file) {
        perror("Error opening file");
        return 1;
    }

    yyin = file;
    yylex();

    printf("Frequency of '%s' in '%s': %d\n", target_word, argv[2], count);

    fclose(file);
    return 0;
}
