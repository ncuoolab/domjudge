%{
#include <stdio.h>
#include <string.h>
int yylex(void);
void yyerror(const char *message);
struct node *insertnode(int type, int data, char op, struct node *left, struct node *right);
struct node{
	int type;
	char op;
	int data,curresult;
	struct node *left, *right;
};
void preorder(struct node *n);
%}
%union{
int ival;
struct node *nptr;
}
%token <ival> INUMBER
%type <nptr> expr
%left '+' '-'
%left '*' '/'
%right UMINUS
%%
line    : expr                  {printf("the preorder expression is : ");preorder($1);printf("\nthe result is : %d\n", $1->curresult);}
        ;
expr    : expr '+' expr         {$$=insertnode(0,0,'+',$1,$3);$$->curresult = $1->curresult + $3->curresult;}
	| expr '-' expr		{$$=insertnode(0,0,'-',$1,$3);$$->curresult = $1->curresult - $3->curresult;}
	| expr '*' expr		{$$=insertnode(0,0,'*',$1,$3);$$->curresult = $1->curresult * $3->curresult;}
	| expr '/' expr		{$$=insertnode(0,0,'/',$1,$3);$$->curresult = $1->curresult / $3->curresult;}
	| '(' expr ')'		{$$=$2;}
        | INUMBER		{$$=insertnode(1,$1,'\0',NULL,NULL);$$->curresult = $1;}
        ;
%%
void yyerror (const char *message)
{
        fprintf (stderr, "%s\n",message);
}

struct node *insertnode(int type, int data, char op, struct node *left, struct node *right){
	struct node *newnode = malloc(sizeof(struct node));
	newnode->type = type;
	newnode->data = data;
	newnode->op = op;
	newnode->left = left;
	newnode->right = right;
	return newnode;
}

void preorder(struct node *n){
	if(!n)return;
	if(n->type==0){
		printf("%c ", n->op);
	}
	else{
		printf("%i ", n->data);
	}
	preorder(n->left);
	preorder(n->right);
}

int main(int argc, char *argv[]) {
        yyparse();
        return(0);
}
