%{
        int count = 0;
        int i = 0;
	int h=0;
%}
lq "{"
rq "}"
tab "\t"
%%
{lq}		{count++;ECHO;}
{rq}		{count--;}
\n.*{lq}.*{rq}  {printf("\n");for(i=0;i<count;i++)printf("\t");
		 for(h=1;h<yyleng;h++){
			if(yytext[h]!='\t')
				printf("%c",yytext[h]);
		 };}
\n.*{rq}	{printf("\n");count--;for(i=0;i<count;i++)printf("\t");for(h=1;h<yyleng;h++){
                        if(yytext[h]!='\t')
                                printf("%c",yytext[h]);
                 };}
\n              {ECHO;for(i=0;i<count;i++)printf("\t");for(h=1;h<yyleng;h++){
                        if(yytext[h]!='\t')
                                printf("%c",yytext[h]);
                 };}
[^\t ]           {ECHO;}
.               ;
%%
int main(int argc, char *argv[])
{
        yylex();
        return(0);
}

