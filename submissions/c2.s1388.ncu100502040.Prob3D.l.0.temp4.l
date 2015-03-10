%{
%}
%x		C
digit		[0-1]?[0-9]?[0-9]
digit1		[2][0-4][0-9]
digit2		[2][5][0-5]
digit3		({digit}|{digit1}|{digit2})
point		[.]
identifier	{digit3}{point}{digit3}{point}{digit3}{point}{digit3}
%%
{identifier}	{ECHO; printf("\n"); BEGIN C;}
<C>\n		{BEGIN INITIAL;}
<C>.		;
\n		;
.		;
%%
int main(int argc, char *argv[]) {

        yylex();
        return(0);
}

