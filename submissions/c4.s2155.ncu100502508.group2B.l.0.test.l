strword		Word
strAddress	IP[ ]Address
stremail	Email[ ]Address
captal		[A-Z]
letter		[a-z]
Word		^{captal}[A-Za-z]*$
Word2		^[ \t]{captal}[A-Za-z]*$


dot             [.]
legal1          [2][5][0-5]
legal2          [2][0-4][0-9]
legal3          [1][0-9][0-9]
legal4          [1-9][0-9]
legal5          [0-9]
legalAll        ({legal1}|{legal2}|{legal3}|{legal4}|{legal5})
IPNOT           ({legalAll}{dot}){3}{legalAll}{dot}
IPNOT2          [^ \t\n]+({legalAll}{dot}){3}{legalAll}{dot}
IP              ({legalAll}{dot}){3}{legalAll}$

digit		[0-9]
legalstr	({captal}|{letter}|{digit})+
email2       	^[ \t][^ \t\n]+@{legalstr}({dot}{legalstr}){1,}$
email		^[^ \t\n]+@{legalstr}({dot}{legalstr}){1,}$	


%% 
"//" 	; 
{strword} {printf("--");ECHO;printf("--\n");}
{strAddress} {printf("--");ECHO;printf("--\n");}
{stremail} {printf("--");ECHO;printf("--\n");}

{Word} {ECHO;printf(" is a word\n");}
{Word2} {printf("%s is a word\n",yytext+1);}

{IP}            {ECHO;printf(" is an IP address\n");}
{IPNOT}         ;
{IPNOT2}        ;
{email}		{printf("%s is an email address\n",yytext);}
{email2}        {printf("%s is an email address\n",yytext+1);}

\n	;
.	;
%%
int main(int argc, char *argv[]) {
        yylex();
        return(0);
}

