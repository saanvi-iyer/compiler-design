%{

/*
1.Request input of an even and an odd number
2.indicate input characteristic : Even/Odd
3.check for input's correctness and print result
*/

#include <stdlib.h>
#include <stdio.h>

int number_1;
int number_2;

%}


number_sequence [0-9]*

%%

{number_sequence}[0|2|4|6|8] {
    printf("Even number [%d]",yyleng);
    return 1;
    }
{number_sequence}[1|3|5|7|9] {
    printf("Odd number [%d]",yyleng);
    return 1;
    }
%%

int yywrap()
{
  return 1;
}
 
int main()
{
  printf("\nInput two numbers\n");
  number_1 = yylex();
  number_2 = yylex();
  return 1;
}
