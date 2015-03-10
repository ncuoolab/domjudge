%{
#include <stdio.h>
%}
name            [a-zA-Z0-9]+
career          [a-zA-Z0-9]+
hometown        [a-zA-Z0-9]+
check		noodles
space		[ \t]+
line		\n{name}{space}{career}{space}{check}{space}{hometown}
%%
{line}		ECHO;
\n		ECHO;
.		{/*do nothing*/}
%%
int main(int argc, char *argv[]) {
	yylex();
        return(0);
}

