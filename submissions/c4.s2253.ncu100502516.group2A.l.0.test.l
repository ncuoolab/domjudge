%{
unsigned int count;
}%
%%
("{")	{ECHO; count++;}
("}")	{count--; ECHO;}
.|\n    {ECHO;}
%%
int main(int argc, char *argv[])
{
        yylex();
        return(0);
}
