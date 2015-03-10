test (cpy|[a-zA-Z_$][0-9a-zA-Z_$]*(cpy))[0-9a-zA-Z_$]*
token {test}
skip [0-9]+{test}

%%
{skip} {}
{token} {ECHO;printf("\n");}
.|\n {}
%%
int main(void) {
yylex();
return (0);
}
