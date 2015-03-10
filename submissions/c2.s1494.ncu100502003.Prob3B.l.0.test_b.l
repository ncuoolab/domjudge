digit		[0-9]
letter		[a-zA-Z]
space		[ ]
column		({digit}|{letter})+
column2		({digit}|{letter})*
noodles		^{column}{space}+{column}{space}+{column2}noodles{column2}{space}+{column}

%%

{noodles}	{ECHO; printf("\n");}
.
\n

%%
int main()
{
	yylex();
	return(0);
}
