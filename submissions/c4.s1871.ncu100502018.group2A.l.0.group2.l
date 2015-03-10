%{
unsigned int tabCount=0;
%}
left	[{]
right	[}]
%%
{left}	{ tabCount++; }
{right} { tabCount--; }
.|\n	;
%%
int main() {
	while(yylex()) {
		int temp = tabCount;
		while(temp!=0) {
			printf("\t");
			temp--;
		}		
		printf("%s", yytext);
	}
	return (0);
}
