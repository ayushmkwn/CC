
%{
	#include<stdio.h> 
	#include "pr6.tab.h"
	extern int yylval;
%}

%%
[0-9]+ {
          yylval=atoi(yytext);
          return NUMBER;
  
       }
[\t] ;
  
[\n] return 0;
  
. return yytext[0];
	  
%%

int yywrap()
{
 return 1;
}

/*
flex pr6.l
bison -d pr6.y
gcc lex.yy.c pr6.tab.c -w
a.exe 
1+2+3+4+5
*/