%{

%}
match	(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)
other	.|\n
%%
{match}	{ ECHO; printf("\n");}
{other}	{}
%%
int main(int argc, char *argv[]) {
    yylex();
    return(0);
}