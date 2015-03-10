word [A-Z][a-z|A-Z]*
alph [a-z|A-Z]+
ida 25[0-5]
idb 2[0-4][0-9]
idc 1[0-9][0-9]
idd [1-9][0-9]
ide [0-9]
id {ida}|{idb}|{idc}|{idd}|{ide}
email1 [^ \t\n]+"@"{alph}"."{alph}
email2 [^ \t\n]+"@"{alph}"."{alph}"."{alph}"."{alph}
title "//"[a-z|A-Z| ]+$

%%
{title} {printf("--%s--\n",yytext+2);}
{word} {ECHO;printf(" is a word\n");}
{id}"."{id}"."{id}"."{id}$ {ECHO;printf(" is an IP address\n");}
{email1} {ECHO;printf(" is an email address\n");}
{email2} {ECHO;printf(" is an email address\n");}
.|\n {}
%%

int main(int argc, char *argv[]) {
        yylex();
        return(0);
}

