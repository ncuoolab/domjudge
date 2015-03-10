%{
unsigned int tabcount=0;
%}
left	{
right	}
tab	\t
change	\n
word	[^\t\n{}]+
%%
{left}	{tabcount++;}
{right}	{tabcount--;}
\n	{yylex()+=\t{tabcount}}
%%
int main(int argc, char *argv[]) {
	yylex();
	return(0);
}
