%{
%}
space           [ \t\n\r]*
comma           [,]*
letter          [a-fA-F]
digit           [0-9]
digits          {digit}+
real            {digits}[\.]{digits}
identifier      {letter}({letter}|{digit})*
hex		^((0x)|(0X))({digit}|{letter}){1,8}
%%
{hex}          {ECHO;}
.		;
%%
int main(int argc, char *argv[]){
        yylex();
        return(0);
}

