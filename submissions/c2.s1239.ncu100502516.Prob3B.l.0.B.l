word    [^\n\t ]+
valid   {word}("\t"){word}("\t")("noodles")("\t"){word}
%%
{valid} {ECHO; printf("\n");}
.|\n    {}
%%
int main(int argc, char *argv[])
{
        yylex();
        return(0);
}
