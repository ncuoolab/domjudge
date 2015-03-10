digit  ([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])
IP     {digit}"\."{digit}"\."{digit}"\."{digit}
%%
{IP}  { ECHO; printf("\n"); }
.|\n   ;
%%
int main(int argc, char *argv[]) {
        yylex();
        return(0);
}
