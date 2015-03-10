start [a-zA-Z_$]

sequence [A-Za-z0-9_$]*

cpy cpy

valid1 (" "|"("|^){cpy}({sequence})*

valid2 (" "|"("|^){start}{sequence}*{cpy}{sequence}*

legal {valid1}|{valid2}

%%


{legal} {printf("%s",1+yytext);printf(" ");}

.|\n ;

%%

int main(int argc,char *argv[])

{
 
yylex();
 
return (0);

}
