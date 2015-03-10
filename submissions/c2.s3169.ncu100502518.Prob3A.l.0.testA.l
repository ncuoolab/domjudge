%{

%}
case1 [A-Za-z]+[0-9]*cpy[_a-zA-Z$0-9]*
case2 [A-Za-z]+[0-9]*_*$*cpy[_a-zA-Z$0-9]*
case3 cpy[_a-zA-Z$0-9]*
case4 [0-9]+_*$*cpy[_a-zA-Z$0-9]*
case5 _+$+cpy[_a-zA-Z$0-9]*
%%
{case1}		{ECHO;printf("\n");}
{case2}		{ECHO;printf("\n");}
{case3}		{ECHO;printf("\n");}
{case4}		{}
{case5}		{}
.		{}
\n		{}
%%
int main(int argc, char *argv[]) {
	yylex();
	return(0);
}
