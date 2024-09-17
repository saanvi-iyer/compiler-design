// Lex program to remove uppercase letters and whitespace from the input

%{
#include <stdio.h>
%}

%%

[A-Z]      ;               // Ignore uppercase letters
[ \t\n]    ;               // Ignore whitespace characters (space, tab, newline)
.          { printf("%c", yytext[0]); }  // Print all other characters

%%

int main() {
    yylex();
    return 0;
}
