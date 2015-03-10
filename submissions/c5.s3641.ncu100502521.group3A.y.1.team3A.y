%{
#include <stdio.h>
#include <string.h>
//int yylex(void);
void yyerror(const char *message);
struct tree {
	struct tree* left;
	struct tree* right;
	char operator;
	int leaf;
	int type;
	int value;
};
void print(struct tree* node_ptr) {
	if ( node_ptr->type == 1 ) printf(" %c",node_ptr->operator); else printf(" %d",node_ptr->leaf);
	if ( node_ptr->left != NULL ) print(node_ptr->left);
	if ( node_ptr->right != NULL ) print(node_ptr->right);
}
%}
%union {
int ival;
struct tree* node;
}
%token <ival> INUMBER
%type <node> expr
%left '+' '-'
%left '*' '/'

%%

start	: expr { printf("the preorder expression is :");
		print($1);
		printf("\nthe result is : %d\n",$1->value);
 }
		;
expr    : expr '+' expr { $$ = malloc(sizeof(struct tree)); $$->left = $1; $$->right = $3; $$->operator = '+'; $$->type = 1; $$->value = $1->value + $3->value; } 
		| expr '-' expr { $$ = malloc(sizeof(struct tree)); $$->left = $1; $$->right = $3; $$->operator = '-'; $$->type = 1; $$->value = $1->value - $3->value; }
		| expr '*' expr { $$ = malloc(sizeof(struct tree)); $$->left = $1; $$->right = $3; $$->operator = '*'; $$->type = 1; $$->value = $1->value * $3->value; }
		| expr '/' expr { $$ = malloc(sizeof(struct tree)); $$->left = $1; $$->right = $3; $$->operator = '/'; $$->type = 1; $$->value = $1->value / $3->value; }
		| '(' expr ')' { $$ = $2; $$->value = $2->value; }
		| INUMBER { $$ = malloc(sizeof(struct tree)); $$->leaf = $1; $$->type = 0; $$->value = $1; }
        ;
%%

void yyerror (const char *message)
{
        printf ("Invalid format\n");
}

int main(int argc, char *argv[]) {
        yyparse();
        return(0);
}
