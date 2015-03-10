%{
unsigned int count = 0, i;
%}
left    "{"
right   "}"
tab     [ \t]
enter   \n
word    [^\n\t{]+
line    {word}+
left2   {line}{left}

%%
{left2} {ECHO; count++;}
{left}  {for(i = 0; i<count; i++){printf("\t");} ECHO; count++;}
{right} {count--; for(i = 0; i<count; i++){printf("\t");} ECHO;}
{enter} {ECHO;}
{tab}   {}
{line}  {for(i = 0; i<count; i++){printf("\t");} ECHO;}
%%

int main(int argc, char *argv[]){
      yylex();
      return(0);
}
      
