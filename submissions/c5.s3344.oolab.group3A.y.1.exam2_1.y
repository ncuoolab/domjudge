%{

#include<stdio.h>

int yylex();
void yyerror(char *message);
struct node * new(int type, char op, int data, struct node *left, struct node *right);
void preorder (struct node *tmp);

struct node
{
    int type;
    char op;
    int data,cur_result;
    struct node *left,*right; 	
};

%}

%union {
    int ival;
    struct node *nptr;
}


%token<ival> INUMBER
%type<nptr> expr
%left '+' '-'
%left '*' '/'
%nonassoc UMINUS

%%

line	: expr { printf("the preorder expression is : ");
		 preorder($1);
		 printf("\nthe result is : %d\n", $1->cur_result) }
	;

expr	: '(' expr ')'  { $$ = $2; }
	| expr '+' expr { $$ = new( 0, '+', 0, $1, $3 ); $$->cur_result = $1->cur_result + $3->cur_result; } 
	| expr '-' expr { $$ = new( 0, '-', 0, $1, $3 ); $$->cur_result = $1->cur_result - $3->cur_result; }  
	| expr '*' expr { $$ = new( 0, '*', 0, $1, $3 ); $$->cur_result = $1->cur_result * $3->cur_result; }
	| expr '/' expr { $$ = new( 0, '/', 0, $1, $3 ); $$->cur_result = $1->cur_result / $3->cur_result; }
	| '-' expr %prec UMINUS {$$ = new(1,'u',$2->cur_result,NULL,NULL); $$->cur_result = 0 - $2->cur_result;}
	| INUMBER	{ $$ = new( 1, '\0', $1, NULL, NULL ); $$->cur_result = $1; }
	;

%%

void yyerror(char *message)
{
    printf("%s\n", message);
}

struct node * new(int type, char op, int data, struct node *left, struct node *right)
{
    struct node *tmp = malloc(sizeof(struct node));
    tmp->type=type;
    if(op=='u')
	tmp->data=-data;
    else
	tmp->data=data;
    tmp->op=op;
    tmp->left=left;
    tmp->right=right;
    return tmp;
}

void preorder(struct node *tmp)
{
    if(tmp == NULL)
	return ;
    if(tmp->type == 0)
	printf("%c ",tmp->op);
    if(tmp->type == 1)
	printf("%d ",tmp->data);
    preorder(tmp->left);
    preorder(tmp->right);
}

int main()
{
	yyparse();
	return 0;
}

