%{
%}

letter [a-zA-Z_$]
number [0-9]	
test1 {letter}+cpy({letter}|{number})*
test2 cpy({letter}|{number})*
%%
{test1}    {ECHO; printf("\n");}
{test2}    {ECHO; printf("\n");}		
.|\n
%%

int main()
{
yylex();
return(0);
}





