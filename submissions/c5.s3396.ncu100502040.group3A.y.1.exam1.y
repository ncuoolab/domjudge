%{
#include <stdio.h> 
#include <string.h>
int yylex(void);
int error = 0; 
double result;
void yyerror(const char *message); 
struct node * insertNode(int type, double data, char op, struct node *left, struct node *right);

struct node{
	int type;
	char operator;
	double data, cur_result;
	struct node *left, *right;
};
struct node *head;

%} 

%union {
	double rval;
        struct node *nptr;
}
%token <rval> RNUMBER 
%type <nptr> expr 
%left '+' '-' 
%left '*' '/' 

%% 
line 	: expr { head = $1; result =  $1->cur_result; }
	; 
expr 	: expr '+' expr { $$ = insertNode(0, 0, '+', $1, $3); 
			  $$->cur_result = $1->cur_result + $3->cur_result;}
	| expr '-' expr { $$ = insertNode(0, 0, '-', $1, $3); 
			  $$->cur_result = $1->cur_result - $3->cur_result;}
        | expr '*' expr { $$ = insertNode(0, 0, '*', $1, $3);
                          $$->cur_result = $1->cur_result * $3->cur_result;}
	| expr '/' expr { $$ = insertNode(0, 0, '/', $1, $3);
                          $$->cur_result = $1->cur_result / $3->cur_result;}
        | '(' expr ')' 	{ $$ = $2; } 
        | RNUMBER 	{ $$ = insertNode( 1, $1, '\0', NULL, NULL );
		    	  $$->cur_result = $1;}
        ; 
%% 
void yyerror (const char *message) {
	error = 1;
	fprintf (stderr, "%s\n", message);
}

struct node * insertNode(int type, double data, char op, struct node * left, struct node * right) 
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->type = type;
    newNode->data = data;
    newNode->operator = op;
    newNode->left = left;
    newNode->right = right;
    return newNode;
} 

void printpre(struct node *root)
{
	if(root->left != NULL)
	{
		printf("%c ", root->operator);
		printpre(root->left);
	}
	if(root->right != NULL)
	{
		printpre(root->right);
	}
	if(root->type == 1)
        {
                printf("%.0f ", root->cur_result);
        }

}

int main(int argc, char *argv[]) {
        yyparse();
	if(error == 0)
	{
		printf("the preorder expression is : ");
		printpre(head);
		printf("\nthe result is : %.0f\n", result);
	}
	
        return 0;
}
