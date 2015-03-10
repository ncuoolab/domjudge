%{
// BEGIN BASIC HEADERS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void yyerror(const char* msg);
// END BASIC HEADERS

// Advanced Declarations

#ifndef NULL
#define NULL 0
#endif

#define true 1
#define false 0
#define bool char

double result = 0.0;
char *preorderResult = "";
char tmpBuffer[4096] = {'\0'}; //4KB buffer
bool isInvalid = false, isOK = false;

int roundFunc(double d){
	return (int)(floor(d+0.5));
}
char* makePreorderElement(char *oper, char *a, char *b){
	int ptr = 0, i;
	for(i=0; oper[i]!='\0'; i++)tmpBuffer[ptr++]=oper[i];
	tmpBuffer[ptr++] = ' '; //separate by a space
	for(i=0; a[i]!='\0'; i++)tmpBuffer[ptr++]=a[i];
	tmpBuffer[ptr++] = ' '; //separate by a space
	for(i=0; b[i]!='\0'; i++)tmpBuffer[ptr++]=b[i];
	tmpBuffer[ptr] = '\0';
	return strdup(tmpBuffer);
}


#ifndef MYDATA_DECLARED
#define MYDATA_DECLARED
typedef struct{
	double dval;
	char *preorder;
} MyData;
#endif

%}

%union{
	MyData *exVal;
	char tmpType;
}

//[Token Type Declarations]
//Example:
//%token <ival> INT_TYPE //called in Lex file, determining the C-lang type
//%type <ival> IntToken //the token name we defined here (as LHS)

%start Whole

%token <exVal> DEC_TYPE
%token <tmpType> SPACE_TYPE

%type <exVal> Stmt

//operator precedence declaration
//%left '+' '-'
//%left '*' '/'
//%nonassoc '^'

%%

// Grammar Declarations here, with ':' as the "arrow", and ';' as the "end of a rule"
// Note: Each rule will be read as "$$ : $1 $2 $3 ... $n",
// while $0 is $$'s parent, $-1 is $0's parent, $-2 is $-1's parent, ...
// Types must be marked, e.g. $<ival>-1, $<ival>0,
// otherwise the default type is integer.

Whole:
	Stmt {
		//write the result to be printed
		//preorderResult = strdup($1->preorder);
		result = $1->dval;
		isOK = true;
	}
	;
Stmt:
	Stmt SPACE_TYPE Stmt SPACE_TYPE '+' {
		$$ = malloc(sizeof(MyData));
		//$$->preorder = makePreorderElement("+", $1->preorder, $3->preorder);
		$$->dval = $1->dval + $3->dval;
	}
|	Stmt SPACE_TYPE Stmt SPACE_TYPE '-' {
		$$ = malloc(sizeof(MyData));
		//$$->preorder = makePreorderElement("-", $1->preorder, $3->preorder);
		$$->dval = $1->dval - $3->dval;
	}
|	Stmt SPACE_TYPE Stmt SPACE_TYPE '*' {
		$$ = malloc(sizeof(MyData));
		//$$->preorder = makePreorderElement("*", $1->preorder, $3->preorder);
		$$->dval = $1->dval * $3->dval;
	}
|	Stmt SPACE_TYPE Stmt SPACE_TYPE '/' {
		$$ = malloc(sizeof(MyData));
		//$$->preorder = makePreorderElement("/", $1->preorder, $3->preorder);
		$$->dval = $1->dval / $3->dval;
	}
|	DEC_TYPE {
		$$ = malloc(sizeof(MyData));
		//$$->preorder = strdup($1->preorder);
		$$->dval = $1->dval;
	}
	;

%%

void yyerror(const char *msg){
	//error message here
	printf("Wrong Formula\n");
	isInvalid = true;
	//fprintf(stderr, "%s", msg);
}
main(){
	yyparse();
	if(!isInvalid){
		if(isOK){
			printf("%.1lf\n", result);
		}
		else yyerror("");
	}
	return 0;
}
