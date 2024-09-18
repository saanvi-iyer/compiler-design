/* Lex program to remove uppercase letters and whitespace from the input */

%{
%}
%%
[A-Z]+ ;
[ \t\n]+ ; //removes space, tabspace, newline space, comma and double quote
%%
int yywrap()
{
return 1;
}
int main()
{
yyin=fopen("input.txt","r");
yylex();
fclose(yyin);
}
