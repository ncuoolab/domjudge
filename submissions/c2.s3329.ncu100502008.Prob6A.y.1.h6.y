%{
#include <stdio.h>
#include <string.h>
void yyerror(const char *message);
int ans; 
int flag=0;
%} 
%union{ 
int ival;
char* word;
}
%token <ival> INUMBER
%token <word> LOAD <word> ADD <word> SUB <word> MUL <word> MOD
%token <word> INC <word> DEC
%type  <ival> expr
%nonassoc ra
%nonassoc rb 
%%
line : expr             {ans=$1;}
     ;
expr : LOAD INUMBER	{$$=$2;}
     | expr expr ADD 	{$$=$2+$1;}
     | expr expr SUB 	{$$=$2-$1;}
     | expr expr MUL 	{$$=$2*$1;}
     | expr expr MOD 	{$$=$2%$1;}
     | expr INC	 	{$$=$1+1;}
     | expr DEC	 	{$$=$1-1;}
     ;
%% 
void yyerror (const char *message) {
        printf ("Invalid format\n");
	flag=1;
}
int main(int argc, char *argv[]) {
        yyparse();
	if(flag!=1){
		printf("%d\n",ans);
	}
        return(0);
}
