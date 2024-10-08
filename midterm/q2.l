/* Lex program to count the number of vowels and consonants in a given string */
%{
    int vow_count=0;
    int const_count =0;
%}
 
%%
[aeiouAEIOU] {vow_count++;}
[a-zA-Z] {const_count++;}
%%
int yywrap()
{
  return 1;
}
int main()
{
  printf("Enter the string of vowels and consonants:");
  char myString[100];
  fgets (myString, sizeof(myString), stdin);
  yy_scan_string(myString);
  yylex();
  printf("Number of vowels are:  %d\n", vow_count);
  printf("Number of consonants are:  %d\n", const_count);
}
