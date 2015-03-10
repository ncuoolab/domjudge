start 0[x|X]
memory [0-9A-Fa-f]
hex ^{start}({memory}{1,8})$

%%

{hex}     {ECHO;printf("\n");}
.|\n    ;
%%

int main(int argc, char *argv[]){
        yylex();
        return(0);
}

