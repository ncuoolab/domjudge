%{

#include<stdio.h>

int yylex();
int result;
void yyerror(char *message);
struct node * insertNode(int type, double data, char op, struct node *left, struct node *right);
void preorder(struct node *tmp);
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
	char* word;
}


%token<fval> RNUMBER
%type<nptr> expr
%left '+' '-'
%left '*' '/'

%%

line	: expr { result = $1->cur_result+0.5;printf("the preorder expression is : " ); preorder($1);}
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

struct node * insertNode(int type, double data, char op, struct node *left, struct node *right)
 {
    struct node *newNode= malloc(sizeof(struct node));
    newNode->type = type;
    newNode->data = data;
    newNode->op = op;
    newNode->left = left;
    newNode->right = right;
    return newNode;
}
void preorder(struct node*tmp)
{
	if(tmp == NULL)
	{
		return;
	}
	if(tmp->type == 0)
	{
		printf("%c",tmp->op);
	}
	else if(tmp->type == 1)
	{
		printf("%0.0f",tmp->data);
	}
	preorder(tmp->left);
	preorder(tmp->right);
}

int main() {
	yyparse();
	printf("The result is : %d\n", result);
	return 0;
}

