%{
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
void yyerror(const char *message);
int s[100]={-200,-200,-200};
int i = 0;
int sum = 0;
%}
%union{
	int ival;
}
%token<ival> ADD
%token<ival> SUB
%token<ival> MUL
%token<ival> MOD
%token<ival> INC
%token<ival> DEC
%token<ival> NUMBER
%type<ival> exprs
%type<ival> expr
%%
line : exprs	{if(s[1] > -100){printf("Invalid format");exit(1);}else{printf("%d\n",s[0]);}}
     ;
exprs: exprs expr	{}
     | expr		{}
     ;
expr : 'load' expr	{s[i] = $2; i++;}
     | ADD 	{ 
     			if(s[i-1]>-100 && s[i-2]>-100 && i > 1 )
     			{s[i-2] = s[i-1]+s[i-2];
			 s[i-1] = -200;
			 i--;
			}else{
				printf("Invalid format");
				exit(1);
			}
		}
     | SUB 	{
     			if(s[i-1]>-100 && s[i-2]>-100 && i > 1)
     			{s[i-2] = s[i-1]-s[i-2];
			 s[i-1] = -200;
			 i--;
			}else{
				printf("Invalid format");
				exit(1);
			}
		}
     | MUL 	{
     			if(s[i-1]>-100 && s[i-2]>-100&& i > 1)
     			{s[i-2] = s[i-1]*s[i-2];
			 s[i-1] = -200;
			 i--;
			}else{
				printf("Invalid format");
				exit(1);
			}
}
     | MOD 	{
     			if(s[i-1]>-100 && s[i-2]>-100&& i > 1)
     			{s[i-2] = s[i-1]%s[i-2];
			 s[i-1] = -200;
			 i--;
			}else{
				printf("Invalid format");
				exit(1);
			}
}
     | INC 	{ if(i > 0 && s[i-1]>-100){s[i-1]++;}else{printf("Invalid format");exit(1);}}
     | DEC 	{ if(i > 0 && s[i-1]>-100){s[i-1]--;}else{printf("Invalid format");exit(1);}}
     | NUMBER	{$$ = $1;}
     ;

%%
void yyerror(const char *message){
	fprintf(stderr,"%s\n",message);
}
int main(int argc, char *argv[]){
	yyparse();
	return 0;
}

