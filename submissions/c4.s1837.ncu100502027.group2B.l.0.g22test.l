email [^" ""\n""\t"]+[@][a-zA-z0-9]+
%%

{email} {ECHO;printf(" is an email address\n");}
.|\n    ;

%%
int main(int argc, char *argv[]){
  yylex();
  return(0);
}
