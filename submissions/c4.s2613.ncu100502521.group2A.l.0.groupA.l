%{
 int tabcount = 0;int i = 0;
%}
%%
"{" {printf(" ");ECHO;tabcount++;}
"}" {tabcount--;for(i=0;i<tabcount;i++){printf("\t");}ECHO;}
^. {for(i=0;i<tabcount;i++){printf("\t");}ECHO;}
%%
int main() {
	yylex();
	printf("\r");
	return 0;
}
