%{

%}
number     ([0-1][0-9][0-9])|([2][0-4][0-9])|([2][5][0-5])|([0-9][0-9])|([0-9])
ip         ^{number}["."]{number}["."]{number}["."]{number}

%%
{ip}       {ECHO;}
.          {}

%%
int main(int argc , char *argv[]){
	yylex();
	return(0);
}
