%{
#include<stdio.h>
#include<string.h>
void yyerror(const char *message);
char *word;
int result;
int flag;
int i;
char *buffer;
%}
%union{
int ival;
}
%token<ival> INUMBER
%type<ival> expr
%left '+''-'
%left '*''/'
%right '('')'
%%
start:expr	{result=$1;}
;
expr:expr'+'expr	{
	$$=$1+$3;
	strcat(word,"+");
	sprintf(buffer,"%d",$1);
	strcat(word,buffer);
	strcpy(buffer,"");	
	
	sprintf(buffer,"%d",$3);
        strcat(word,buffer);
        strcpy(buffer,"");
}
    |expr'-'expr	{
	$$=$1-$3;
	 strcat(word,"-");
        sprintf(buffer,"%d",$1);
        strcat(word,buffer);
        strcpy(buffer,"");
        sprintf(buffer,"%d",$3);
        strcat(word,buffer);
        strcpy(buffer,"");

	}
    |expr'*'expr	{
	$$=$1*$3;
	 strcat(word,"*");
        sprintf(buffer,"%d",$1);
        strcat(word,buffer);
        strcpy(buffer,"");
        sprintf(buffer,"%d",$3);
        strcat(word,buffer);
        strcpy(buffer,"");

	}
    |expr'/'expr	{
	$$=$1/$3;
	 strcat(word,"/");
        sprintf(buffer,"%d",$1);
        strcat(word,buffer);
        strcpy(buffer,"");
        sprintf(buffer,"%d",$3);
        strcat(word,buffer);
        strcpy(buffer,"");

	}
    |'('expr')'	{$$=$2;}
    |INUMBER
;
;
%%
void yyerror(const char*message){
	flag=1;
}
int main(int argc, char *argv[]){
	word=malloc(1024);
	word[0]='\0';
	buffer=malloc(1024);
	buffer[0]='\0';
	yyparse();
	if(flag!=1){
		printf("the preorder expression is : %s\n",word);
		printf("the reslut is : %d\n",result);
	}
	else{
        	printf("Invalid format\n");
	}
	return(0);
}
