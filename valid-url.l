%{
   #include <stdio.h>
   int valid = 0;
%}

%%
(http|https):\/\/([a-zA-Z0-9\-]+\.)+[a-zA-Z]{2,}(\/[a-zA-Z0-9\-._~:/?#[\]@!$&'()+,;%=])? { valid = 1; return 1; }
%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter a URL: ");
    yylex();
    if (valid == 1) {
        printf("It is a valid URL\n");
    } else {
        printf("It is not a valid URL\n");
    }
    return 0;
}
