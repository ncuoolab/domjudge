%{

#include<stdio.h>

int yylex();
void yyerror(char *message);
struct node * insertNode(int type, double data, char op, struct node *left, struct node *right);
void traversal(struct node *p);
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

line	: expr { 
printf("the preorder expression is :");traversal($1);
printf("\nthe result is : %.0lf\n", $1->cur_result); }
	;

expr	: '(' expr ')'  { $$ = $2; }
	| expr '+' expr { $$ = insertNode( 0, 0, '+', $1, $3 ); $$->cur_result = $1->cur_result + $3->cur_result; } 
	| expr '-' expr { $$ = insertNode( 0, 0, '-', $1, $3 ); $$->cur_result = $1->cur_result - $3->cur_result; }  
	| expr '*' expr { $$ = insertNode( 0, 0, '*', $1, $3 ); $$->cur_result = $1->cur_result * $3->cur_result; }
	| expr '/' expr { $$ = insertNode( 0, 0, '/', $1, $3 ); $$->cur_result = $1->cur_result / $3->cur_result; }
	| RNUMBER	{ $$ = insertNode( 1, $1, '\0', NULL, NULL ); $$->cur_result = $1; }
	;

%%
void traversal(struct node *p)
{
if(p!=NULL){
if(p->type==1)printf(" %.0f",p->data);
else printf(" %c",p->op);
traversal(p->left);
traversal(p->right);
}}
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

int main() {
	yyparse();
	
	return 0;
}

