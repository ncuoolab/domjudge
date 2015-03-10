word (0x|0X)[0-9A-Fa-f]{1,8}
skip1 [.]+{word}[.]+
skip2 [.]+{word}
skip3 {word}[.]+

%%
{skip1} {}
{skip2} {}
{skip3} {}
{word} {ECHO;printf("\n");}
.|\n {}
%%

int main(int argc, char *argv[]) {
yylex();
return (0);
}
