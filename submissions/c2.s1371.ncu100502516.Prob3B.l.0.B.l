name	[^\n\t ]+[A-Z]+[a-z]+
career	[^\n\t ]+
hometown	[^\n\t ]+
space	[\t ]+

valid   {name}{space}{career}{space}("noodles"){space}{hometown}
%%
{valid} {ECHO; printf("\n");}
.|\n    {}
%%
int main(int argc, char *argv[])
{
        yylex();
        return(0);
}
