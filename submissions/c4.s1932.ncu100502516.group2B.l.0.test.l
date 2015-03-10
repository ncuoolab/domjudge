String  [a-zA-z0-9]
Digit   [0-9]
Word    [A-Z]+[A-Za-z]*
IPBit   ([0-9]|[0-9]{2}|[0-1][0-9]{2}|("2")[0-4][0-9]|("25")[0-5])(".")
IPEnd   [0-9]|[0-9]{2}|[0-1][0-9]{2}|("2")[0-4][0-9]|("25")[0-5]
IPAddress       {IPBit}{3}{IPEnd}
InvalidIP       {IPBit}{3}{Digit}{4,}
ELeft   [^\n\t ]+
ERight  {String}+(("."){String}+)+
EmailAddress    {ELeft}("@"){ERight}
InvalidEmail    {Digit}+("@"){ERight}
%%
("//Word")      {printf("--Word--\n");}
("//IP Address")      {printf("--IP Address--\n");}
("//Email Address")      {printf("--Email Address--\n");}
{InvalidEmail}  {}
{EmailAddress}  {ECHO; printf(" is an email address\n");}
{InvalidIP}     {}
{IPAddress}     {ECHO; printf(" is an IP address\n");}
{Word}  {ECHO; printf(" is a word\n");}
.|\n    {}
%%
int main(int argc, char *argv[])
{
        yylex();
        return(0);
}