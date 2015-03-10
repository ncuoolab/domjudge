%{
%}
letter	[a-zA-Z]
ID		{letter}+[ ]+{letter}+[ ]+noodles[ ]+{letter}+

%%
{ID}		{ECHO; printf("\n");}
\n|.		;
%%
int main(int argc, char *argv[]){
		yylex();
		return 0;
}
