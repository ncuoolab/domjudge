%{
unsigned int count = 0, i;
%}
left    "{"
left2   {line}{left}({blank}|{tab})*
left3   {left2}\n
right   "}"
tab     [\t]
before  ({tab}|{blank})+
blank   " "
enter   \n
word    [^\n\t{} ]+
line    {word}({word}|{blank}|{tab})*
line2   {left2}{line}{right}({blank}|{tab})*

%%
{right} {count--; for(i = 0; i<count; i++){printf("\t");} ECHO;}
{left3} {for(i = 0; i<count; i++){printf("\t");} ECHO; count++;}
{line2} {for(i = 0; i<count; i++){printf("\t");} ECHO; }
{left}  {for(i = 0; i<count; i++){printf("\t");} ECHO; count++;}
{enter} {ECHO;}
{before}   {}
{line}  {for(i = 0; i<count; i++){printf("\t");} ECHO;}
%%

int main(int argc, char *argv[]){
      yylex();
      return(0);
}
      
