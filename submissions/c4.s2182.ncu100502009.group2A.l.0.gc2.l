%{
unsigned int count=0,i=0,line=0;
%}
eol	\n
tab 	\t
digit	[a-z]
%%
{digit} {if(line==1){
		for(;i<count;i++)
			printf("\t");}
	 line=0;
	 ECHO;
	}
"{"	{i=0;
	 for(;i<count;i++)
		printf("\t");
	 count++;
	 ECHO;
	 line=0;}
"}"	{count--;
	 i=0;
	 for(;i<count;i++)
		printf("\t");
	 ECHO;
	 line=0;
	}
{tab}	{/*do nothing*/}
{eol}	{ECHO;i=0;line=1;}
.	{ECHO;}
%%
int main(int argc, char* argv[]){
	yylex();
	return(0);
}
