%{

#include<stdio.h>

int yylex();
void yyerror(char *message);
struct node * insertNode(int type, double data, char op, struct node *left, struct node *right);

struct node {
    int type;
    char op;
    int data,cur_result;
    struct node *left,*right; 	
};

void preorder(struct node *top);

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

line	: expr { printf("the preorder expression is : ");preorder($1);printf("\nthe result is : %d\n", $1->cur_result); }
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

struct node * insertNode(int type, double data, char op, struct node *left, struct node *right) {
    struct node *newNode= malloc(sizeof(struct node));
    newNode->type = type;
    newNode->data = data;
    newNode->op = op;
    newNode->left = left;
    newNode->right = right;
    return newNode;
}

void preorder(struct node * top)
{
	if(!top)
	{
		return;
	}
  	if( top->type ==0)
	{
		printf("%c ",top->op);
	}
	else if(top->type==1)
	{
		printf("%d ",top->cur_result);
	}
	preorder(top->left);
	preorder(top->right);

}

int main() {
	yyparse();
	return 0;
}


