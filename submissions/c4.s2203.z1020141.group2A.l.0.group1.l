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

{BR}          	{count--;if(count == 1) printf("\t");else if(count == 2) printf("\t\t");else if(count == 3) printf("\t\t\t");else if(count == 4) printf("\t\t\t\t"); ECHO;}


^.	       	{if(count == 1) printf("\t");else if(count == 2) printf("\t\t");else if(count == 3) printf("\t\t\t");else if(count == 4) printf("\t\t\t\t");ECHO;}






%%

int main(int argc,char *argv[]){
	yylex();
	return(0);
}
