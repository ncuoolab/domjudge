%{
#include<stdio.h>
int yylex(); 
void yyerror(char *message);

struct node * insertNode(int type, int data, char op, struct node *left, struct node *right); 
void tree (struct node *);
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

line	: expr 			{ printf("the preorder expression is : "); tree($1); printf("\nthe result is : %i ",$1->cur_result); }
;

 expr   : '(' expr ')' 		{ $$ = $2; }
	| expr '+' expr 	{ $$ = insertNode( 0, 0, '+', $1, $3 ); $$->cur_result = $1->cur_result +  $3->cur_result; } 
	| expr '-' expr 	{ $$ = insertNode( 0, 0, '-', $1, $3 ); $$->cur_result = $1->cur_result -  $3->cur_result; } 
	| expr '*' expr 	{ $$ = insertNode( 0, 0, '*', $1, $3 ); $$->cur_result = $1->cur_result *  $3->cur_result; } 
	| expr '/' expr 	{ $$ = insertNode( 0, 0, '/', $1, $3 ); $$->cur_result = $1->cur_result /  $3->cur_result; } 
	| RNUMBER		{ $$ = insertNode( 1, $1,'\0', NULL, NULL ); $$->cur_result = $1; }
; 

%% 

void yyerror(char *message) {
    printf("%s\n", message);
}

void tree(struct node *t){
	if (t!=NULL){
    		if (t->type==0){
    			printf("%c ",t->op);
		}
		if (t->type==1){
			printf("%i ",t->data);
	 	}
   		tree(t->left);
    		
		tree(t->right);
	}
}

struct node * insertNode(int type, int  data, char op, struct node *left, struct node *right) {
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
