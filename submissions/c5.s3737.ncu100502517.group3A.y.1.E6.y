%{

#include<stdio.h>

int yylex();
void yyerror(char *message);
struct node * insertNode(int type, double data, char op, struct node *left, struct node *right);

struct node {
    int type;
    char op;
    double data,cur_result;
    struct node *left,*right; 	
};

void pre(struct node *n);

%}

%union {
    double fval;
    struct node *nptr;
}


%token<fval> RNUMBER
%type<nptr> expr
%left '+' '-'
%left '*' '/'

%%

line	: expr {printf("the preorder expression is : ");pre($1);if( $1->cur_result-(int)$1->cur_result>0.4){ printf("\nThe result is : %d\n", (int)$1->cur_result+1);}else{printf("\nThe result is : %d\n", (int)$1->cur_result);} }
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

void pre(struct node *n) {
	if(n!=NULL) {
		printf("%c ", n->op);
		pre(n->left);
		pre(n->right);
		if(n->data!=0) {
			printf("%d ",(int)n->data);
		}
	}
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

int main() {
	yyparse();
	return 0;
}

