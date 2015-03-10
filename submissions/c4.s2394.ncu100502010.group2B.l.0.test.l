sp [ |\t]
alp [a-z|A-Z|0-9]+
dot "."
id1 25[0-5]
id2 2[0-4][0-9]
id3 1[0-9][0-9]
id4 [1-9][0-9]
id5 [0-9]
w1 ^[A-Z][a-z|A-Z]*
w2 {sp}[A-Z][a-z|A-Z]*
id {id1}|{id2}|{id3}|{id4}|{id5}
idd1 ^{id}"."{id}"."{id}"."{id}$
idd2 {sp}{id}"."{id}"."{id}"."{id}$
s {dot}{alp}
email1 ^[^  \t\n]+"@"{alp}{s}+$
title "//"[a-z|A-Z| ]+
%%
{title} {printf("--%s--\n",2+yytext);}
{w1} {ECHO;printf(" is a word\n");}
{w2} {printf("%s is a word\n",yytext+1);}
{idd1} {ECHO;printf(" is an IP address\n");}
{idd2} {printf("%s is an IP address\n",yytext+1);}
{email1} {ECHO;printf(" is an email address\n");}
.|\n {}


%%
int main(int argc, char *argv[]) {
	yylex();
        return(0);
}

