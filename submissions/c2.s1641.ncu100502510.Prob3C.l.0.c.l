%{
%}
head      0[xX]
digit     [0-9A-Fa-f]
hexdigit  {digit}{1,8}
hex       ^{head}{hexdigit}[\t\n]+
hex2      " "{head}{hexdigit}$
%%
{hex}     {ECHO;}
{hex2}    {fprintf(yyout, "%s", yytext+1);printf("\n");} 
.         {}
\n        {}
%%
int main(int argc,char *argv[]){
   yylex();
   return(0);
}
