%{
#include <stdio.h>
#include <string.h>
int yylex(void); 
void yyerror(const char *message); 
struct node * insertNode(int type, int data, char op, struct node *left, struct node *right);
void preOrder(struct node* tree);
struct node{
	int type;
	char op;
	int data,cur_result;
	struct node *left,*right;
};

struct node* tree;

%} 
%union { 
int ival;
struct node *nptr; 
}
%token <ival> INUMBER
%type <nptr> expr
%left '+' '-' 
%left '*' '/' 
%nonassoc '(' ')'
%% 


line 	: expr 		{ tree = $1; }
	;
expr	: '(' expr ')'	{ $$ = $2;}
	| expr '+' expr { $$ = insertNode( 0, 0, '+', $1, $3 ); 
			  $$->cur_result = $1->cur_result + $3->cur_result;}
	| expr '-' expr { $$ = insertNode( 0, 0, '-', $1, $3 );
                          $$->cur_result = $1->cur_result - $3->cur_result;}
	| expr '*' expr { $$ = insertNode( 0, 0, '*', $1, $3 );
                          $$->cur_result = $1->cur_result * $3->cur_result;}
	| expr '/' expr { $$ = insertNode( 0, 0, '/', $1, $3 );
                          $$->cur_result = $1->cur_result / $3->cur_result;}
	| INUMBER	{ $$ = insertNode( 1, $1, '\0', NULL, NULL ); $$->cur_result = $1; }
	;  
%%
void yyerror (const char *message) {
        fprintf (stderr, "%s\n", message);
}
void preOrder(struct node* tree){
	if( tree->op == '\0'){
		printf("%d ", tree->cur_result);
	}
	else{
		printf("%c ", tree->op);
	}
	if ( tree->left != NULL) preOrder(tree->left);
	if ( tree->right != NULL) preOrder(tree->right);
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
	printf("the preorder expression is : ");
	preOrder(tree);
	printf("\nthe result is : %d\n", tree->cur_result);
	return(0);
}
