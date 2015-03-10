%{
int  count = 0, i=0;
int isFirstNonSpace = 1;
%}
 
ri "{"
le "}"
alp  [^\t\n\{\} ]
ta "\t"

a {alp}*
b \n{ta}*{le}
c {ri}{alp}*{ta}*{le}
d " "+


%%
{ri}     {ECHO;count++;}
{a}      {ECHO; isFirstNonSpace=0;}
{b}	 {count--;printf("\n");for(i=0; i<count; i++) printf("\t");printf("}");}
{c}	 {ECHO;}
{d}	 {if(!isFirstNonSpace)ECHO;}
\n       {ECHO;for(i=0; i<count; i++) printf("\t"); isFirstNonSpace=1;}
.	 ;
%%
int main()
{
	yylex();
	return(0);
}

