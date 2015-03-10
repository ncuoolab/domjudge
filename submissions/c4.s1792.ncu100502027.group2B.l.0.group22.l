word [a-zA-Z]+
digit [0-9]|[0-9][0-9]|[1][0-9][0-9]|[2][0-4][0-9]|(25)[0-5]
adress (digit)"\."(digit)"\."(digit)"\."(digit)
email [.]+"@"[.]
%%
"//Word" {printf("--Word--");}
"//IP Address" {printf("--IP Address--");}
"//Email Address" {printf("--Email Address--");}
{word}  {ECHO;printf(" is a word\n");}
[adress] {ECHO;printf(" is an IP address\n");}
.|\n    ;

%%
int main(int argc, char *argv[]){
  yylex();
  return(0);
}