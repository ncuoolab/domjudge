name	[A-Z]+[^\n]
career	[^\n]+
hometown	[^\n]+

valid   {name}("\t"){career}("\t")("noodles"){"\t"}{hometown}
%%
{valid} {ECHO; printf("\n");}
.|\n    {}
%%
int main(int argc, char *argv[])
{
        yylex();
        return(0);
}
