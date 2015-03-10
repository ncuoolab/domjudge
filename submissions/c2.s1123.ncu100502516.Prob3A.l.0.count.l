word    [^ \t\n();]+
digit   [0-9]+
invalid {digit}("cpy")+
%x COMMENT
%%
{invalid}       {}
"cpy"   {BEGIN COMMENT; ECHO;}
<COMMENT>word   {ECHO;}
<COMMENT>" "|"\n" {BEGIN INITIAL; printf("\n");}
.	{}
%%
int main(int argc, char *argv[]) {
        yylex();
        return(0);
}
