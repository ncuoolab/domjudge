beg             ^(0(x|X))
digit           [0-9]|[a-fA-F]
%%
{beg}({digit}{1,6})       {ECHO;printf("\n");}
"\n"            ;
.               ;
%%
int main(int argc,char* argv)
{
        yylex();
        return 0;
}

