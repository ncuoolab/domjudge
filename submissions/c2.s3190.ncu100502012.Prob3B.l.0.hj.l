food    ^[a-zA-Z]+[ \t]+[a-zA-Z]+[ \t]+"noodles"[ \t]+[a-zA-Z]+$
eof     .|\n
%%
{food}  {ECHO;printf("\n");}
{eof}
%%
int main(int argc, char *argv[]) {
        yylex();
        return(0);
}
