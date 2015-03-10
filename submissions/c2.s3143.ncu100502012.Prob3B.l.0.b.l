food    ^.[]+[a-zA-Z]+[ ]+[a-zA-Z]+[ ]+"noodles"[ ]+[a-zA-Z]+$
eof     [.\n\t]
%%
{food}  {ECHO;printf("\n");}
{eof}
%%
int main(int argc, char *argv[]) {
        yylex();
        return(0);
}
