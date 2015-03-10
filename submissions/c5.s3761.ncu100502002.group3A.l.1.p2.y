%{

#include<stdio.h>

int yylex();
void yyerror(char *message);
struct node * insertNode(int type, int data, char op, struct node *left, struct node *right);
void preorder(struct node *input);
struct node {
    int type;
    char op;
    int data,cur_result;
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

line	: expr { printf("the preorder expression is :"); preorder($1);printf("\nthe result is : %i\n", $1->cur_result);}
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
void preorder(struct node *input)
{
	if(input == NULL)
	return;
	if(input->type==0)
	{
		printf(" %c", input->op);
	}
	else
	{
		printf(" %i", input->data);
	}
	preorder(input->left);
	preorder(input->right);
}
int main() {
	yyparse();
	return 0;
}

