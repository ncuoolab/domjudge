word    [^\n\t ]+
valid   {word}+("noodles"){word}+
%%
{valid} {ECHO; printf("\n");}
.|\n    {}
%%
int main(int argc, char *argv[])
{
        yylex();
        return(0);
}
