space           [("\t")|("\r")|("\n")|(" ")]*
dot		[.]
legal1          [2][5][0-5]
legal2		[2][0-4][0-9]
legal3		[1][0-9][0-9]
legal4		[0-9][0-9]
legal5		[0-9]
legalAll	({legal1}|{legal2}|{legal3}|{legal4}|{legal5})
IPNOT		({legalAll}{dot}){3}{legalAll}{dot}
IP		({legalAll}{dot}){3}{legalAll}

%%
{IPNOT}		;
{IP}            {ECHO;printf("\n");}
\n		;
.               ;

%%
int main(int argc, char *argv[]) {
        yylex();
        return(0);
}

