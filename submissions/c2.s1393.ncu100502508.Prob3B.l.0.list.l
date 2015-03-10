space           [ \t\n\r]*
letter          [a-zA-z]
notnoo1		noodles{space}+{letter}+{space}+noodles{space}+{letter}+
notnoo2         {letter}+{space}+noodles{space}+noodles{space}+{letter}+
notnoo3         {letter}+{space}+{letter}+{space}+noodles{space}+noodles
noodles         {letter}+{space}+{letter}+{space}+noodles{space}+{letter}+

%%
{notnoo1}       ;
{notnoo2}       ;
{notnoo3}       ;

{noodles}       {ECHO;printf("\n");}
\n              ;
.               ;

%%
int main(int argc, char *argv[]) {
        yylex();
        return(0);
}

