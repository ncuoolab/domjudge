digit		[0-9]
letter		[a-zA-Z]
column		({digit}|{letter})*
noodles		{column}\t{column}\tnoodles\t{column}

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
