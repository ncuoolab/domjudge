%x COMMENT
Capital [A-Z]
letter  [a-zA-Z]
word    {Capital}{letter}*
word2   {Capital}{letter}*[ ]{Capital}{letter}* 
comment [Word]|[IP][ ][Address]|[Email][ ][Address]
a       [0-9]
b       [1-9][0-9]
c       [1][0-9][0-9]
d       [2][0-5][0-5]
point   [.]
ip      ({a}|{b}|{c}|{d}){point}({a}|{b}|{c}|{d}){point}({a}|{b}|{c}|{d}){point}({a}|{b}|{c}|{d})$
temp    {point}({letter}|{a})+
email   ^({letter}|{a})+[@]({letter}|{a})+{temp}+
email2  ^[ |\t]({letter}|{a})+[@]({letter}|{a})+{temp}+ 
%%
"//"               {BEGIN COMMENT;}
<COMMENT>{word}|{word2}    {printf("--");ECHO;printf("--\n");}
<COMMENT>\n        {BEGIN INITIAL;}
{word}             {ECHO;printf(" is a word\n");}
{ip}               {ECHO;printf(" is an IP address\n");}
{email2}           {printf("%s", yytext+1);printf(" is an email address\n");}
{email}            {ECHO;printf(" is an email address\n");}
.|\n               ;
%%
int main(int argc, char *argv[]){
     yylex();
     return(0);
}
