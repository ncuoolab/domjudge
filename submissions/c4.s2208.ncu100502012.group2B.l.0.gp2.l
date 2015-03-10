%x COMMENT
Word			^[A-Z][a-zA-Z]*$
string 			[^ \t\n@]+
digit			([0-9]|[1-9][0-9]|2[0-4][0-9]|25[0-5]|1[0-9][0-9])	
IP			^{digit}"."{digit}"."{digit}"."{digit}$
Email			^{string}"@"{string}("."{string})+$
KeyWord1		"Word"
KeyWord2		"IP Address"
KeyWord3		"Email Address"	
%%
{KeyWord1}		{printf("--Word--\n");}
{KeyWord2}		{printf("--IP Address--\n");}
{KeyWord3}		{printf("--Email Address--\n");}
{Word}			{ECHO;printf(" is a word\n");}
{IP}			{ECHO;printf(" is an IP address\n");}
{Email}			{ECHO;printf(" is an email address\n");}
.|\n			;
%%
int main(int argc, char *argv[]) {
        yylex();
        return(0);
}

