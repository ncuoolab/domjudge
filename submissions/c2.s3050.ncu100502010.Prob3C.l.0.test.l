
id 0
idx [xX]
back [0123456789ABCDEF]{1,8}
trueid ^{id}{idx}{back}

%%

{trueid} {ECHO; printf("\n");} 
.|\n ;

%%
int main (int argc, char *argv[]){
	yylex();
	return(0);
}

