%{

%}
space (" ")
tab ("\t")
noodles "noodles"
name [a-z|A-Z]+
stand {name}("\t"){name}("\t"){noodles}("\t"){name}
standspace {name}{space}{name}{space}{noodles}{space}{name}
%%
{stand} {ECHO;printf("\n");};
{standspace} {ECHO;printf("\n");}
{space} {}
{tab} {}
.|\n {}
%%
int main(int argc, char* argv[])
{
 yylex();
 return 0;
}



