%{
        int count = 0;
        int i = 0;
	int h=0;
%}
lq "{"
rq "}"
tab "\t"
%x comment
%%
{lq}		{count++;ECHO;}
{rq}		{count--;}
\n.*{lq}.*{rq}  {printf("\n");for(i=0;i<count;i++)printf("\t");
		 for(h=1;h<yyleng;h++){
			if(yytext[h]!='\t')
				printf("%c",yytext[h]);
		 };}
\n.*{rq}	{printf("\n");count--;for(i=0;i<count;i++)printf("\t");printf("%s",yytext+1);}
\n              {ECHO;for(i=0;i<count;i++)printf("\t");}
[^\t]           {ECHO;}
.               ;
%%
int main(int argc, char *argv[])
{
        yylex();
        return(0);
}

