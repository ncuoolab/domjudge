%x comment

letter [a-zA-z]
Adress [a-zA-Z0-9]+
adress [a-zA-Z0-9.]+
exc    [^\t\n ]+
range  [0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5]
number [0-9]
captal [A-Z]
Word   ^{captal}{letter}*
IP     {range}\.{range}\.{range}\.{range}$
Email  ^{exc}"@"{Adress}"."{adress}
%%
"//" {BEGIN comment;}
<comment>[a-zA-Z ]+ {printf("--%s--\n",yytext);}
<comment>\n         {BEGIN INITIAL;}
{Word}   {ECHO; printf(" is a word\n");}
{IP}     {ECHO; printf(" is an IP address\n");}
{Email}  {ECHO; printf(" is an email address\n");}
.|\n          ;
%%

int main()
{
yylex();
return(0);
}
