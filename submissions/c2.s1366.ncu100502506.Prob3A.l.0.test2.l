digit           [0-9]
letter          [a-zA-Z]
other           $|_
%%
"cpy"({digit}|{letter}|{other})*               {ECHO;printf("\n");}
({letter}|{other})+({other}|{digit}|{letter})*("cpy")({digit}|{letter}|{other})*  {ECHO;printf("\n");}
"\n"            ;
.               ;
%%
int main(int argc,char *argv[])
{
        yylex();
        return 0;
}


