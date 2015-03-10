digit		[0-9]
letter		[a-zA-Z]
space		[ \t]
column		({digit}|{letter})*
noodles		{column}{space}*{column}{space}*{column}noodles{column}{space}*{column}

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
