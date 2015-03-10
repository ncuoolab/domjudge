space           [ \t\n\r]*
comma           [,]*
letter          [a-zA-z_]
digit           [0-9]
else		[^()=]
digits          {digit}+
identifier      {letter}({letter}|{digit})*
cpy		[^0123456789( ]{letter}*(cpy){letter}*{digit}*

%x COMMENT
%%
"//"            {BEGIN COMMENT;}
<COMMENT>.      {/* do nothing*/}
<COMMENT>"\n"   {BEGIN INITIAL;}
{cpy}           {ECHO;printf("\n");}
{space}		;
.               ;

%%
int main(int argc, char *argv[]) {
        yylex();
        return(0);
}

