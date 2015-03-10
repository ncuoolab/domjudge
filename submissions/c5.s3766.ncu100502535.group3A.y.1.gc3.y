%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yylex(void);
void yyerror(const char *message);
struct Node* calc(struct Node* left, struct Node* right, char op);
void printNode(struct Node* node);
struct Node* uminus(struct Node* node);
char* strcatChar(char* array, char a);
void printPre(struct Node* node);
struct Node* createNode(int value);

struct Node {
	int result;
	char op;
	struct Node* left;
	struct Node* right;
};

%}
%union {
    int ival;
	struct Node* node;
}

%token <ival> RNUMBER
%type <node> expr
%left '+' '-'
%left '*' '/'
%right UMINUS

%%

line    : expr                  { printNode($1); }
		;
expr    : expr '+' expr         { $$ = calc($1, $3, '+'); }
		| expr '-' expr         { $$ = calc($1, $3, '-'); }
        | expr '*' expr         { $$ = calc($1, $3, '*'); }
        | expr '/' expr         { $$ = calc($1, $3, '/'); }
        | '(' expr ')'          { $$ = $2; }
        | '-' expr %prec UMINUS {}
        | RNUMBER				{ $$ = createNode($1);}
        ;

%%

struct Node* calc(struct Node* left, struct Node* right, char op) {
    struct Node* newNode = malloc(sizeof(struct Node));
    switch(op) {
    	case '+':
    		newNode->result = left->result + right->result;
    		break;
    	case '-':
    		newNode->result = left->result - right->result;
    		break;
    	case '*':
    		newNode->result = left->result * right->result;
    		break;
    	case '/':
    		newNode->result = left->result / right->result;
    		break;
    }
	newNode->left = left;
	newNode->right = right;
	newNode->op = op;
    return newNode;
}

void printNode(struct Node* node) {
	printf("%s ", "the preorder expression is : ");
	printPre(node);
	printf("%s ", "\nthe result is : ");
	printf("%d\n", node->result);
}

void printPre(struct Node* node) {
	if (node!=NULL)	{
		if (node->op=='\0')	{
			printf("%d ", node->result);
		} else {
			printf("%c ", node->op);
		}
		if (node->left != NULL) {
			printPre(node->left);
		}
		if (node->right != NULL) {
			printPre(node->right);
		}
	}
}

struct Node* createNode(int value) {
	struct Node* newNode = malloc(sizeof(struct Node));
	newNode->op = '\0';
	newNode->result = value;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void yyerror (const char *message) {
	fprintf(stderr, "%s\n", message);
}

int main(int argc, char *argv[]) {
        yyparse();
        return 0;
}
