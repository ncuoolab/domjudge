%{
 int tabcount = 0;int i = 0;
%}
%%
"{" {ECHO;tabcount++;}
"}" {printf("\b\b\b\b\b\b\b\b");tabcount--;ECHO;}
\n {ECHO;for(i=0;i<tabcount;i++){printf("\t");}}
. {ECHO;}
%%
int main() {
	yylex();
	return 0;
}
