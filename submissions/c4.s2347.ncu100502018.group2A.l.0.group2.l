%{
unsigned int tabCount=0, temp = 0, first = 0, pre=0;
#define LEFT 251
#define RIGHT 252
#define LINE1 253
#define LINE2 254
#define LINE3 255
%}
left	^[{]$
right	^[}]$
line1	^[{].*$
line2	^.*[^{]$
line3	^.*[{]$
%%
{left}	{ tabCount++; return LEFT; }
{right}	{ tabCount--; return RIGHT; }
{line1}	{ tabCount++; return LINE1; }
{line2}	return LINE2;
{line3}	{ tabCount++; return LINE3; }
.	;
%%
int main() {
	while(yylex()) {
		temp = tabCount;
		printf("%u", tabCount);
		if(tabCount > pre) {
			temp = temp - 1;
			while(temp > 0) {
				printf("\t");
				temp--;
			}
			printf("%s", yytext);
		}
		else {
			while(temp > 0) {
				printf("\t");
				temp--;
			}
			printf("%s", yytext);
		}
		pre = tabCount;
	}
	return (0);
}
