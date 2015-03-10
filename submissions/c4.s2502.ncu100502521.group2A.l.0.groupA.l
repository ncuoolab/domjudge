%{
 int tabcount = 0;int i = 0;
%}
%%
"{" {ECHO;tabcount++;}
"}" {tabcount--;ECHO;}
\n {ECHO;for(i=0;i<tabcount-1;i++){printf("\t");}}
^. {if(tabcount!=0){printf("\t");}ECHO;}
. {ECHO;}
%%
int main() {
	yylex();
	return 0;
}
