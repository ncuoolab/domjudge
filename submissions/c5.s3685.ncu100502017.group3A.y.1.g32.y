%{
#include <stdio.h>
#include <string.h>
int yylex(void);
void yyerror(const char *message);
int result=0;
struct node * insertNode(int type, double data, char op, struct node *left, struct node *right);

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

int main(int argc, char *argv[]){
    yyparse();
	printf("%c",end.char);
	
	return 0;
}