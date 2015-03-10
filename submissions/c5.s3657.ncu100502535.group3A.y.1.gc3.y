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
struct Node* createNode(int value);

struct Node {
	int result;
	char* preorder;
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
        | '-' expr %prec UMINUS { $$ = uminus($2); }
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

    	strcatChar(newNode->preorder, op);
    	strcat(newNode->preorder, " ");
    	strcat(newNode->preorder, left->preorder);
    	strcat(newNode->preorder, " ");
    	strcat(newNode->preorder, right->preorder);
    }
    return newNode;
}

struct Node* uminus(struct Node* node) {
    node->result = -(node->result);
    node->preorder = strcat(" ", node->preorder);
}

char* strcatChar(char* array, char a) {
    size_t len = strlen(array);
    char* ret = (char*)malloc((len+2)*sizeof(char*));
    strcpy(ret, array);    
    ret[len] = a;
    ret[len+1] = '\0';
    return ret;
}

void printNode(struct Node* node) {
	printf("%s\n", node->preorder);
	printf("%d\n", node->result);
}

struct Node* createNode(int value) {
	struct Node* newNode = malloc(sizeof(struct Node));
	newNode->result = value;


	char buffer[12];
	int i = value;
	snprintf(buffer, 12, "%d", i);


	newNode->preorder = buffer;
	return newNode;
}

void yyerror (const char *message) {
	fprintf(stderr, "%s\n", message);
}

int main(int argc, char *argv[]) {
        yyparse();
        return 0;
}
