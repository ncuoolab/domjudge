%{
#include <stdio.h>
#include <string.h>
#include <math.h>
void yyerror(const char *message);
struct node * insertNode(int type, double data, char op, struct node *left, struct node *right);
struct node {
    int type;
    char op;
    double data,cur_result;
    struct node *left,*right;
};

void preorder(struct node*root);
%}
%union{
double fval;
char* word;
struct node *nptr;
}
%token<fval> INUMBER
%type<nptr> expr
%left '+' '-'
%left '*' '/'
%%

line : expr        {printf("the preorder expression is : ");  
                    preorder($1);
                    printf("\nthe result is : %.0f\n",$1->cur_result);  }
     ;
expr : expr'+'expr {$$ = insertNode( 0, 0, '+', $1, $3 ); $$->cur_result = $1->cur_result + $3->cur_result; }
     | expr'-'expr {$$ = insertNode( 0, 0, '-', $1, $3 ); $$->cur_result = $1->cur_result + $3->cur_result; }
     | expr'*'expr {$$ = insertNode( 0, 0, '*', $1, $3 ); $$->cur_result = $1->cur_result + $3->cur_result; }    
     | expr'/'expr {$$ = insertNode( 0, 0, '/', $1, $3 ); $$->cur_result = $1->cur_result + $3->cur_result; }
     | '('expr')'  {$$=$2;}  
     | INUMBER     {$$ = insertNode( 1, $1, '\0', NULL, NULL ); $$->cur_result = $1; }
     ;
%%

void yyerror(const char *message)
{
        fprintf(stderr, "Invalid format\n");
}
void preorder(struct node *root) {
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
int main(int argc, char *argv[])
{
    yyparse();
   // printf("the preorder expression is :");
    return(0);
}
