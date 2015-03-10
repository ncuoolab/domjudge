word (0x|0X)[0-9A-Fa-f]{1,8}$
skip [^ \t\n]+[0x|0X][0-9A-Fa-f]{1,8}

%%
{skip} {}
{word} {ECHO;printf("\n");}
.|\n {}
%%

int main(int argc, char *argv[]) {
yylex();
return (0);
}
