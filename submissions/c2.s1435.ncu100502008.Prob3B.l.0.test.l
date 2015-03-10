
id [a-z|A-Z]+
space [ ]+

%%

{id}{space}{id}{space}"noodles"{space}{id} {ECHO;printf("\n");}
{id}{space}{id}{space}{id}{space}{id} {/*fuck*/}
.|\n {/*fuck2*/}
%%

int main(int argc,char *argv[]){
  yylex();
  return 0;
}

