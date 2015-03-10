%{
#include <stdio.h>
#include <string.h>
#include <math.h>
void yyerror(const char *message);
struct node *insertNode(int, int, char, struct node *, struct node *);
struct node {
	int type;
	int data, cur_result;
	char op;
	struct node *left, *right;
};

void display(struct node *root);
%}

%union {
	int ival;
	struct node *nptr;
}

%token<ival> INTEGER
%type<nptr> expr
%left '+' '-' '*'
%right '/'

%%

line	: expr	{ printf("the preorder expression is : "); display($1); printf("\nthe result is : %i\n", $1->cur_result); }
	;
expr	: expr '+' expr				{ $$ = insertNode(0, 0, '+', $1, $3); $$->cur_result = $1->cur_result + $3->cur_result; }
	| expr '-' expr				{ $$ = insertNode(0, 0, '-', $1, $3); $$->cur_result = $1->cur_result - $3->cur_result; }
	| expr '*' expr				{ $$ = insertNode(0, 0, '*', $1, $3); $$->cur_result = $1->cur_result * $3->cur_result; }
	| expr '/' expr				{ $$ = insertNode(0, 0, '/', $1, $3); $$->cur_result = $1->cur_result / $3->cur_result; }
	| '(' expr ')'				{ $$ = $2; }
	| INTEGER				{ $$ = insertNode(1, $1, '\0', NULL, NULL); $$->cur_result = $1; }
	;

%%

struct node *insertNode(int type, int data, char op, struct node *left, struct node *right) {
	struct node *newNode = malloc(sizeof(struct node));
	newNode->type = type;
	newNode->data = data;
	newNode->op = op;
	newNode->left = left;
	newNode->right = right;
	return newNode;
}

void display(struct node *root) {
	if(root != NULL) {
		if(root->type == 1) {
			printf("%i ", root->data);
		}
		else {
			printf("%c ", root->op);
		}

		display(root->left);
		display(root->right);
	}
}

void yyerror(const char *message) {
	fprintf(stderr, "%s\n", "Invalid format");
}

int main(int argc, char *argv[]) {
	yyparse();
	return 0;
}
