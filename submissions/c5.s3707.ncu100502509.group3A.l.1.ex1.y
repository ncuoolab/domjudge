%{
#include<stdio.h>
int yylex();
void yyerror(char *message);
struct node * insertNode(int type, double data, char op, struct node *left, struct node *right); 
void print_preorder(struct node *root);
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
%type<nptr> expr
%left '+' '-'
%left '*' '/'
%% 

line	: expr { printf("the preorder expression is : "); print_preorder($1); printf("\nthe result is : %.f\n", $1->cur_result); }
	;
expr	: '(' expr ')' { $$ = $2; }
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
void print_preorder(struct node *root) {
	if(root->type == 0)
		printf("%c ", root->op);
	else if(root->type == 1)
		printf("%.f ", root->data);
	if(root->left != NULL)
		preorder(root->left);
	if(root->right != NULL)
		preorder(root->right);
}
struct node * insertNode(int type, double data, char op, struct node *left, struct node *right) {
    struct node *newNode = malloc(sizeof(struct node));
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

