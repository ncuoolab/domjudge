%{
%}
letter          [a-fA-F]
digit           [0-9]
digits          {digit}+
identifier      {letter}({letter}|{digit})*
nothex		[^ \t\n]+((0x)|(0X))({digit}|{letter}){1,8}
hex		((0x)|(0X))({digit}|{letter}){1,8}$
%%
{nothex}	;
{hex}          {ECHO;printf("\n");}
\n		;
.		;	
%%
int main(int argc, char *argv[]){
        yylex();
        return(0);
}

