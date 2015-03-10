word    [^ \t\n]+
digit   [0-9]+
invalid {digit}(cpy)+
%%
{invalid}       {}
"cpy"   {BEGIN COMMENT; ECHO;}
<COMMENT>word   {ECHO;}
<COMMENT>" "|\n {printf("\n"); BEGIN INITIAL;}
%%
int main(int argc, char *argv[]) {
        yylex();
        return(0);
}
