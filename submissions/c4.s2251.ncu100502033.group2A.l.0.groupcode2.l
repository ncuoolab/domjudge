%{
%}
word [^//\n]+
tab0 need" "0" "tab
tab1 need" "1" "tab
tab2 need" "2" "tab
t0 {word}{tab0}
t1 {word}[//]+{tab1}
t2 {word}[//]+{tab2}
%%
{t2} {printf("\t\t%s",yytext);}
{t1} {printf("\t%s",yytext);}
{tab0} {printf("%s",yytext);}
{tab1} {printf("%s",yytext);}
{tab2} {printf("%s",yytext);}

%%
main(){
	yylex();
	return(0);
}
