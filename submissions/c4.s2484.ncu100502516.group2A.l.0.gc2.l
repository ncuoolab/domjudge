%{
int count = 0;
%}
word [a-zA-Z]
%%
("\t")  {}
^"{"    {int i = 0; for(i; i < count; i++){printf("\t");} ECHO; count++;}
^"}"    {count--; int i = 0; for(i; i < count; i++){printf("\t");} ECHO;}
("{")   {ECHO;count++;}
("}")   {count--;ECHO;}
^{word}|"/"     {int i = 0; for(i; i < count; i++){printf("\t");} ECHO;}
.|\n    {ECHO;}
%%
int main(char *argc)
{
        yylex();
        return 0;
}
