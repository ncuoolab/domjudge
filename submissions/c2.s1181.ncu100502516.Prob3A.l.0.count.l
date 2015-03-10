word    [a-zA-z_]+
digit   [0-9]+
invalid {digit}("cpy")+
%x IN_COMMENT
%%
{invalid}       {}
<INITIAL>{
   "cpy"	{BEGIN(IN_COMMENT); ECHO;}
   }
   <IN_COMMENT>{
   word	{ECHO;}
   .B	EGIN(INITIAL);
   }
%%
int main(int argc, char *argv[]) {
        yylex();
        return(0);
}
