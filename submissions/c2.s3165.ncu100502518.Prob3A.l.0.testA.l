%{

%}
case1 [a-z]+cpy[_a-z]*[0-9]*
case2 [a-z]+_*cpy[_a-z]*[0-9]*
case3 cpy[_a-z]*[0-9]*
case4 [0-9]+_*cpy[_a-z]*[0-9]*
%%
{case1}		{ECHO;printf("\n");}
{case2}		{ECHO;printf("\n");}
{case3}		{ECHO;printf("\n");}
{case4}		{}
.		{}
\n		{}
%%
int main(int argc, char *argv[]) {
	yylex();
	return(0);
}
