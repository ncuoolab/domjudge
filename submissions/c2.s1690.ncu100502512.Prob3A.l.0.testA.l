%{
%}

word [^\t\n (0-9]+
word1 [^\t\n]+
test1 {word}+['c']['p']['y']
test2 ['c']['p']['y']{word1}*

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





