%{
 int tabcount = 0;int i = 0;
%}
word [^{}]
%%
^{word} {for(i=0;i<tabcount;i++){printf("\t");}ECHO;}
^"{" {for(i=0;i<tabcount;i++){printf("\t");}ECHO;tabcount++;}
"{" {ECHO;tabcount++;}
^"}" {tabcount--;for(i=0;i<tabcount;i++){printf("\t");}ECHO;}
%%
int main() {
	yylex();
	return 0;
}
