%x TITLE
greatword [A-Z]
chars [A-Za-z]
word ^{greatword}+{chars}*
ipnumber [2][5][0-5]|[2][0-4][0-9]|[0-1]?[0-9]?[0-9]
ipaddress ^{ipnumber}"."{ipnumber}"."{ipnumber}"."{ipnumber}$
emailword [A-za-z0-9_]
emaildot ['.']{emailword}+
emailaddress ^{emailword}+"@"{emailword}+{emaildot}+$
%%
"//" {BEGIN TITLE;printf("--");}
<TITLE>. {ECHO;}
<TITLE>\n {printf("--\n");BEGIN INITIAL;}
{word} {ECHO;printf(" is a word\n");}
{ipaddress} {ECHO;printf(" is an IP address\n");}
{emailaddress} {ECHO;printf(" is an email address\n");}
.|\t|\n|" " {}
%%
int main() {
	yylex();
	return 0;
}
