%{
#include <stdio.h>
#include <string.h>
void yyerror(const char* message);
struct node* insertNode(int type, int data, char op, struct node* left, struct node* right);
struct node {
	int type;
	char operator;
	int data;
	int cur_result;
	struct node* left;
        struct node* right;
};
void preOrder(struct node* tree);
struct node* answer;
int flag = 1;
%}

%union {
struct node* nptr;
int ival;
}

%token<ival> INUMBER
%type<nptr> expr
%left '+' '-'
%left '*' '/'
%nonassoc '(' ')'

%%
line	: expr { answer = $1; }
	;
expr	: expr '+' expr {
	    $$ = insertNode(0, 0, '+', $1, $3);
	    $$->cur_result = $1->cur_result + $3->cur_result;
	}
	| expr '-' expr {
	    $$ = insertNode(0, 0, '-', $1, $3);
	    $$->cur_result = $1->cur_result - $3->cur_result;
	}
	| expr '*' expr {
            $$ = insertNode(0, 0, '*', $1, $3);
	    $$->cur_result = $1->cur_result * $3->cur_result;
	}
	| expr '/' expr {
	    $$ = insertNode(0, 0, '/', $1, $3);
	    $$->cur_result = $1->cur_result / $3->cur_result;
	}
        | '(' expr ')'  { $$ = $2; }
        | INUMBER	{
	    $$ = insertNode(1, $1, '\0', NULL, NULL);
            $$->cur_result = $$->data;
	}
%%

struct node* insertNode(int type, int data, char op, struct node* left, struct node* right) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->type = type;
    newNode->data = data;
    newNode->operator = op;
    newNode->left = left;
    newNode->right = right;
    return newNode;
}

void preOrder(struct node* tree) {
	if ( tree != NULL ) {
		if ( tree->operator == '\0' ) {
		    printf("%d ", tree->cur_result);
		} else {
                    printf("%c ", tree->operator);
		}
		if ( tree->left != NULL ) preOrder(tree->left);
		if ( tree->right != NULL ) preOrder(tree->right);
	}
}
void yyerror(const char* message) {
	fprintf(stderr, "%s\n", message);
	flag = 0;
}

int main(int argc, char* argv[]) {
	yyparse();
	if ( flag == 1 ) {
		printf("the preorder expression is : ");
		preOrder(answer);
		printf("\nthe result is : %d\n", answer->cur_result);
	}
	return 0;
}
