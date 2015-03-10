word    [a-zA-z_$]+
digit   [0-9]+
valid   ({word})*("cpy")+({word})*
invalid {digit}{valid}
%%
{invalid}       {}
{valid} {ECHO; printf("\n");}
.|\n    {}
%%
int main(int argc, char *argv[])
{
        yylex();
        return(0);
}
