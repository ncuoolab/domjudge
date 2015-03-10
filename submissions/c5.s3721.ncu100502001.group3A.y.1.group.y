%{
#include<stdio.h>
#include<string.h>
void yyerror(const char *message);
struct node * insertNode(int type, int data, char op, struct node *left, struct node *right);
struct node {
    int type;
    char op;
    int data,cur_result;
    struct node *left,*right; 	
};
void show(struct node *root){
	if(root->type == 0 )
		printf(" %c",root->op);
	else
		printf(" %d",root->data);
	if(root->left!=NULL)
		show(root->left);
	if(root->right!=NULL)
		show(root->right);
	
};
int result;
int flag;
struct node *root;
%}
%union{
int ival;
struct node *nptr;
}
%token<ival> INUMBER
%type<nptr> expr
%left '+''-'
%left '*''/'
%right '('')'
%%
start:expr	{result=$1->cur_result;root=$1;}
;
expr : expr '+' expr { $$ = insertNode( 0, 0, '+', $1, $3 ); $$->cur_result = $1->cur_result + $3->cur_result;}
	 |expr '-' expr { $$ = insertNode( 0, 0, '-', $1, $3 ); $$->cur_result = $1->cur_result - $3->cur_result;}
	 |expr '*' expr { $$ = insertNode( 0, 0, '*', $1, $3 ); $$->cur_result = $1->cur_result * $3->cur_result;}
	 |expr '/' expr { $$ = insertNode( 0, 0, '/', $1, $3 ); $$->cur_result = $1->cur_result / $3->cur_result;}
	 |'('expr')'	{$$=$2;}
	 | INUMBER      { $$ = insertNode( 1, $1, '\0', NULL, NULL ); $$->cur_result = $1;}
; 

%%
struct node * insertNode(int type, int data, char op, struct node * left, struct node * right) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->type = type;
    newNode->data = data;
    newNode->op = op;
    newNode->left = left;
    newNode->right = right;
    return newNode;
} 
void yyerror(const char*message){
	flag=1;
}
int main(int argc, char *argv[]){
	yyparse();
	if(flag!=1){
		printf("the preorder expression is :");
		show(root);
		printf("\nthe result is : %d\n",result);
	}
	else{
        	printf("Invalid format\n");
	}
	return(0);
}

