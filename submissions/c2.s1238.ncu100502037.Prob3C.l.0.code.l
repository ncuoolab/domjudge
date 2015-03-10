
HAX  [A-Fa-f]
TAB   [ |\t|\n]+
DIGIT  [0-9]
ZERO  (0X|0x)
HaxLine {ZERO}({HAX}|{DIGIT})*{TAB}
Others  [^0]{ZERO}
word    [\t\n]+

%%
{Others}  { }
{ZERO}     {/* ECHO; printf("\n");*/ }
{HaxLine}  { ECHO;  }
.|\n   {/* do nothing */}


%%
int main(int argc, char *argv[]) {
        yylex();

        return(0);
}