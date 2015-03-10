uletter   [A-Z]
dletter   [a-z]
letter    [a-zA-Z]
interger  [0-9]
dot       [.]
at        [@]
id1       [01][0-9][0-9]
id2       [2][0-4][0-9]
id3       [2][5][0-5]
id4       [0-9]
id5       [0-9][0-9]
digit     {id1}|{id2}|{id3}|{id4}|{id5}
space     [' ']
sword     Word
sip       IP
semail    Email
word      ^{space}*{uletter}({uletter}|{dletter})*{space}*$
ip        {digit}{dot}{digit}{dot}{digit}{dot}{digit}$
string    ({letter}|{interger})+
dstring   {dot}{string}
email     ^[^ ,\t\n]+{at}{string}{dstring}+$
%%
{sword}           {printf("--Word--\n");}
{sip}             {printf("--IP Address--\n");}
{semail}          {printf("--Email Address--\n");}
{word}            {ECHO;printf(" is a word\n");}
{ip}              {ECHO;printf(" is an IP address\n");}
{email}           {ECHO;printf(" is an email address\n");}
.|\n              ;
%%
int main(int argc, char *argv[]){
    yylex();
    return(0);
}
