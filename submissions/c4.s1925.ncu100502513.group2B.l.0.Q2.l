dot    "."
IP1    [0-9]
IP2    [1-9][0-9]
IP3    1[0-9][0-9]
IP4    2[0-4][0-9]
IP5    25[0-5]
IPall  ({IP1}|{IP2}|{IP3}|{IP4}|{IP5})
IP     {IPall}{dot}{IPall}{dot}{IPall}{dot}{IPall}$
wordmain   "/""/""W""o""r""d"
IPmain     "/""/""I""P"" ""A""d""d""r""e""s""s"
Emilmain   "/""/""E""m""a""i""l"" ""A""d""d""r""e""s""s"
bletter   [A-Z]
sletter    [a-z]
word      {bletter}+({bletter}|{sletter})*
digit     [0-9]
emaildot  ({bletter}|{sletter}|{digit})*(\.)
email     ({digit}|{bletter}|{sletter})+(\@){emaildot}+({bletter}|{sletter}|{digit})+
woringma  ({digit}|{bletter}|{sletter})+(" "|"\t"|"\n")({digit}|{bletter}|{sletter})+(\@){emaildot}+({bletter}|{sletter}|{digit})+
%%
{IP}        {ECHO;   printf(" is an IP address\n");}
{wordmain}  {printf("--Word--\n");}
{IPmain}    {printf("--IP Address--\n");}
{Emilmain}  {printf("--Email Address--\n");}
{word}      {ECHO;   printf(" is a word\n");}
{email}     {ECHO;   printf(" is an email address\n");}
{woringma}   ;
.|\n        ;
%%

int main(int argc, char *argv[]) {
        yylex();
        return(0);
}

