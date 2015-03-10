%{
#include <stdio.h>
#include <string.h>
int yylex();
void yyerror(const char *message);
struct node *new(int type,int data,char op,struct node *left,struct node *right);
void preOrder(struct node *tmp);
struct node{
	int type,data,sum;
	char op;
	struct node *left,*right;
};
enum{OPERATOR,OPERAND};
%}
%union {
	int ival;
	struct node *nptr;
}
%token <ival> INUMBER
%type <nptr> expr
%left '+' '-'
%left '*' '/'
%%
line : expr { printf("the preorder expression is : "); preOrder($1);printf("\nthe result is : %d\n",$1->sum); }
	;
expr : expr '+' expr {$$ = new(OPERATOR,0,'+',$1,$3); $$->sum=$1->sum+$3->sum;}
	| expr '-' expr {$$ = new(OPERATOR,0,'-',$1,$3); $$->sum=$1->sum-$3->sum;}
	| expr '*' expr {$$ = new(OPERATOR,0,'*',$1,$3); $$->sum=$1->sum*$3->sum;}
	| expr '/' expr {$$ = new(OPERATOR,0,'/',$1,$3); $$->sum=$1->sum/$3->sum;}
	| '('expr')' 	{$$ = $2;}
        | INUMBER	{$$ = new(OPERAND,$1,'\0',NULL,NULL); $$->sum = $1;}
        ;

%%

void yyerror (const char *message) {
        fprintf (stderr, "%s\n",message);
}

struct node *new(int type, int data, char op,struct node *left, struct node *right){
	struct node *tmp = malloc(sizeof(struct node));
	tmp->type = type;
	tmp->data = data;
	tmp->op = op;
	tmp->left = left;
	tmp->right = right;
	return tmp;
}


void preOrder(struct node *tmp){
	if(tmp == NULL)
		return;
	if(tmp->type == OPERATOR)
		printf("%c ",tmp->op);
	else if (tmp->type == OPERAND)
		printf("%d ",tmp->data);
	preOrder(tmp->left);
	preOrder(tmp->right);
}

int main(int argc, char *argv[]) {
        yyparse();
        return(0);
}

