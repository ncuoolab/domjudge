%{
#include<stdio.h>
int cnt = 0;
char buf[1000], *pp;
void rep(int n){
	while(n --){
		printf("\t");
	}
}
int delta;
void endOfLine(){
	fprintf(stderr, "%d\n", cnt);
	if(delta >= 0)
		rep(cnt);
	else
		rep(cnt+delta);
	*pp = '\0';
	printf("%s", buf);
	cnt += delta;
}
void beginOfLine(){
	delta = 0;
	pp = buf;
}
%}
inc			\{
dec			\}
%%
^[ \t]*		{}
{inc}		{*pp++ = yytext[0]; delta++;}
{dec}		{*pp++ = yytext[0]; delta--;}
\n			{*pp++ = yytext[0]; endOfLine(); beginOfLine(); }
.			{*pp++ = yytext[0];}
%%

int main(){
	beginOfLine();
	yylex();
	return 0;
}
