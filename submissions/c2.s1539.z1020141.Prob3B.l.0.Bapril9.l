%{
int a = 0, b = 0,c = 0,d = 0;
%}

letter		[a-zA-Z_]
letters		[a-zA-Z_]*
identifier	{letter}({letter}|{digit})*
digit           [0-9]
digits          [0-9]*
real            [0-9]*[.][0-9]*
noodles		(noodles)
eol		\n
word		[^ \t\n]
st		[ ]*[\t]*[ ]*
fa		(Favorite)
box		({letters}|{digits})*

%%
{fa}{st}*{letters}*{st}*{letters}*{st}*{letters}* 	{a = 1;}

{letters}*{st}*{fa}{st}*{letters}*{st}*{letters}*	{b = 1;}

{letters}*{st}*{letters}*{st}*{fa}{st}*{letters}*	{c = 1;}

{letters}*{st}*{letters}*{st}*{letters}*{st}*{fa}	{d = 1;}


{noodles}{st}*{box}*{st}*{box}*{st}*{box}*              {if(a == 1) ECHO;}

{box}*{st}*{noodles}{st}*{box}*{st}*{box}*              {if(b == 1) ECHO;}

{box}*{st}*{box}*{st}*{noodles}{st}*{box}*              {if(c == 1) ECHO;}

{box}*{st}*{box}*{st}*{box}*{st}*{noodles}              {if(d == 1) ECHO;}

.							{}

%%
int main(int argc, char *argv[]) {
	yylex();
 	return(0);
}

