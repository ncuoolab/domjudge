word [$0][xX][0-9A-F]{1,8}

%%
{word} {ECHO;printf("\n");}
.|\n {}
%%

int main(int argc, char *argv[]) {
yylex();
return (0);
}
