%{
 int tabcount = 0;int i = 0;
%}
endline ";"$
%%
"{" {ECHO;printf("\n");tabcount++;for(i=0;i<tabcount;i++){printf("\t");}}
"}" {printf("\r");tabcount--;for(i=0;i<tabcount;i++){printf("\t");}ECHO;printf("\n");for(i=0;i<tabcount;i++){printf("\t");}}
{endline} {ECHO;printf("\n");for(i=0;i<tabcount;i++){printf("\t");}}
">" {ECHO;printf("\n");}
. {ECHO;}
\n {}
%%
int main() {
	yylex();
	return 0;
}
