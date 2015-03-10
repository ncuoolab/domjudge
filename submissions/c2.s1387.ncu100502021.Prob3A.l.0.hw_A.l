start [a-zA-Z_$]

sequence [A-Za-z0-9_$]*

cpy cpy

valid1 (" "|"("|\n){cpy}({sequence})*

valid2 (" "|"("|\n){start}{sequence}*{cpy}{sequence}*

legal {valid1}|{valid2}

%%


{legal} {printf("%s",1+yytext);}

.|\n ;

%%

int main(int argc,char *argv[])

{
 
yylex();
 
return (0);

}
