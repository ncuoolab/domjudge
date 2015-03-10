%{

%}

%x COMMENT

word    [A-Z][A-Za-z]*
ip		(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$
email	^[^ \t\n]+@[a-zA-Z0-9]+(\.[a-zA-Z0-9]+)+

%%

{word}	{ printf("%s is a word\n", yytext); }
{ip}	{ printf("%s is an IP address\n", yytext); }
{email}	{ printf("%s is an email address\n", yytext); }
"//"		{ BEGIN COMMENT; }
.|\n	{ }

<COMMENT>.+	{ printf("--%s--", yytext); }
<COMMENT>\n	{ ECHO; BEGIN INITIAL; }

%%
int main(int argc, char *argv[]) {
    yylex();
    return(0);
}