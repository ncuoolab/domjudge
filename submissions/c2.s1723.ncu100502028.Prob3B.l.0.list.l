name     [A-Za-z0-9]
career   [A-Za-z0-9]
hometown [A-Za-z0-9]
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
