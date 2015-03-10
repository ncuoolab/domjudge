%{
    int count = 0;
%}

eol    	\n
BL	(\{)
BR	(\})
L	(\()
R	(\))

%%

{L}{R}{BL}      {count++;ECHO;}

{BL}		{count++;printf("\t");ECHO;}

{BR}          	{count--;if(count > 0) printf("\t"); ECHO;}

^.	       	{if(count == 1) printf("\t");else if(count == 2) printf("\t\t");ECHO;}


%%

int main(int argc,char *argv[]){
	yylex();
	return(0);
}