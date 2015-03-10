%{
%}

%x COMMENT
word            [A-Z]
word2           [A-Z]+[a-z]*
IP2             ^(([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\.){3}([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])$
name            [a-z]+"@"[a-z]+(\.[a-z]+)+
name2           [0-9]*[a-z]+"@"(.+)+(\.[a-z]+)+

%%

"//"                    {BEGIN COMMENT;printf("--");}
<COMMENT>.              {ECHO;}
<COMMENT>\n             {BEGIN INITIAL;printf("--\n");}

{word}                  {ECHO; printf(" is a word\n");}
{word2}                 {ECHO; printf(" is a word\n");}
{IP2}                   {ECHO; printf(" is an IP address\n");}
{name}                  {ECHO; printf(" is an email address\n");}
{name2}                 {ECHO; printf(" is an email address\n");}
.|\n                    {/* do nothing */}

%%
int main(void) {
        yylex();
        return(0);
}
