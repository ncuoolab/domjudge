%{
%}

word [^\t\n ]+
test1 {word}+['c']['p']['y']
test2 ['c']['p']['y']{word}*

%%
{test1}    {ECHO; printf("\n");}
{test2}   {ECHO; printf("\n");}
. {}
.|\n
%%

int main()
{
yylex();
return(0);
}





