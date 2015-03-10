space           [ \t\n\r]*
letter          [a-zA-z]
noodles          {letter}+{space}+{letter}+{space}+noodles{space}+{letter}+

%%
{noodles}       {ECHO;printf("\n");}
\n              ;
.               ;

%%
int main(int argc, char *argv[]) {
        yylex();
        return(0);
}

