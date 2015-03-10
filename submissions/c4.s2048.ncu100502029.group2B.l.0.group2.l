Word		^[A-Z][a-zA-Z]*[ ]*$
range           [0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5]
IPaddress       ^{range}\.{range}\.{range}\.{range}[ ]*$
Email		^[^ \t\n]+@[^ \t\n]+"."[^ \t\n]+[ ]*$
%x COMMENT
%%
"//"            {BEGIN COMMENT;printf("--");}
<COMMENT>.      {ECHO;}
<COMMENT>"\n"   {printf("--\n");BEGIN INITIAL;}
{Email}		{ECHO;printf(" is an email address\n");}
{Word}		{ECHO;printf(" is a word\n");}
{IPaddress}     {ECHO;printf(" is an IP address\n");}
.|\n            ;
%%
int main(int argc, char *argv[]) {
        yylex();
        return(0);
}

