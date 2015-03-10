%{
#include <stdio.h> 
#include <string.h>

int i=0;

void tab(int num)
{ 
  int j;
  printf("\n");
  for (j=1;j<=num;j++)
  {
    printf("\t");
  }
}
%}

space [" "]

%%

[{]   {printf("{");i++;}
[}]   {printf("\b\b\b\b\b\b\b\b}");i--;}
\n    {tab(i);}
^[" "]* {}
^[\t]   {}
%%

int main(){
    yylex();
    
    return 0;
}
    
