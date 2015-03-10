%{
/* c defination */
#include<stdio.h>
#include<string.h>
int cino = 0;
char res[2048];
char *rp = res;
char line[1024];
char *lp = line;

void addChar(char c){
	*(lp ++) = c;
}

void eee(){
	// add indent
	int i = cino;
	for(; i -- ; ){
		*(rp ++) = '\t';
	}
	// add str
	addChar('\n');
	addChar('\0');
	strcpy(rp, line);
	rp += strlen(line);
	lp = line;
}
%}
b1	\{[ \t]*\n
b2	\}[ \t]*\n
predent	^[ \t]*
eol	\n
%%
{predent}	{}
{b1}		{addChar('{'); eee(); cino ++;}
{b2}		{addChar('}'); cino --; eee();}
{eol}		{eee();}
.		{addChar(yytext[0]);}
%%
int main(int argc, char* argv[]){
	yylex();
	*rp = '\0';
	printf("%s", res);
	return 0;
}
