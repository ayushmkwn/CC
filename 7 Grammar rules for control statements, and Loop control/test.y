%{
#include <stdio.h>
#include <stdlib.h>
void yyerror(char *str);
int yylex();
%}
%token ID NUM FOR LE GE EQ NE OR AND IF ELSE
%right '='
%left OR AND
%left '<' '>' LE GE EQ NE
%left '+' '-'
%left '*' '/'
%right UMINUS
%left '!'

%%
SS : SS S
   | S {printf("Input accepted\n"); exit(0);}
   ;
S : E ';' S
  | IFST S
  | FORST S
  | FORST
  | IFST
  | E
  |
  ;
IFST : IF '(' E ')' S
     | IF '(' E ')' S ELSE S
     ;
FORST : FOR '(' E ';' E2 ';' E ')' DEF
      ;
DEF : '{' E ';' '}'
    | '{' S '}'
    |
    ;
E : E '=' E
  | E '+' E
  | E '-' E
  | E '*' E
  | E '/' E
  | E '<' E
  | E '>' E
  | E LE E
  | E GE E
  | E EQ E
  | E NE E
  | E OR E
  | E AND E
  | T
  |
  ;
E2 : E'<'E
   | E'>'E
   | E LE E
   | E GE E
   | E EQ E
   | E NE E
   | E OR E
   | E AND E
   |
   ;   
T : ID
  | NUM
  ;
%%
int main()
{
yyparse();
return 0;
}
void yyerror(char *str)
{
printf("Syntax Error:%s\n",str);
}