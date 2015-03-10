%{
unsigned int count = 0, i;
%}
left    "{"
right   "}"
tab     [\t ]
blank   " "
enter   \n
word    [^\n\t{} ]+
line    ({word}|{blank})+
left2   {line}{left}

%%
{right} {count--; for(i = 0; i<count; i++){printf("\t");} ECHO;}
{left2} {for(i = 0; i<count; i++){printf("\t");} ECHO; count++;}
{left}  {for(i = 0; i<count; i++){printf("\t");} ECHO; count++;}
{enter} {ECHO;}
{tab}   {}
{line}  {for(i = 0; i<count; i++){printf("\t");} ECHO;}
%%

int main(int argc, char *argv[]){
      yylex();
      return(0);
}
      
