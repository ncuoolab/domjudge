%{

%}

alpha [a-zA-Z\$\_]*
digit [0-9]*
var cpy
identifier {alpha}{var}({alpha}|{digit})

%%
{identifier} ECHO; printf("\n");
.|\n  ;
%%

int main(){
	yylex();
	return 0;

}
