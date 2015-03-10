
HAX  [A-Fa-f]
TAB   [ |\t|\n]+
DIGIT  [0-9]+
ZERO  ([0]X|[0]x)
HaxLine {ZERO}({HAX}|{DIGIT})+{TAB}
Others {DIGIT}{ZERO}({HAX}|{DIGIT})+{TAB}
word    [\t\n]+

%%
{Others}   { }
{ZERO}     {/* ECHO; printf("\n");*/ }
{HaxLine}  { ECHO;  }
.|\n   {/* do nothing */}


%%
int main(int argc, char *argv[]) {
        yylex();

        return(0);
}


