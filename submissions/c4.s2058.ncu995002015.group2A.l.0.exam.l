%{
unsigned int count = 0, i;
%}
left    "{"
right   "}"
tab     [ \t]
enter   \n
word    [^\n{\t]+
%%
{left}  {ECHO; count++;}
{right} {count--; for(i = 0; i<count; i++){printf("\t");} ECHO;}
{enter} {ECHO;}
{tab}   {}
{word}  {for(i = 0; i<count; i++){printf("\t");} ECHO;}
%%

int main(int argc, char *argv[]){
      yylex();
      return(0);
}
      
