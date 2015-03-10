word [A-Za-z]
ip1 [0-9]
ip2 [1-9][0-9]
ip3 1[0-9][0-9]
ip4 2[0-5][0-5]
ip_f {ip1}|{ip2}|{ip3}|{ip4}
ip_iden {ip_f}\.{ip_f}\.{ip_f}\.{ip_f}$
word_iden [A-Z]{word}{0,257}$
email_iden ^[^ \,\t\n]+"@"([^ \,\t\n]+\.)+[^ \,\t\n]+$

%x comment
%%
"//"		{BEGIN comment;}{printf("--");}
<comment>.	{ECHO;}
<comment>\n	printf("--\n");{BEGIN INITIAL;}
{word_iden}     ECHO; printf(" is a word\n");
{ip_iden}	ECHO; printf(" is an IP address\n");
{email_iden}	ECHO; printf(" is an email address\n");
.|\n		;
%%
int main(){
	yylex();
	return 0;

}
