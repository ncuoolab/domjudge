%x COMMENT
Word			^[A-Z][a-zA-Z]*$
string 			[^ \t\n]+
digit			([0-9]|[1-9][0-9]|2[0-4][0-9]|25[0-5]|1[0-9][0-9])	
IP			^{digit}"."{digit}"."{digit}"."{digit}$
Email			^{string}"@"{string}("."{string})+$
KeyWord1		"Word"
KeyWord2		"IP Address"
KeyWord3		"Email Address"	
eol			.
%%
{KeyWord1}		{printf("--Word--");}
{KeyWord2}		{printf("--IP Address--");}
{KeyWord3}		{printf("--Email Address--");}


{Word}			{ECHO;printf(" is a word");}
{IP}			{ECHO;printf(" is an IP address");}
{Email}			{ECHO;printf(" is an email address");}
.			;
%%
int main(int argc, char *argv[]) {
        yylex();
        return(0);
}

