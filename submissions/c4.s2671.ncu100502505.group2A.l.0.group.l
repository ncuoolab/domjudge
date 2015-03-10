%{
int  count = 0, i=0;
%}
 
ri "{"
le "}"
alp  [^\t\n\{\}]
ta "\t"

a {alp}*
b \n{ta}*{le}
c {ri}{alp}*{ta}*{le}


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

