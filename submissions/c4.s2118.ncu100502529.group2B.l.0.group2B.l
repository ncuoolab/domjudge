capital       [A-Z]
letter        [A-Za-z]
word          {capital}{letter}*
digit         [0-9]
digit1        [1-9][0-9]
digit2        [1][0-9][0-9]
digit3        [2][0-4][0-9]
digit4        [2][5][0-5]
range         {digit4}|{digit3}|{digit2}|{digit1}|{digit}
space         [ \t]*
ip            ^{range}[.]{range}[.]{range}[.]{range}$
left          [^ \t\n]+
right         {left}[.]{left}([.]{left})*         
email         ^{left}[@]{right}$
%x            COM
%%
"//"          { printf("--"); BEGIN COM; }
<COM>.        { ECHO; }
<COM>\n       { printf("--"); ECHO; BEGIN INITIAL; }
{space}       ;
{word}        { ECHO; printf(" is a word\n"); }
{ip}          { ECHO; printf(" is an IP address\n"); }
{email}       { ECHO; printf(" is an email address\n"); }
.|\n          ;
%%
int main( int argc, char *argv[] )
{
  yylex();
  return(0);
}
