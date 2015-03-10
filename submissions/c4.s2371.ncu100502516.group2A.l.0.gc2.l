%{
int count=0;

%}


word		[a-zA-Z]

%%

"{"		{ECHO;count++;BEGIN(into);}

^({word}|"/")	{int i=0;for(i;i<count;i++){printf("\t");}ECHO;}

"\t"+"}"	{int i=0;for(i;i<count-1;i++){printf("\t");}printf("}");count--;}

"\t"*	{int i=0;for(i;i<count;i++){printf("\t");}}

^"{"	{int i=0;for(i;i<count;i++){printf("\t");}ECHO;count++;BEGIN(into);}
"{"	{ECHO;count++;BEGIN(into);}

^"}"	{int i=0;for(i;i<count-1;i++){printf("\t");}ECHO;count--;}
"}"	{ECHO;count--;}
<into>.		{ECHO;}	

"\n"	{int i=0;for(i;i<count;i++){printf("\t");}ECHO;}


.		{ECHO;}

\n		{int i=0;for(i;i<count;i++){printf("\t");}ECHO;}

%%

int main(char *argc)

{
	
	yylex();

	return 0;

}
