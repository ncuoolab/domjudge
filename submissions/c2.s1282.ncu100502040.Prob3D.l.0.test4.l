%{
#define correct 123
%}
digit		[0-9]
point		[.]
identifier	{digit}+{point}{digit}+{point}{digit}+{point}{digit}+
%%
{identifier}	return(correct);
.		;
%%
int main(int argc, char *argv[]) {
      	int temp;
	do
        {
                temp = yylex();
                if(temp == 123)
                {
                	
			printf("%s", yytext);

                }
        }while(temp == 123);
	return(0);
}

