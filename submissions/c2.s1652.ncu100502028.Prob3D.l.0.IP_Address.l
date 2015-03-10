%x COMMENT
digit  ([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])
IP     {digit}"\."{digit}"\."{digit}"\."{digit}
%%
"\-"             {BEGIN COMMENT;}
<COMMENT>.|\n    {/* do nothing */}
<COMMENT>        {BEGIN INITIAL;}
{IP}  { ECHO; printf("\n"); }
{com} {;}
.|\n   ;
%%
int main(int argc, char *argv[]) {
        yylex();
        return(0);
}
