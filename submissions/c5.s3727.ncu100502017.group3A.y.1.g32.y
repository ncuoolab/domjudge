%{
#include <stdio.h>
#include <string.h>
int yylex(void);
void yyerror(const char *message);
int result=0;
struct node * insertNode(int type, double data, char op, struct node *left, struct node *right);
void outTree();
void outnode(struct node *ths);
struct node {
    int type;
    char op;
    double data,cur_result;
    struct node *left,*right; 	
};
struct node *end;
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
line : expr {end=$1;}
     ;
expr : expr '+' expr { $$ = insertNode( 0, 0, '+', $1, $3 ); $$->cur_result = $1->cur_result + $3->cur_result; }
     | expr '-' expr { $$ = insertNode( 0, 0, '-', $1, $3 ); $$->cur_result = $1->cur_result - $3->cur_result; }
     | expr '*' expr { $$ = insertNode( 0, 0, '*', $1, $3 ); $$->cur_result = $1->cur_result * $3->cur_result; }
     | expr '/' expr { $$ = insertNode( 0, 0, '/', $1, $3 ); $$->cur_result = $1->cur_result / $3->cur_result; }
	 | '(' expr ')'  {$$ = $2; }
	 | RNUMBER { $$ = insertNode( 1, $1, '\0', NULL, NULL ); $$->cur_result = $1; }
	 ;
%%

void yyerror(const char *message){
     printf("Wrong Formula.");
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

void outTree(){
	printf("%c",end->op);
	outnode(end->left);
	outnode(end->right);
}
void outnode(struct node *ths){
	if(ths->type==0){
		printf("%c",ths->op);	
	}
	else{
		printf("%1f",ths->data);	
	}
	if(ths->left!=NULL){
		outnode(ths->left);
	}
	if(ths->right!=NULL){
		outnode(ths->right);
	}
}
int main(int argc, char *argv[]){
    yyparse();
	outTree();
	
	return 0;
}