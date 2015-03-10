digit		[0-9]
letter		[a-zA-Z]
column		({digit}|{letter})*
noodles		{column}\t{column}\t{column}noodles{column}\t{column}

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
