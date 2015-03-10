alp [A-Z|a-z|0-9|" "|\(|\)|\;|\=|\,|\+|\/|\\|*|<|>]
count "" 
cha "{"

first {alp}*"{"{alp}*
second {alp}*
third "}"{alp}*


%%
{first} {ECHO;printf("\n");printf("\t");}
{second} {ECHO;printf("\n");}
{third} {ECHO;printf("\n");}

.|\n  ;
%%

int main()
{
	yylex();
	return(0);
}


