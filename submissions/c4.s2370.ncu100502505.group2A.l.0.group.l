%{
int  count = 0, i=0;
%}
 
ri "{"
le "}"
alp  [A-Za-z|0-9|\(|\)|\=|\;|\<|\+|\\|" "|\/|?|:|*|\>]

a {alp}*
b \n{le}


%%
{ri}     {ECHO;count++;}
{a}      {ECHO;}
{b}	 {count--;printf("\n");for(i=0; i<count; i++) printf("\t");printf("}");}
\n       {ECHO;for(i=0; i<count; i++) printf("\t");}
.	 ;
%%
int main()
{
	yylex();
	return(0);
}

