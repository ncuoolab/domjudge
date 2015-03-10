%{
#include <stdio.h>
#include <string.h>
int yylex(void);
void yyerror(const char *message);
struct node * insertNode(int type, double data, char op, struct node *left, struct node *right);
struct node {
int type;
char op;
double data,cur_result;
struct node *left,*right; 	
};

%}
%union {
        double fval;
	struct node *nptr;
}

%token<fval> RNUMBER
%token ADD
%token SUB
%token MUL
%token DIV
%type<nptr> expr
%type <rval> expr
%left '+' '-'
%left '*' '/'

%%

line	: expr { printf("The result is : %.3lf\n", $1->cur_result) }
	;

expr	: '(' expr ')'  { $$ = $2; }
	| expr '+' expr { $$ = insertNode( 0, 0, '+', $1, $3 ); $$->cur_result = $1->cur_result + $3->cur_result; } 
	| expr '-' expr { $$ = insertNode( 0, 0, '-', $1, $3 ); $$->cur_result = $1->cur_result - $3->cur_result; }  
	| expr '*' expr { $$ = insertNode( 0, 0, '*', $1, $3 ); $$->cur_result = $1->cur_result * $3->cur_result; }
	| expr '/' expr { $$ = insertNode( 0, 0, '/', $1, $3 ); $$->cur_result = $1->cur_result / $3->cur_result; }
	| RNUMBER	{ $$ = insertNode( 1, $1, '\0', NULL, NULL ); $$->cur_result = $1; }
	;

%%

void yyerror (const char *message) {
	fprintf (stderr, "%s\n", message);
}
struct node * insertNode(int type, double data, char op, struct node *left, struct node *right) {
    struct node *newNode= malloc(sizeof(struct node));
    newNode->type = type;
    newNode->data = data;
    newNode->op = op;
    newNode->left = left;
    newNode->right = right;
    return newNode;
}


int main(int argc, char *argv[]) {
        yyparse();
        return 0;
}

