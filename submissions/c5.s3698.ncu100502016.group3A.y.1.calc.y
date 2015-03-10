%{

#include <stdio.h>
#include <string.h>
int yylex(void);
void yyerror(const char *message);
void traverse(struct node *);

struct node {
	int type;
	char op;
    double data,cur_result;
    struct node *left,*right; 	
};

int flag = 0;
double result;
struct node *rnode;

%}
%union {
        double rval;
		struct node *nptr;
}

%token<rval> RNUMBER
%type<nptr> expr
%left '+' '-'
%left '*' '/'

%%

line	: expr {  rnode = $1;}
	;

expr	: '(' expr ')'  { $$ = $2; }
	| expr '+' expr { $$ = insertNode( 0, 0, '+', $1, $3 ); $$->cur_result = $1->cur_result + $3->cur_result; } 
	| expr '-' expr { $$ = insertNode( 0, 0, '-', $1, $3 ); $$->cur_result = $1->cur_result - $3->cur_result; }  
	| expr '*' expr { $$ = insertNode( 0, 0, '*', $1, $3 ); $$->cur_result = $1->cur_result * $3->cur_result; }
	| expr '/' expr { $$ = insertNode( 0, 0, '/', $1, $3 ); $$->cur_result = $1->cur_result / $3->cur_result; }
	| RNUMBER	{ $$ = insertNode( 1, $1, '\0', NULL, NULL ); $$->cur_result = $1; }
	;
	
%%

void yyerror (const char *message) {
	flag = 1;
}

int main(int argc, char *argv[]) {
        yyparse();
		traverse(rnode);
		if(flag != 1){
			printf("the preorder expression is : ");
			traverse(rnode);
			printf("\nthe result is : %.0f\n",result);
		}else{
			printf("error");
		}
        return 0;
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

void traverse(struct node *n){
	if(n!=NULL){
		if(n->type==0)
			printf("%c ",n->op);
		else
			printf("%.0f ",n->data);
		traverse(n->left);
		traverse(n->right);
	}

}
