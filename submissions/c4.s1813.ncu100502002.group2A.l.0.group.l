%{
        unsigned int count = 0;
        int i = 0;
%}
lq "{"
rq "}"
%%
{lq} {count++;ECHO;}
\n   {ECHO;for(i=0;i<count;i++)printf("\t");}
{rq} {count--;ECHO;}

%%
int main(int argc, char *argv[])
{
        yylex();
        return(0);
}
