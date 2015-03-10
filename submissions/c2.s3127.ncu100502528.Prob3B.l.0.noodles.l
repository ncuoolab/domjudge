%{

%}
space (" ")
tab ("\t")
noodles "noodles"
name [a-z|A-Z]+
stand {name}("\t"){name}("\t"){noodles}("\t"){name}
standspace {name}{space}{name}{space}{noodles}{space}{name}
%%
{stand} {ECHO;}
{standspace} {ECHO;printf("space\n");}
{space} {ECHO;printf("SPACE\n");}
{tab} {ECHO;printf("tab\n");}
.|\n {ECHO;}
%%
int main(int argc, char* argv[])
{
 yylex();
 return 0;
}



