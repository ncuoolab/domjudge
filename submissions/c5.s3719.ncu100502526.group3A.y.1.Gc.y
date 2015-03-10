%{

#include<stdio.h>
int yylex();
void yyerror(char *message);
struct node * insertNode(int type, double data, char op, struct node *left, struct node *right);
char* a;
struct node {
    int type;
    char op;
    double data,cur_result;
    struct node *left,*right; 	
};
struct node* f;
void pre(struct node * n);
double ans;
int flag=0;
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

line	: expr { f = $1; }
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
	flag=1;
}

void pre(struct node * n){
	if(n->type==0){
		printf("%c ",n->op);
	}
	else
		printf("%.0f ",n->data);
	if(n->left!=NULL){
	pre(n->left);
	}
	if(n->right!=NULL){
	pre(n->right);
	}
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
	if(flag!=1){
		printf("the preorder expression is : ");
		ans=f->cur_result;
		pre(f);
		printf("\nthe result is : %.0f\n",ans);
	}
	return 0;
}

