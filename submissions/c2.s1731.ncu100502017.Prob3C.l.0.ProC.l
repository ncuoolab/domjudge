zeroX   [0][x|X]
letter  [a-fA-F]
digit   [0-9]
hexlit  ^{zeroX}({letter}|{digit}){1,8}$
hexsp   " "{zeroX}({letter}|{digit}){1,8}$
%%
{hexlit}        {ECHO; printf("\n");}
{hexsp}         {printf("%s",1+yytext);printf("\n");}
.|\n                       ;
%%
int main(int argc, char *argv[]) {
        yylex();
        return(0);
}
