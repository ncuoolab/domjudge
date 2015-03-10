%{

%}
int         int 
double      double
letter      [a-zA-Z]
digit       [0-9]
special     [_$]
not         (^{letter})({letter}|{digit}|{special})*
cpy         cpy
cpy2        {cpy}({letter}|{digit}|{special})*
identfier   {letter}({letter}|{digit}|{special})*{cpy2}
%%
{not}       {}
\n          {}
{identfier} {ECHO;printf("\n");}
{cpy2}      {ECHO;printf("\n");}
.           {}
%%
int main(int argc,char *argv[]){
       yylex();
       return(0); 
}


