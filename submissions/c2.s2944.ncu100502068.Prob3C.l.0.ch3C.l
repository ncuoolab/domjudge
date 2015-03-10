%{

%}
hexhead		0[xX]
digit		[_0-9]|[_a-f]|[_A-F]
digits		{digit}{1,8}
hex		{hexhead}{digit}{1,8}

%% 
{digits}	{ECHO; printf(" is digits.\n"); }
[^ {digit}]	{}
%%
int main(int argc, 
char *argv[]) {
	yylex();
 	return(0);
}
