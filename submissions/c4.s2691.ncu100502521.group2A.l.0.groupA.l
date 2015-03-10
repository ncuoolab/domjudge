%{
 int tabcount = 0;int i = 0;
%}
word [^{}]
%%
^{word} {for(i=0;i<tabcount;i++){printf("\t");}ECHO;}
^"{" {for(i=0;i<tabcount;i++){printf("\t");}ECHO;tabcount++;}
"{\n" {ECHO;tabcount++;}
"{" {tabcount++;printf("\n");for(i=0;i<tabcount;i++){printf("\t");}ECHO;}
^"}" {tabcount--;for(i=0;i<tabcount;i++){printf("\t");}ECHO;}
"}" {printf("\n");tabcount--;for(i=0;i<tabcount;i++){printf("\t");}ECHO;}

%%
int main() {
	yylex();
	return 0;
}
