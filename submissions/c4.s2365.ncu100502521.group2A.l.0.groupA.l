%{
 int tabcount = 0;int i = 0;
%}
%%
"{" {ECHO;tabcount++;}
"}" {printf("\r");tabcount--;for(i=0;i<tabcount;i++){printf("\t");}ECHO;}
\n {ECHO;}
">" {ECHO;printf("\n");}
^. {for(i=0;i<tabcount;i++){printf("\t");}ECHO;}
%%
int main() {
	yylex();
	return 0;
}
