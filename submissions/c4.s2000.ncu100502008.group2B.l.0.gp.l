word1 ^[A-Z][a-z|A-Z]*
word2 {spe}[A-Z][a-z|A-Z]*
spe [ |\t]
alph [a-z|A-Z|0-9]+
dot "."
ida 25[0-5]
idb 2[0-4][0-9]
idc 1[0-9][0-9]
idd [1-9][0-9]
ide [0-9]
id {ida}|{idb}|{idc}|{idd}|{ide}
idadd1 ^{id}"."{id}"."{id}"."{id}$
idadd2 {spe}{id}"."{id}"."{id}"."{id}$ 
s {dot}{alph}
email1 ^[^ \t\n]+"@"{alph}{s}+$
title "//"[a-z|A-Z| ]+

%%

{title} {printf("--%s--\n",2+yytext);}
{word1} {ECHO;printf(" is a word\n");}
{word2} {printf("%s is a word\n",yytext+1);}
{idadd1} {ECHO;printf(" is an IP address\n");}
{idadd2} {printf("%s is an IP address\n",yytext+1);}
{email1} {ECHO;printf(" is an email address\n");}
.|\n {}

%%


int main(int argc, char *argv[]) {
        yylex();
        return(0);
}

