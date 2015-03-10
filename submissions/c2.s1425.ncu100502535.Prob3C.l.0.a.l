%{

%}
match	^0[xX][0-9A-Fa-f]+
other	.|\n
%%
{match}  { ECHO; printf("\n");}
{other}  {}
%%
int main(int argc, char *argv[]) {
        yylex();
        return(0);
}
