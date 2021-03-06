%x COMWORD
email ^[^" ""\n""\t"]+[@][a-zA-z0-9]+([.][a-zA-z0-9]+)+$
word ^[A-Z][a-zA-Z]*$
digit [0-9]|[1-9][0-9]|[1][0-9][0-9]|[2][0-4][0-9]|(25)[0-5]
adress ^{digit}"\."{digit}"\."{digit}"\."{digit}$

%%
"//Word" {printf("--Word--\n");}
"//IP Address" {printf("--IP Address--\n");}
"//Email Address" {printf("--Email Address--\n");}
{word}  {ECHO;printf(" is a word\n");}
{adress} {ECHO;printf(" is an IP address\n");}
{email} {ECHO;printf(" is an email address\n");}
.|\n    ;

%%
int main(int argc, char *argv[]){
  yylex();
  return(0);
}
