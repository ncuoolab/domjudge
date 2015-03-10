letter        [a-zA-Z\_\$]
digit         [0-9]
identifier1   {letter}({letter}|{digit})*cpy({letter}|{digit})*[^ ]
var	      cpy
id            {letter}*{var}({letter}|{digit})*
%%
{id}           {ECHO;printf("\n");}
.|\n           ;
%%
int main(int argc, char *argv[]) {
     yylex();
     return(0);
}



