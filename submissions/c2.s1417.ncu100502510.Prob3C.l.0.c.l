%{

%}
head      0[xX]
digit     [0-9A-Fa-f]
hexdigit  {digit}{1,8}
hex       ^{head}{hexdigit}
%%
{hex}     {ECHO;printf("\n");}
.         {}
\n        {}
%%
int main(int argc,char *argv[]){
   yylex();
   return(0);
}
