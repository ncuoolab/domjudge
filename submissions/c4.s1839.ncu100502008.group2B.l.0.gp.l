word [A-Z][a-z|A-Z]*
alph [a-z|A-Z|0-9]+
dot "."
ida 25[0-5]
idb 2[0-4][0-9]
idc 1[0-9][0-9]
idd [1-9][0-9]
ide [0-9]
id {ida}|{idb}|{idc}|{idd}|{ide}
idadd {id}"."{id}"."{id}"."{id}$ 
s {dot}{alph}
email ^[^ \t\n]+"@"{alph}{s}+$
title "//"[a-z|A-Z| ]+$

%%
{title} {printf("--%s--\n",yytext+2);}
{word} {ECHO;printf(" is a word\n");}
{idadd} {ECHO;printf(" is an IP address\n");}
{email} {ECHO;printf(" is an email address\n");}
.|\n {}
%%

int main(int argc, char *argv[]) {
        yylex();
        return(0);
}

