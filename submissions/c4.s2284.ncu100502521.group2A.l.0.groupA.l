%{
 int tabcount = 0;int i = 0;
%}
%%
"{" {ECHO;printf("\n");tabcount++;for(i=0;i<tabcount;i++){printf("\t");}printf("%d",tabcount);}
"}" {printf("\r");ECHO;printf("\n");tabcount--;for(i=0;i>tabcount;i++){printf("\t");}printf("%d",tabcount);}
";\n" {ECHO;printf("\n");for(i=0;i<tabcount;i++){printf("\t");}printf("%d",tabcount);}
">" {ECHO;printf("\n");for(i=0;i<tabcount;i++){printf("\t");}}
. {ECHO;}
\n {}
%%
int main() {
	yylex();
	return 0;
}
