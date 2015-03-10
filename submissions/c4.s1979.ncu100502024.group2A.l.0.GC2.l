%{
int counter = 0;int i;
%}
character  [^{|^}]
else	   [.| ]+
space	[ ]
left	[{]
right	[}]
word	({character}|{space})*{left}
%%
{word}	{printf("%d",counter);counter++;printf("%d",counter);ECHO;}
{left}	{printf("%d",counter);counter++;ECHO;}
{right}	{counter--;printf("%d",counter);ECHO;}
{else}	{printf("%d",counter);ECHO;}

%%

int main()
{
	yylex();
	return(0);
}
