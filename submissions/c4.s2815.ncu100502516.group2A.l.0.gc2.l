%{
int count = 0;
int tmp = 0;
%}
word [^\n\t"{""}"]
break   [\t ]
%%
^(" ")+$	{int i = 0; for(i; i < count; i++){printf("\t");} printf("\n"); count = tmp;}
^{break}+       {}
{word}  {int i = 0; for(i; i < count; i++){printf("\t");} ECHO; count = 0;}
"{"    {int i = 0; for(i; i < count; i++){printf("\t");} ECHO; tmp++; count = 0;}
"}"    {tmp--; count--; int i = 0; for(i; i < count; i++){printf("\t");} ECHO; count = 0;}
\n      {ECHO; count = tmp;}
.       {ECHO;}
%%
int main(char *argc)
{
        yylex();
        return 0;
}
