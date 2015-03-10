strword		Word
strAddress	IP[ ]Address
stremail	Email[ ]Address
captal	[A-Z]
letter	[a-z]
Word	{captal}{letter}*

dot             [.]
legal1          [2][5][0-5]
legal2          [2][0-4][0-9]
legal3          [1][0-9][0-9]
legal4          [1-9][0-9]
legal5          [0-9]
legalAll        ({legal1}|{legal2}|{legal3}|{legal4}|{legal5})
IPNOT           ({legalAll}{dot}){3}{legalAll}{dot}
IP              ^({legalAll}{dot}){3}{legalAll}$

digit		[0-9]
legalstr	({captal}|{letter}|{digit})+
email		{legalstr}@{legalstr}({dot}{legalstr}){1,}	


%% 
"//" 	; 
{strword} {printf("--");ECHO;printf("--\n");}
{strAddress} {printf("--");ECHO;printf("--\n");}
{stremail} {printf("--");ECHO;printf("--\n");}


{Word} {ECHO;printf(" is a word\n");}

{IP}            {ECHO;printf(" is an IP address\n");}
{IPNOT}         ;
{email}		{ECHO;printf(" is an email address\n");}
\n	;
.	;
%%
int main(int argc, char *argv[]) {
        yylex();
        return(0);
}

