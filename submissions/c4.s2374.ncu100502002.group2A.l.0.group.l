%{
        unsigned int count = 0;
        int i = 0;
%}
lq "{"
rq "}"
%x comment
%%
{lq}		{count++;ECHO;}
{rq}		{count--;}
\n.*{rq}	{printf("\n");count--;for(i=0;i<count;i++)printf("\t");printf("%s",yytext+1);}
\n              {ECHO;for(i=0;i<count;i++)printf("\t");}
%%
int main(int argc, char *argv[])
{
        yylex();
        return(0);
}

