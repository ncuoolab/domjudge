space           [("\t")|("\r")|("\n")|(" ")]*
letter          [a-zA-z_]
digit           [0-9]
digits          {digit}+
cpya		{digit}({letter}|{digit})*cpy({letter}|{digit})*
cpy		({letter}|{digit})*cpy{letter}*{digit}*

%%
{cpya}		;
{cpy}           {ECHO;printf("\n");}
\n		;
.               ;

%%
int main(int argc, char *argv[]) {
        yylex();
        return(0);
}

