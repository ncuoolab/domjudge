word    [a-zA-z_]+
digit   [0-9]+
invalid {digit}("cpy")+
%x COMMENT
%%
{invalid}       {}
"cpy"   {BEGIN COMMENT; ECHO;}
<COMMENT>word   {ECHO;}
<COMMENT>. {BEGIN INITIAL; printf("\n");}
word	{ECHO;}
.	{}
%%
int main(int argc, char *argv[]) {
        yylex();
        return(0);
}
