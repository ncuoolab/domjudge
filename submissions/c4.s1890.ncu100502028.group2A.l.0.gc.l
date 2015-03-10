%{
unsigned int count = 0;
%}
%x BRACE 
print_line	[ .\(\)\;]$
%% 
"\{"			{ printf("{"); count++; BEGIN BRACE; }
<BRACE>{print_line}	{ printf("\t"); printf("%s", yytext); printf("\n"); }
<BRACE>"\}"		{ printf("}"); count--; BEGIN INITIAL; }
.|\n			{ ECHO; }
%% 
int main(int argc, char *argv[]) {
	yylex();
	return(0);
}
