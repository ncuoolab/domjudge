%{

#include <stdio.h> 
#include <string.h>
int yylex(void);
void yyerror(const char *message); 
int sum;
int b = 0;

%} 
%union{ 
	int ival; 
	char* word;
}

%token<ival> INUMBER 
%token<word> WORD
%type<ival> expr
%left '+' '-'
%left '*' '%'
%left '>' '<'

%% 

line : expr {   sum = $1;  }
	; 

expr : expr  expr '+' { $$ = $2 + $1; } 
	| expr  expr '-' { $$ = $2 - $1; }
        | expr  expr '*' { $$ = $2 * $1; }
        | expr  expr '%'{ $$ = $2 % $1; }
	| expr '>'      { $$ = $1 +1 ; }
	| expr '<'      { $$ = $1 -1 ; }
        | INUMBER {$$ = $1; }
;


%%

void yyerror (const char *message) {
	printf ("Invalid format\n");
        b = 1; 
}
int main(int argc, char *argv[]) {
        yyparse();

	if(b == 0){
		printf("%d\n", sum);
	}
	
        return 0;
}
