%x comment
id        [0-9]
id1       [1-9][0-9]
id4       "1"[0-9][0-9]
id2       "2"[0-4][0-9]
id3       "25"[0-5]
ip        {id4}|{id1}|{id2}|{id3}|{id}
word      [A-Z][A-Za-z]*$
email2    ^[^ \t\n]+"@"[a-zA-Z][a-zA-Z0-9]*"."[a-zA-Z]+["."[a-zA-Z]+]*$
%%
"//"			     {BEGIN comment;}
<comment>[ a-zA-Z0-9]+       {printf("--%s--",yytext);}
<comment>\n                  {ECHO;BEGIN INITIAL;}
{word}                       {ECHO;printf(" is a word\n");}
{ip}"."{ip}"."{ip}"."{ip}$   {ECHO;printf(" is an IP address\n");}
{email2}                     {ECHO;printf(" is an email address\n");}
.|\n                         ;
%%
int main(int argc ,char*argv[]){
        yylex();
        return(0);
}
