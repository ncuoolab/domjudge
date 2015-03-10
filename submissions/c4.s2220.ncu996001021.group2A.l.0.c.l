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
^[{]  {i++;printf("\t{");}
[{]   {i++;printf("{");}
[}]   {i--;printf("}");}
^[^}\t] {if (i>0)
       {
        printf("\t%s",yytext);
       }
       else
       printf("%s",yytext);
      }
\n    {tab(i-1);}
^[" "]* {printf("\t");}
^[\t]*  {printf("\t");}
%%

int main(){
    yylex();
    
    return 0;
}
    
