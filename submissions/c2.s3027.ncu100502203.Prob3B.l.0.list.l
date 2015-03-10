input	({word}{blank}{word}{blank}noodles{blank}{word})
word	[a-zA-Z0-9]+
blank	" "+

%% 

{input}	{ ECHO; printf("\n"); }
.|\n	; 

%%

int main(int argc, char *argv[]) {
	yylex();
 	return(0);
}
