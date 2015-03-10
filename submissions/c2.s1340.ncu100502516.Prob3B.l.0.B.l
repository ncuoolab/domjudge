name	[A-Z]+[^\n]
career	[^\n]+
hometown	[^\n]+
space	[\t ]

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
