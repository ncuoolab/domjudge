%{
unsigned int count = 0, i;
%}
left    "{"
left2   {line}{left}
left3   {left2}{blank}*\n
right   "}"
tab     [\t ]
blank   " "
enter   \n
word    [^\n\t{} ]+
line    {word}+({blank}|{tab})*{word}*
line2   {left2}{line}{right}

%%
{right} {count--; for(i = 0; i<count; i++){printf("\t");} ECHO;}
{left3} {for(i = 0; i<count; i++){printf("\t");} ECHO; count++;}
{line2} {for(i = 0; i<count; i++){printf("\t");} ECHO; }
{left}  {for(i = 0; i<count; i++){printf("\t");} ECHO; count++;}
{enter} {ECHO;}
{tab}   {}
{line}  {for(i = 0; i<count; i++){printf("\t");} ECHO;}
%%

int main(int argc, char *argv[]){
      yylex();
      return(0);
}
      
