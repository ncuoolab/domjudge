%{

%}
one [0-9]
two [1-9][0-9]
three1 1[0-9][0-9]
three2 2[0-4][0-9]
three3 25[0-5]
goal ({one}|{two}|{three1}|{three2}|{three3})"."({one}|{two}|{three1}|{three2}|{three3})"."({one}|{two}|{three1}|{three2}|{three3})"."({one}|{two}|{three1}|{three2}|{three3})
%%
{goal}	{if(yyleng>=7) ECHO;if(yyleng>=7) printf("\n");}
.|\n	{}
%%
int main(int argc, char *argv[]) {
	yylex();
	return(0);
}