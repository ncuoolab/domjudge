%{

#include <stdio.h>
#include <string.h>
int yylex(void);
void yyerror(const char *message);
int wrong = 0;
double ans=0;
%}
%union {
        double rval;	
	char* word;
}

%token <rval> RNUMBER
%type <rval> expr
%left '+' '-'
%left '*' '/'
%right UMINUS

%%

line : expr {ans=$1;}
     
expr : expr expr'+' {$$=$1+$2;}
	 | expr expr '-' {$$=$1-$2;}
	 | expr expr '*' {$$=$1*$2;}
	 | expr expr '/' {$$=$1/$2;}
	 | RNUMBER 
	 ;
 

%%

void yyerror (const char *message) {
	wrong=1;
        printf("Wrong Formula.");
	printf("\n");
}

int main(int argc, char *argv[]) {
        yyparse();
	if(wrong != 1){
          printf("%.1f\n",ans);
	}
	return 0;
}

