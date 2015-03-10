%{
int  count = 0, i=0;
%}
 
ri "{"
le "}"
alp  [^\t\n\{\}]

a {alp}*
b \n{le}
c {ri}{alp}+{le}


%%
{ri}     {ECHO;count++;}
{a}      {ECHO;}
{b}	 {count--;printf("\n");for(i=0; i<count; i++) printf("\t");printf("}");}
{c}	 {ECHO;}
\n       {ECHO;for(i=0; i<count; i++) printf("\t");}
.	 ;
%%
int main()
{
	yylex();
	return(0);
}

