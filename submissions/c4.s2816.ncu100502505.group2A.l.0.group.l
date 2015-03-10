%{
int  count = 0, i=0;
int isFirstNonSpace = 1;
%}
 
ri "{"
le "}"
alp  [^\t\n\{\}]
ta "\t"

a {alp}*[ \t]*
b \n{ta}*{le}
c {ri}({alp}|{ta})*{le}({alp}|{ta})*
d " "+


%%
{d}      {if(!isFirstNonSpace)ECHO;}
{ri}     {ECHO;count++; isFirstNonSpace=0;}
{a}      {ECHO; isFirstNonSpace=0;}
{b}	 {count--;printf("\n");for(i=0; i<count; i++) printf("\t");printf("}");}
{c}	 {ECHO; isFirstNonSpace=0;}
\n       {ECHO;for(i=0; i<count; i++) printf("\t"); isFirstNonSpace=1;}
.	 ;
%%
int main()
{
	yylex();
	return(0);
}

