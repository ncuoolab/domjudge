%{
unsigned int tabCount=0, temp = 0, first = 0, pre=0,count = 0;
#define LEFT 251
#define RIGHT 252
#define LINE1 253
#define LINE2 254
#define LINE3 255
%}
tab	[\t]
left	^[{]$
right	^[}]$
line1	^[{].*$
line2	^.*[^{]$
line3	^.*[{]$
%%
{tab}	{ count++; }
{left}	{ tabCount++; return LEFT; }
{right}	{ tabCount--; return RIGHT; }
{line1}	{ tabCount++; return LINE1; }
{line2}	return LINE2;
{line3}	{ tabCount++; return LINE3; }
.|\t	;
%%
int main() {
	while(yylex()) {
		temp = tabCount - count;
		printf("%u", temp);
		if(tabCount > pre) {
			temp = temp - 1;
			while(temp > 0) {
				printf("\t");
				temp--;
			}
			printf("%s", yytext);
		}
		else if(tabCount <= pre) {
			while(temp > 0) {
				printf("\t");
				temp--;
			}
			printf("%s", yytext);
		}
		pre = tabCount;
		count = 0;
	}
	return (0);
}
