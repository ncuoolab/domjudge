%{

#include<stdio.h>

int yylex();
void yyerror(char *message);
struct node * insertNode(int type, int data, char op, struct node *left, struct node *right);

struct node {
    int type;
    char op;
    int data,cur_result;
    struct node *left,*right; 	
};

%}

%union {
    int fval;
    struct node *nptr;
}


%token<fval> RNUMBER
%type<nptr> expr
%left '+' '-'
%left '*' '/'

%%

line	: expr { printf("the result is : %d\n", $1->cur_result) ;}
	;

expr	: '(' expr ')'  { $$ = $2; }
		| expr '+' expr { $$ = insertNode( 0, 0, '+', $1, $3 ); $$->cur_result = $1->cur_result + $3->cur_result; } 
		| expr '-' expr { $$ = insertNode( 0, 0, '-', $1, $3 ); $$->cur_result = $1->cur_result - $3->cur_result; }  
		| expr '*' expr { $$ = insertNode( 0, 0, '*', $1, $3 ); $$->cur_result = $1->cur_result * $3->cur_result; }
		| expr '/' expr { $$ = insertNode( 0, 0, '/', $1, $3 ); $$->cur_result = $1->cur_result / $3->cur_result; }
		| RNUMBER	{ $$ = insertNode( 1, $1, '\0', NULL, NULL ); $$->cur_result = $1; }
		;

%%

void yyerror(char *message) {
    printf("%s\n", message);
}

struct node * insertNode(int type, int data, char op, struct node *left, struct node *right) {
    struct node *newNode= malloc(sizeof(struct node));
    newNode->type = type;
    newNode->data = data;
    newNode->op = op;
    newNode->left = left;
    newNode->right = right;
    return newNode;
}

int main() {
	yyparse();
	return 0;
}

