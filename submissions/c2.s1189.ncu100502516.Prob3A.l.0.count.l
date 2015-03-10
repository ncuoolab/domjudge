word    [a-zA-z_]+
digit   [0-9]+
valid	[word]*"cpy"[word]*
invalid {digit}("cpy")+
%x COMMENT
%%
invalid	{}
valid	{BEGIN COMMENT;	ECHO;}
<COMMENT>.	{BEGIN INITIAL; printf("\n");}
%%
int main(int argc, char *argv[]) {
        yylex();
        return(0);
}
