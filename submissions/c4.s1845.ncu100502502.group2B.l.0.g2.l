eol	\n
digit   [0-9]{1}
digit2  [0-9][0-9]
digit3  1[0-9][0-9]|2[0-4][0-9]|25[0-5]
ip      {digit}|{digit2}|{digit3}
ip4     ^{ip}{point}{ip}{point}{ip}{point}{ip}$
point   "."
Word	^[A-Z][a-zA-Z]*$
left	[^ \t\n]+
any	[a-zA-Z0-9]
right	{any}+{point}{any}+({point}{any}+)*
EAd	^{left}@{right}$
%x	COMMENT
%%
"//"	{BEGIN COMMENT;}
<COMMENT>[^\n]*	{printf("--"); ECHO; printf("--\n");}
<COMMENT>\n	{BEGIN INITIAL;}
{ip4}	{ECHO; printf(" is an IP address\n");}
{Word}	{ECHO; printf(" is a word\n");}
{EAd}	{ECHO; printf(" is an email address\n");}
{eol}	{}
.	{}	
%%
int main(void){
	yylex();
	return(0);
}
