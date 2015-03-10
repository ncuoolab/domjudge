start 0[x|X]
memory [0-9A-Fa-f]
hex ^{start}({memory}{1,8})$
hex2  [ |\t]+{start}({memory}{1,8})$

%%

{hex}     {ECHO;printf("\n");}
{hex2}     {printf("%s\n",yytext+2);}
.|\n    ;
%%

int main(int argc, char *argv[]){
        yylex();
        return(0);
}

