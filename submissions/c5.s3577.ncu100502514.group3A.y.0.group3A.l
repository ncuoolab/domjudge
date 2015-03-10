%{

//typedef declarations
#ifndef MYDATA_DECLARED
#define MYDATA_DECLARED
typedef struct{
	double dval;
	char *preorder;
} MyData;
#endif

#include "group3A.tab.h" //[!!Remember!!] "filename.tab.h"
%}

num [0-9]+(\.[0-9]+)?

%%

{num} {
	yylval.exVal = malloc(sizeof(MyData));
	yylval.exVal->dval = atof(yytext);
	yylval.exVal->preorder = strdup(yytext);
	return DEC_TYPE; //will be defined in yacc file
}
[ \t]+ { /*do nothing when whitespace occurs*/ }
[\n\r] { /*force end when newline occurs*/ return 0; }
. { return yytext[0]; }

%%

// DO NOT WRITE main() HERE!!
// We are gonna write that in the YACC file.
