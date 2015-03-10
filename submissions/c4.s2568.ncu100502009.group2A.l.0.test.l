%{
unsigned int count=0,i=0,line=0;
%}
eol	\n
tab 	\t
digit	[a-z]
%%
{digit} {if(line==1){
		line=0;
		for(;i<count;i++)
			printf("\t");
		ECHO;
		}
	 else if(line==0)
	 {
		ECHO;
	 }
	}
"{"	{if(line==1){
	 	i=0;
	 	for(;i<count;i++)
			printf("\t");
	 	ECHO;
		count++;
		line=0;}
	 else if(line==0){ 
		ECHO;
		count++;}
	}
"}"	{if(line==1){
	 	count--;
	 	i=0;
	 	for(;i<count;i++)
			printf("\t");
	 	ECHO;
	 	line=0;}
	 else if(line==0){
	 	ECHO;
	 	count--;}
	}
{tab}   {/*do nothing*/}
{eol}   {ECHO;i=0;line=1;}
.       {ECHO;}
%%
int main(int argc, char* argv[]){
	yylex();
	return(0);
}
