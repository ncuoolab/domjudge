name     [A-Z][a-z]*
career   [a-z]*
hometown [A-Za-z]*
target   noodles
line     {name}[ \t]+{career}[ \t]+"noodles"[ \t]+{hometown}
%%
{line}  { ECHO; printf("\n"); }
.|\n    ;
%%
int main(int argc, char *argv[]) {
        yylex();
        return(0);
}
