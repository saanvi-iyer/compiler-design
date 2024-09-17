%{
#include <stdio.h>
%}

%option noyywrap

%%

"<"[^">"]*">"  { printf("HTML Tag: %s\n", yytext); }
.|\n           { /* ignore other characters */ }

%%

int main(int argc, char **argv)
{
    if(argc > 1)
    {
        FILE *file = fopen(argv[1], "r");
        if(!file)
        {
            perror("File opening failed");
            return 1;
        }
        yyin = file;
    }

    yylex();
    return 0;
}
