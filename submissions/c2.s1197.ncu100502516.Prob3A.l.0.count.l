word    [a-zA-z_]+
digit   [0-9]+
valid	[word]*("cpy")+[word]*
invalid {digit}("cpy")+
%%
invalid	{}
valid	{ECHO; printf("\n");}
.	{}
%%
int main(int argc, char *argv[]) {
        yylex();
        return(0);
}
