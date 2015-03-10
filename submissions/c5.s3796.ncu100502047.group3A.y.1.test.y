%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void yyerror(const char *message);
char preorder[100]={'\0'};
struct node * insertNode(int data, char op, struct node *left, struct node *right);
struct node{
	char op;
	int data, cur_result;
	struct node *left, *right;
};
struct node *tree;
%}
%union{
	int i;
	struct node *n;
}
%token<i> INTEGER
%type<n> expr
%left'+''-'
%left'*''/'

%%
line : expr	{tree = $1;}
     ;
expr : '('expr')'	{$$ = $2;}
     | expr '+' expr	{$$ = insertNode(0,'+',$1,$3);$$->cur_result = $1->cur_result + $3->cur_result;}
     | expr '-' expr	{$$ = insertNode(0,'-',$1,$3);$$->cur_result = $1->cur_result - $3->cur_result;}
     | expr '*' expr	{$$ = insertNode(0,'*',$1,$3);$$->cur_result = $1->cur_result * $3->cur_result;}
     | expr '/' expr	{$$ = insertNode(0,'/',$1,$3);$$->cur_result = $1->cur_result / $3->cur_result;}
     | INTEGER		{$$ = insertNode($1,'\0',NULL,NULL); $$->cur_result= $1;}
     ;
%%
void yyerror(const char *message){
	fprintf(stderr,"%s\n",message);
}


struct node * insertNode(int data, char op, struct node *left, struct node *right) {
    struct node *newNode= malloc(sizeof(struct node));
    newNode-> data= data;
    newNode-> op = op;
    newNode -> left = left;
    newNode-> right = right;
    return newNode;
}

void tra(struct node *p){
	if(!p) return;
	if(p->op == '\0'){
		printf("%d ",p-> cur_result);
	}else{
		printf("%c ",p-> op);
	}
	tra(p->left);
	tra(p->right);
}

int main(int argc, char *argv[]){
	yyparse();
	printf("the preorder expression is : ");
	tra(tree);
	printf("\nthe result is : ");
	printf("%d\n",tree->cur_result);

	return 0;
}
