%{

#include <stdio.h>
#include <string.h>
int yylex(void);
int answer;
int flag= 0;
void yyerror(const char *message); 
struct node * insertNode(int type, int  data, char op, struct node *left, struct node *right);
struct node{
	int type;
	char op;
	int data,cur_result;
	struct node  *left,*right;
};
void traversal (struct node* root);
 %}
%union {
        int ival;
	struct node *nptr;
}
%token <ival> INUMBER
%type <nptr> expr
%left '+' '-'
%left '*' '/' 
%nonassoc '('
%right UMINUS
%%
 line : expr {printf("the preorder expression is : ");traversal($1);printf("\nThe result is : %i\n", $1->cur_result);}   
	;
expr	: '(' expr ')'  { $$ = $2; }
	| expr '+' expr {$$=insertNode(0,0, '+', $1, $3 ); $$->cur_result = $1->cur_result + $3->cur_result; } 
	| expr '-' expr {$$=insertNode(0,0, '-', $1, $3 ); $$->cur_result = $1->cur_result - $3->cur_result; }  
	| expr '*' expr {$$=insertNode(0,0, '*', $1, $3 ); $$->cur_result = $1->cur_result * $3->cur_result; }
	| expr '/' expr {$$=insertNode(0,0, '/', $1, $3 ); $$->cur_result = $1->cur_result / $3->cur_result; }
	| INUMBER	{$$=insertNode(1,$1, '\0', NULL, NULL ); $$->cur_result = $1; }
	;
%% 		
void   yyerror   (const char *message) {
	printf ("Invalid input\n");
	flag = 1;
}
void traversal(struct node* root){
	
	if (!root) return;
	if( root->type==1){
		printf("%i ",root->data);
	}
	else
		printf("%c ",root->op);     	
    	traversal(root->left); 
    	traversal(root->right);
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
int main(int argc, char *argv[]) {
        yyparse();
        return 0;
}
