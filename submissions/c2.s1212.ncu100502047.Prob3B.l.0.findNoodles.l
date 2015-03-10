%{
char item[4][100] = {'\0'} ;
int number=0;
%}
letter		[a-zA-Z]
digit		[0-9]
word		({letter}|{digit})+
changeline	\n
%%
{changeline}	{	if(number == 4){
				if(strcmp(item[2],"noodles")==0){
					int i;
					for(i=0;i<4;i++){
					printf("%s	",item[i]);
					}
					printf("\n");
				}
			number = 0;
			}else{
			/*nothing*/
			}
		}
{word}	{strcpy(item[number], yytext); number++;}
.	{/*nothing*/}
%%
int main(int argc, char *argv[]){
	yylex();
	return 0;
}
